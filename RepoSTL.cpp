/*#include "RepoSTL.h"
#include <fstream>

using namespace std;

RepoSTL::RepoSTL() {
	this->fileNameIn = NULL;
	this->fileNameOut = NULL;
}

RepoSTL::RepoSTL(const char* fileNameIn, const char* fileNameOut)
{
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
	this->load_from_file();
}

RepoSTL::~RepoSTL()
{
	this->products.clear();
}

RepoSTL& RepoSTL::operator=(const RepoSTL& r)
{
	this->set_fileNameIn(r.fileNameIn);
	this->set_fileNameOut(r.fileNameOut);
	this->load_from_file();
	return *this;
}

RepoSTL::RepoSTL(const RepoSTL& r)
{
	this->fileNameIn = new char[strlen(r.fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(r.fileNameIn) + 1, r.fileNameIn);
	this->fileNameOut = new char[strlen(r.fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(r.fileNameOut) + 1, r.fileNameOut);
}

void RepoSTL::set_fileNameIn(const char* fileNameIn)
{
	if (this->fileNameIn != NULL)
	{
		delete[]this->fileNameIn;
	}
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
}

void RepoSTL::set_fileNameOut(const char* fileNameOut)
{
	if (this->fileNameOut != NULL)
	{
		delete[]this->fileNameOut;
	}
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
}

void RepoSTL::add(Products p) {
	this->products.push_back(p);
	this->save_to_file();
}

vector<Products> RepoSTL::show() {
	return this->products;
}

int RepoSTL::get_size()
{
	return this->products.size();
}

Products RepoSTL::get_product(int id)
{
	if (id < 1 || id > this->products.size())
	{
		char code[] = "";
		char name[] = "";
		return Products(0, code, name, 0.0);
	}
	return this->products[id];
}

void RepoSTL::update(Products& old_product, Products& new_product)
{
	vector<Products>::iterator it;
	it = find(this->products.begin(), this->products.end(), old_product);
	if (!(it == this->products.end()))
	{
		*it = new_product;
	}
	this->save_to_file();
}

void RepoSTL::del(Products& p)
{
	vector<Products>::iterator it;
	it = find(this->products.begin(), this->products.end(), p);
	if (!(it == this->products.end()))
	{
		this->products.erase(it);
	}
	this->save_to_file();
}

void RepoSTL::load_from_file()
{
	if (this->fileNameIn != NULL)
	{
		this->products.clear();
		ifstream f(this->fileNameIn);
		char* code = new char[20];
		char* name = new char[20];
		int id;
		float price;
		while (!f.eof())
		{
			f >> id >> code >> name >> price;
			if (strlen(code) > 0 && strlen(name) > 0)
			{
				this->add(Products(id, code, name, price));
			}
		}
		delete[] code;
		delete[] name;
		f.close();
	}
}

void RepoSTL::save_to_file()
{
	if (this->fileNameOut != NULL)
	{
		ofstream f(this->fileNameOut);
		for (int i = 0; i < this->products.size(); i++)
		{
			f << this->products[i] << endl;
		}
		f.close();
	}
}*/
