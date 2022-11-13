#pragma once
#include "Film.h"
#define CAPACITATE 2
//typedef Film ElemT;
template <typename ElemT>
class Iterator;

template <typename ElemT>
class vectorDinamic
{
private:
	int capacitate;
	int stored;
	ElemT* elems;

public:
	vectorDinamic();
	vectorDinamic(const vectorDinamic& ot);
	~vectorDinamic();
	vectorDinamic& operator=(const vectorDinamic& ot);
	vectorDinamic(vectorDinamic&& ot);
	vectorDinamic& operator=( vectorDinamic&& ot);
	void add(const ElemT& elem);
	ElemT& get(int poz) const;
	void set(ElemT& elem, int poz);
	void redim();
	int size();
	friend class Iterator<ElemT>;
	Iterator<ElemT> begin();
	Iterator<ElemT> end();
	void erase(int poz) ;

};

template <typename ElemT>
vectorDinamic<ElemT>::vectorDinamic() :elems{ new ElemT[CAPACITATE] }, capacitate{ CAPACITATE }, stored{ 0 }{};

template <typename ElemT>
vectorDinamic<ElemT>::vectorDinamic(const vectorDinamic& ot)
{
	elems = new ElemT[ot.capacitate];
	for (int i = 0;i < ot.stored;i++) {
		elems[i] = ot.elems[i];
	}
	stored = ot.stored;
	capacitate = ot.capacitate;
}

template <typename ElemT>
vectorDinamic<ElemT>::~vectorDinamic()
{
	delete[] elems;
}

template <typename ElemT>
vectorDinamic<ElemT>& vectorDinamic<ElemT>::operator=(const vectorDinamic& ot)
{
	if (this == &ot) {
		return *this;
	}
	delete[] elems;
	elems = new ElemT[ot.capacitate];
	for (int i = 0;i < ot.stored;i++) {
		elems[i] = ot.elems[i];
	}
	stored = ot.stored;
	capacitate = ot.capacitate;

}

template <typename ElemT>
vectorDinamic<ElemT>::vectorDinamic(vectorDinamic&& ot)
{
	elems = ot.elems;
	stored = ot.stored;
	capacitate = ot.capacitate;

	ot.elems = nullptr;
	ot.stored = 0;
	ot.capacitate = 0;
}

template <typename ElemT>
vectorDinamic<ElemT>& vectorDinamic<ElemT>::operator=(vectorDinamic&& ot)
{
	if (this == &ot) {
		return *this;
	}
	delete[] elems;
	elems = ot.elems;
	stored = ot.stored;
	capacitate = ot.capacitate;

	ot.elems = nullptr;
	ot.stored = 0;
	ot.capacitate = 0;
	return *this;
}

template <typename ElemT>
void vectorDinamic<ElemT>::add(const ElemT& elem)
{
	redim();
	elems[stored] = elem;
	stored++;

}

template <typename ElemT>
ElemT& vectorDinamic<ElemT>::get(int poz) const
{
	return elems[poz];
}

template <typename ElemT>
void vectorDinamic<ElemT>::set(ElemT& elem, int poz)
{

	elems[poz] = elem;
}

template<typename ElemT>
void vectorDinamic<ElemT>::erase(int poz)
{
	ElemT elem = get(poz);
	//delete (elem);
	stored--;
}

template <typename ElemT>
void vectorDinamic<ElemT>::redim()
{
	if (stored < capacitate)
		return;
	else {
		capacitate *= 2;
		ElemT* aux = new ElemT[capacitate];
		for (int i = 0;i < stored;i++) {
			aux[i] = elems[i];
		}
		delete[] elems;
		elems = aux;
	}
}

template <typename ElemT>
int vectorDinamic<ElemT>::size()
{
	return stored;
}

template <typename ElemT>
Iterator<ElemT> vectorDinamic<ElemT>::begin()
{
	return Iterator<ElemT>(*this,0);
}

template <typename ElemT>
Iterator<ElemT> vectorDinamic<ElemT>::end()
{
	return Iterator<ElemT>(*this, stored);
}


template <typename ElemT>
class Iterator {
private:
	const vectorDinamic<ElemT>& v;
	int poz;
public:
	Iterator(const vectorDinamic<ElemT>& v) noexcept;
	Iterator(const vectorDinamic<ElemT>& v, int poz)noexcept;
	bool valid();
	ElemT& element() const noexcept;
	void urmator() noexcept;
	Iterator& operator++();
	bool operator==(const Iterator<ElemT>& ot)noexcept;
	bool operator!=(const Iterator<ElemT>& ot)noexcept;

};

template <typename ElemT>
Iterator<ElemT>::Iterator(const vectorDinamic<ElemT>& v) noexcept :v{ v } {}

template <typename ElemT>
Iterator<ElemT>::Iterator(const vectorDinamic<ElemT>& v, int poz) noexcept :v{ v }, poz{ poz }{}

template <typename ElemT>
bool Iterator<ElemT>::valid()
{
	return poz < v.stored;
}

template <typename ElemT>
ElemT& Iterator<ElemT>::element() const noexcept
{
	return v.elems[poz];
}

template <typename ElemT>
void Iterator<ElemT>::urmator() noexcept
{
	poz++;
}

template <typename ElemT>
Iterator<ElemT>& Iterator<ElemT>::operator++()
{
	urmator();
	return *this;
}

template <typename ElemT>
bool Iterator<ElemT>::operator==(const Iterator<ElemT>& ot) noexcept
{
	return poz == ot.poz;
}

template <typename ElemT>
bool Iterator<ElemT>::operator!=(const Iterator<ElemT>& ot) noexcept
{
	return !(*this == ot);
}
