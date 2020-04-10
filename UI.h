#pragma once
#include "Service.h"
#include "Products.h"
#include "Money.h"
#include <fstream>
#include <iostream>

class UI
{
private:
    Service service;

    void menu_tonomate();
    void menu_setings();
    void display();

    void add_product();
    void show_product();
    void update_product();
    void delete_product();

    void add_money();
    void transacion();

    void show_money();
    void show_sum_tonomate();

public:
    UI();
    UI(const Service& service);
    ~UI();
    void run();
};