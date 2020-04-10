#pragma once
#include "RepoSTL.h"
#include "Products.h"
#include <vector>
class Test_RepoSTL_Products 
{
private:
	RepoSTL<Products> repo_products;
	vector<Products> products_test;
	void test_repo();
public:
	Test_RepoSTL_Products();
	void test_main();
};