#pragma once
#include "RepoSTL.h"
#include "Products.h"
#include "Money.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <map>

class Service {
private:
	RepoSTL<Products> repo_product;
	RepoSTL<Money> repo_money;
	map<int, float> money_added;
public:
	Service() 
	{

	};
	Service(const RepoSTL<Products>& ptoducts, const RepoSTL<Money>& money);
	Service(const Service& s);
	~Service()
	{
		money_added.clear();
	};

	void add_product(const char* code, const char* name, float price);
	vector<Products> show_product();
	void update_product(int id, const char* new_code, const char* new_name, float new_price);
	void delete_product(int id);
	float get_product_price_by_code(const char* code);
	Products get_product(int id);

	void add_money(int nr, float coin);
	float get_sum_coin(int nr, float coin);
	vector<Money> show_coin();
	void clear_money();
	void update_money(int nr, float coin);

	int verify_sum(const char* code, int nr, float coin);
	float how_much(const char* code, int nr, float coin);
	int rest(float sum, float price);
	float sum_tonomate();
	int delete_money_tonomate(float rest);
	void delete_money_rest();

	int same_float(float f1, float f2);
};


