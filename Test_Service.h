#pragma once
#include "Repo.h"
#include "RepoSTL.h"
#include "Money.h"
#include "Products.h"
#include "Service.h"
#include <vector>
#include <map>
class Test_Service
{
private:
	Service service;

	void add_product();
	void update_product();
	void delete_product();
	void get_product();

	void get_sum_tonomate();
	void rest();
	void delete_rest();
	void get_sum_coin();
	void verify_sum();
	void how_much();

public:
	Test_Service();
	void test_main2();
};