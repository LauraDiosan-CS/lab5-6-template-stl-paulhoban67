#pragma once
#include"Repo.h"
#include <fstream>
#include <iostream>
#include <cstddef>

template <class T>
class RepoSTL : public Repo<T>
{
private:
	char* filename;
public:
	RepoSTL() : Repo<T>()
	{
		this->filename = NULL;
	};

	RepoSTL(const char* filename)
	{
		this->filename = new char[strlen(filename) + 1];
		strcpy_s(this->filename, strlen(filename) + 1, filename);
		this->load_to_file();
	};

	~RepoSTL()
	{
		delete[] this->filename;
	};

	RepoSTL(const RepoSTL& repo)
	{
		this->filename = new char[strlen(repo.filename) + 1];
		strcpy_s(this->filename, strlen(repo.filename) + 1, repo.filename);
		this->load_to_file();
	}
	void set_filename(const char* filename)
	{
		if (this->filename != NULL) {
			delete[] this->filename;
		}
		if (filename != NULL) {
			this->filename = new char[strlen(filename) + 1];
			strcpy_s(this->filename, strlen(filename) + 1, filename);
		}
		else
			this->filename = NULL;
	};

	void add_element(T element) {
		Repo<T>::add_element(element);
	};

	vector<T> show()
	{
		return Repo<T>::show_elements();
	};

	int get_size()
	{
		return  Repo<T>::get_size();
	};

	RepoSTL<T>& operator=(const RepoSTL<T>& repo)
	{
		this->set_filename(repo.filename);
		this->load_to_file();
		return *this;
	};

	void load_to_file()
	{
		if (this->filename != NULL)
		{
			ifstream f(this->filename);

			T element;

			while (f >> element)
			{
				Repo<T>::add_element(element);
			}

			f.close();
		}
		else 
			Repo<T>::clear();
	};

	void save_to_file()
	{
		if (this->filename != NULL) {
			ofstream f(this->filename);
			int n = Repo<T>::get_size();
			for (int i = 0; i < n; i++)
				f << Repo<T>::get_element(i);
			f.close();
		}
	}
};

