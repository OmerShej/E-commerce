#pragma once
#include "Seller.h"
#include <iostream>
using namespace std;

class Seller;// forward declaration 

enum Category { KIDS, ELECTRICITY, OFFICE, CLOTHING };

class Product 
{
private:
	static int globalSerielNumber;
	int serielNumber;
	string name;
	Seller& sellerOfPrdct;
	Category category;
	double price;

public:
	Product(string name, Category category, double price, Seller& seller);
	Product(const Product& prdct);
	Product(Product* prdct);
	~Product();
		
	int getSeielNumber()const;
	string getNameOfPRoduct()const;
	double getPrice()const;
	void showProdcut()const;
	friend ostream& operator<<(ostream& os, const Product& product);
	Seller& getSeller();
	void setSeller(const Seller& seller);
};

