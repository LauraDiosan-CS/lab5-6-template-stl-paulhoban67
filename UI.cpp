#include "UI.h"
#include <cstddef>
#include <iostream> 
#include <cstring>

UI::UI()
{

}

UI::~UI()
{

}

UI::UI(const Service& service)
{
	this->service = service;
}

void UI::display()
{
	cout << "\n";
	cout << "\n";
	cout << "    Pentru a cumpara un produs de la tonomatul 'CANDY SHOP' trebuie sa selectati tasta 1,\n ";
	cout << "  astfel veti putea vedea produsele disponibile. Pentru a cumpara, va rugam sa apasati\n ";
	cout << "  tasta 2, introduceti codul dorit al produsului si introduceti BANII.\n ";
	cout << "  ATENTIE !\n ";
	cout << "    Aparatul ofera rest doar in monezi de 0.50, 0.10, 0.05, 0.01 bani, iar BANII introdusi\n ";
	cout << "    incorect nu se mai inapoiaza conform SC.CANDYSHOP.SRL\n ";
	cout << "    CUMPARATI cu grija si prudenta!\n ";
}

void UI::menu_tonomate()
{
	cout << "			\n";
	cout << "			\n";
	cout << "           ***************************\n";
	cout << "           * WELCOME TO CANDY SHOP ! *\n";
	cout << "           ***************************\n";
	cout << "               ******************\n";
	cout << "               *        MENU    *\n";
	cout << "               *                *\n";
	cout << "               *   1.Show candy *\n";
	cout << "               *   2.Buy candy  *\n";
	cout << "               *   3.Exit       *\n";
	cout << "               *                *\n";
	cout << "               ******************\n";
	cout << "			\n";
	cout << "                                      Setings\n";
}

void UI::menu_setings()
{
	cout << "\n";
	cout << "                  1.Add product\n";
	cout << "                  2.Update product\n";
	cout << "                  3.Delete product\n";
	cout << "                  4.Show products\n";
	cout << "                  5.Show money\n";
	cout << "                  6.Show sum tonomate\n";
	cout << "                  7.Exit\n";
	cout << "\n";
}

void UI::run()
{
	char option[8];
	int option1;
	display();
	while (true)
	{
		menu_tonomate();
		cout << "\n";
		cout << "               OPTION: ", cin >> option;
		cout << "\n";
		if (strcmp(option,"1")==0)
		{
			this->show_product();
		}
		if (strcmp(option, "2") == 0)
		{
			this->transacion();
		}
		if (strcmp(option, "3") == 0)
		{
			break;
		}
		if (strcmp(option, "Setings") == 0)
		{
			while (true)
			{
				menu_setings();
				cout << "\n";
				cout << "               OPTION: ", cin >> option1;
				cout << "\n";
				if (option1 == 1)
				{
					this->add_product();
				}
				if (option1 == 2)
				{
					this->update_product();
				}
				if (option1 == 3)
				{
					this->delete_product();
				}
				if (option1 == 4)
				{
					this->show_product();
				}
				if (option1 == 5)
				{
					this->show_money();
				}
				if (option1 == 6)
				{
					this->show_sum_tonomate();
				}
				if (option1 == 7)
				{
					break;
				}
			}
		}
	}
}

void UI::add_product()
{
	float price;
	char* code;
	char* name;
	char cod[100], nume[100];
	cout << "               CODE: ", cin >> cod;
	cout << "               NAME: ", cin >> nume;
	cout << "               PRICE: ", cin >> price;

	code = new char[strlen(cod) + 1];
	strcpy_s(code, strlen(cod) + 1, cod);

	name = new char[strlen(nume) + 1];
	strcpy_s(name, strlen(nume) + 1, nume);

	this->service.add_product(code, name, price);
}

void UI::delete_product()
{
	int id;
	cout << "               ID TO DELETE : ", cin >> id;
	this->service.delete_product(id);
}

void UI::update_product()
{
	int id;
	char* code;
	char cod[20];
	cout << "               ID TO UPDATE: ", cin >> id;
	cout << "               NEW CODE: ", cin >> cod;
	code = new char[strlen(cod) + 1];
	strcpy_s(code, strlen(cod) + 1, cod);
	char* name;
	char nume[20];
	cout << "               NEW NAME: ", cin >> nume;
	name = new char[strlen(nume) + 1];
	strcpy_s(name, strlen(nume) + 1, nume);
	float price;
	cout << "               NEW PRICE: ", cin >> price;

	this->service.update_product(id, code, name, price);
}

void UI::show_product()
{
	vector <Products> products = this->service.show_product();
	int size = products.size();
	for (int i = 0; i < size; i++)
	{
		cout << products[i] << "\n";
	}
}

void UI::transacion()
{
	char* code;
	char cod[100];
	cout << "               CODE: ", cin >> cod;
	code = new char[strlen(cod) + 1];
	strcpy_s(code, strlen(cod) + 1, cod);
	float price = this->service.get_product_price_by_code(code);

	int nr = 0;
	float coin = 0.0;
	float sum = 0.0;
	while (sum < price)
	{
		cout << "               NR: ", cin >> nr;
		cout << "               COIN: ", cin >> coin;
		sum += this->service.get_sum_coin(nr, coin);
		this->service.add_money(nr, coin);
	}
	if (this->service.rest(sum, price) == -1)
		cout << "               CAN'T BUY !";
	else
	{
		this->service.delete_money_rest();
		cout << "               TRANSACTION COMPLETED !\n";
	}
}

void UI::show_money()
{
	vector <Money> money = this->service.show_coin();
	int size = money.size();
	for (int i = 0; i < size; i++)
	{
		cout << money[i] << "\n";
	}
}

void UI::show_sum_tonomate()
{
	float sum = this->service.sum_tonomate();
	cout << "               SUM: " << sum;
}
