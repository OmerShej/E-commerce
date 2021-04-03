#include "Product.h"

int Product::globalSerielNumber = 0;

Product::Product(string name, Category category, double price, Seller& seller): sellerOfPrdct(seller)
{
	globalSerielNumber++; // update the global counter 
	this->name = name;
	this->price = price;
	this->category = category;
	this->serielNumber = globalSerielNumber;
}

// copy c'tor 
Product::Product(const Product& prdct) :sellerOfPrdct(prdct.sellerOfPrdct)
{
	cout << "copy c'tor" <<endl;
	globalSerielNumber++;
	this->name = prdct.name;
	this->price = prdct.price;
	this->category = prdct.category;
	this->serielNumber = globalSerielNumber;

}

Product::~Product() { }

string Product::getNameOfPRoduct()const
{
	return this->name;
}

int Product::getSeielNumber()const
{
	return this->serielNumber;
}

double Product::getPrice()const
{
	return this->price;
}

Product::Product(Product* prdct) :sellerOfPrdct(prdct->sellerOfPrdct)
{
	this->name = prdct->name;
	this->price = prdct->price;
	this->serielNumber = prdct->serielNumber;
	this->sellerOfPrdct = prdct->sellerOfPrdct;
}

Seller& Product::getSeller()
{
	return this->sellerOfPrdct;
}

void Product::showProdcut()const 
{
	cout << this->name << ", " << this->price << " shekels." << endl;
}

ostream& operator<<(ostream& os, const Product& product)
{
	os << "Product: " << product.name << ", " << product.price << " shekels." << endl;
	return os;
}

void Product::setSeller(const Seller& seller)
{
	this->sellerOfPrdct = seller;
}