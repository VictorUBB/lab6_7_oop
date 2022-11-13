#pragma once
#include "Service.h"
class ui
{private:
	Service& serv;
public:
	ui(Service& serv) :serv{ serv } {};
	ui(const ui& cop) = delete;
	void print_menu();
	void add_menu();
	void find_menu();
	void delete_menu();
	void modify_menu();
	void show_all();
	void filter_menu();
	void sort_ui();
	void run();
	void cos_menu();
	void add_2_cos();
	void show_cos();
	void test_all();
	void addRandomToCos();
	void Cos_ui();
	void fis_ui();
	void undo_ui();
};

