#pragma once
#include <vector>
using namespace std;


template <class T> 
class Repo
{
private:
	vector<T> elements;
public:
	Repo()
	{

	}

	~Repo()
	{
		this->elements.clear();
	}

	void clear() {
		this->elements.clear();
	}
	//m.suceveanu@stratec.com

	void add_element(T p) {
		this->elements.push_back(p);
	}

	void del_element(T p)
	{
		typename vector<T>::iterator it;
		it = find(this->elements.begin(), this->elements.end(), p);
		if (!(it == this->elements.end()))
		{
			this->elements.erase(it);
		}
	};

	void update_element(T& old_product, T& new_product)
	{
		typename vector <T>::iterator it;
		it = find(this->elements.begin(), this->elements.end(), old_product);
		if (!(it == this->elements.end()))
		{
			*it = new_product;
		}
	};

	vector<T> show_elements()
	{
		return this->elements;
	};

	int get_size()
	{
		return this->elements.size();
	};

	T get_element(int id)
	{
		return this->elements[id];
	}
};
