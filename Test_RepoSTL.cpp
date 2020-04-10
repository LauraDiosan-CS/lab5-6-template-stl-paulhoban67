#include "Test_RepoSTL.h"
#include <cassert>

void Test_RepoSTL_Products::test_repo()
{
	this->repo_products.set_filename("RepoSTL_Test");
	this->repo_products.load_to_file();
	int n = this->repo_products.show().size();
	for (int i = 0; i < n; i++) 
	{
		assert(this->repo_products.show()[i] == this->products_test[i]);
	}
}

Test_RepoSTL_Products::Test_RepoSTL_Products()
{
	char* name1 = new char[strlen("Croissant") + 1];
	strcpy_s(name1, strlen("Croissant") + 1, "Croissant");
	char* code1 = new char[strlen("HH77") + 1];
	strcpy_s(code1, strlen("HH77") + 1, "HH77");
	Products p1(1, code1, name1, 2.3);

	char* name2 = new char[strlen("Banana") + 1];
	strcpy_s(name2, strlen("Banana") + 1, "Banana");
	char* code2 = new char[strlen("FF44") + 1];
	strcpy_s(code2, strlen("FF44") + 1, "FF44");
	Products p2(2, code2, name2, 2.9);

	char* name3 = new char[strlen("Milka") + 1];
	strcpy_s(name3, strlen("Milka") + 1, "Milka");
	char* code3 = new char[strlen("OO99") + 1];
	strcpy_s(code3, strlen("OO99") + 1, "OO99");
	Products p3(3, code3, name3, 2.0);

	this->products_test.push_back(p1);
	this->products_test.push_back(p2);
	this->products_test.push_back(p3);

}

void Test_RepoSTL_Products::test_main()
{
	this->test_repo();
}
