#include "UI.h"
#include "RepoSTL.h"
#include "Tests.h"
#include "Test_RepoSTL.h"
#include "Tets_Repo.h"
#include "Test_Service.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	Test_RepoSTL_Products t;
	t.test_main();

	Test_Repo_Products t1;
	t1.test_main1();

	Test_Service s1;
	s1.test_main2();

	test_products();
	test_money();

	RepoSTL<Products> repo_product("Products.txt");
	RepoSTL<Money> repo_monede("Money.txt");
	Service s(repo_product, repo_monede);

	UI ui(s);
	ui.run();
	return 0;
}