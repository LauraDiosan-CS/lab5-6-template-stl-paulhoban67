#include "Service.h"
#include <ctime>
#include <time.h>

// Init Service with Repo
Service::Service(const RepoSTL<Products>& products, const RepoSTL<Money>& money)
{
	this->repo_product = products;
	this->repo_money = money;
}

// Init Service
Service::Service(const Service& s)
{
	this->repo_product = s.repo_product;
	this->repo_money = s.repo_money;
	this->money_added = s.money_added;
}

// Add a product
void Service::add_product(const char* code, const char* name, float price)
{
	int id = repo_product.get_size() + 1;
	this->repo_product.add_element(Products(id, code, name, price));
}

// Show all products
vector<Products> Service::show_product()
{
	return this->repo_product.show();
}

//	Get a product by id
Products Service::get_product(int id)
{
	return this->repo_product.get_element(id);
}

//	Update a product by id
void Service::update_product(int id, const char* new_code, const char* new_name, float new_price)
{
	vector<Products> products = this->repo_product.show();
	Products new_product(id, new_code, new_name, new_price);
	for (int i = 0; i < this->repo_product.get_size(); i++)
	{
		if (products[i].get_id()==id)
		{
			Products old_product(id, products[i].get_code(), products[i].get_name(), products[i].get_price());
			this->repo_product.update_element(old_product, new_product);
			return;
		}
	}
}

//	Delete a product by id
void Service::delete_product(int id)
{
	for (int i = 0; i < this->repo_product.get_size(); i ++)
	{
		if (this->repo_product.show()[i].get_id() == id)
		{
			Products product_to_delete(this->repo_product.show()[i].get_id(), this->repo_product.show()[i].get_code(), this->repo_product.show()[i].get_name(), this->repo_product.show()[i].get_price());
			this->repo_product.del_element(product_to_delete);
			return;
		}
	}
}

// Get a price of a product by code
float Service::get_product_price_by_code(const char* code)
{
	for (int i = 0; i < this->repo_product.show().size(); i++)
		if (strcmp(this->repo_product.show()[i].get_code(),code) == 0)
			return this->repo_product.show()[i].get_price();
	return 0;
}

// Add money
void Service::add_money(int nr, float coin)
{
	this->repo_money.add_element(Money(nr, coin));
}

// Get sum om money added
float Service::get_sum_coin(int nr, float coin)
{
	return nr * coin;
}

// Show all money
vector<Money> Service::show_coin()
{
	return this->repo_money.show();
}

// Clear all money added;
void Service::clear_money()
{
	money_added.clear();
}

void Service::update_money(int nr, float coin)
{
	vector<Money> money = this->repo_money.show();
	Money new_money(nr-1, coin);
	for (int i = 0; i < this->repo_money.get_size(); i++)
	{
		if (money[i].get_coin() == coin)
		{
			Money old_money(nr, money[i].get_coin());
			this->repo_money.update_element(old_money, new_money);
			return;
		}
	}
}

// Verify if must be introduced money in tonomate
int Service::verify_sum( const char* code, int nr, float coin)
{
	if (how_much(code, nr, coin) <= 0)
		return 0;
	else
		return 1;
}

// Verify how much money must be introduced in tonomate
float Service::how_much(const char* code, int nr, float coin)
{
	int price;
	price = get_product_price_by_code(code) - get_sum_coin(nr, coin);
	return price;
}

// Give a rest
//int Service::rest(const char* code, int nr, float coin)
int Service::rest(float sum, float price)
{
	float rest = sum - price;
	if (rest == 0)
		return 1;
	else
	{
		if (delete_money_tonomate(rest) == 1)
			return 1;
		else
			return -1;
	}
}

// Delete money from tonomate and give a rest
int Service::delete_money_tonomate(float rest)
{
	float sum = 0.0; //poate float
	int nr;

	for (int i = 0; i < this->repo_money.get_size();)
		if ((same_float(this->repo_money.show()[i].get_coin(), 0.50)) && (rest - sum >= 0.50) && (repo_money.show()[i].get_nr() > 0) && (rest - sum > 0.0))
			nr = repo_money.show()[i].get_nr(), update_money(nr, this->repo_money.show()[i].get_coin()), sum += 0.50; 
		else
			i++;

	for (int i = 1; i < this->repo_money.get_size();)
		if ((same_float(this->repo_money.show()[i].get_coin(), 0.10)) && (rest - sum >= 0.1) && (repo_money.show()[i].get_nr() > 0) && (rest - sum > 0.0))
			nr = repo_money.show()[i].get_nr(), update_money(nr, this->repo_money.show()[i].get_coin()), sum += 0.1;
		else
			i++;

	for (int i = 0; i < this->repo_money.get_size();)
		if ((same_float(this->repo_money.show()[i].get_coin(), 0.05)) && (rest - sum >= 0.05) && (repo_money.show()[i].get_nr() > 0) && (rest - sum > 0.0))
			nr = repo_money.show()[i].get_nr(), update_money(nr, this->repo_money.show()[i].get_coin()), sum += 0.05;
		else
			i++;

	for (int i = 0; i < this->repo_money.get_size();)
		if ((same_float(this->repo_money.show()[i].get_coin(), 0.01)) && (rest - sum >= 0.01) && (repo_money.show()[i].get_nr() > 0) && (rest - sum > 0.0))
			nr = repo_money.show()[i].get_nr(), update_money(nr, this->repo_money.show()[i].get_coin()), sum += 0.01;
		else
			i++;
	
	if (same_float(rest,sum))//se poate
		return 1;
	else
		return 0;
}

//da suma din aparat
float Service::sum_tonomate()
{
	float sum = 0.0;
	for (int i = 0; i < this->repo_money.get_size(); i++)
		sum += get_sum_coin(this->repo_money.show()[i].get_nr(), this->repo_money.show()[i].get_coin());
	return sum;
}

// Delete inexistent money from tonomate
void Service::delete_money_rest()
{
	for (int i = 0; i < this->repo_money.get_size(); i++)
		if (this->repo_money.show()[i].get_nr() == 0)
			this->repo_money.del_element(this->repo_money.show()[i]);
}

//undei float poate int
int Service::same_float(float f1, float f2)
{
	float epsilon = 0.0001;
	if (abs(f1 - f2) < epsilon)
		return 1;
	else
		return 0;
}
