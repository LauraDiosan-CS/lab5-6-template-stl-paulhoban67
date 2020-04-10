#pragma once
#include "Repo.h"
#include "Products.h"
#include <vector>
class Test_Repo_Products
{
private:
	Repo <Products> repo_products1;
	vector<Products> products_test1;

	void test_add();
	void test_delete();
	void test_update();
	void test_show();

public:
	Test_Repo_Products();
	void test_main1();
};