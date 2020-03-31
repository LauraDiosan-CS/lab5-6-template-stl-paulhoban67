#include "Tests.h"
#include "UI.h"
#include <iostream>
using namespace std;

int main()
{
	test_products();
	test_repoST_products();
	test_service_products();
	RepoSTL r = RepoSTL("Products.in", "Products.out");
	Service s = Service(r);
	UI ui = UI(s);
	ui.run();
	return 0;
}