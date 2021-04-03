#include "Cart.h"


Cart::Cart() { }

Cart::Cart(const Cart& cart) 
{
	vector<Product*>::const_iterator itr= cart.allMyProducts.begin();
	vector<Product*>::const_iterator itrEnd= cart.allMyProducts.end();

	for (; itr != itrEnd; itr++)
	{
		this->allMyProducts.push_back((*itr));
	}
}

Cart::~Cart() 
{
	this->allMyProducts.clear();
}

double Cart:: getCurrentCartTotalPrice()
{
	vector<Product*>::iterator itr = this->allMyProducts.begin();
	vector<Product*>::iterator itrEnd = this->allMyProducts.end();
	double price = 0;

	for (;itr!=itrEnd; itr++)
	{
		price+= (*itr)->getPrice();
	}
	return price;
}


void Cart:: addProductToCart(Product* myProduct)
{
	this->allMyProducts.push_back(myProduct);
	cout << "product added" << endl;
}


int Cart::getNumOfProducts() const 
{
	return this->allMyProducts.size();
}

const vector<Product*>& Cart::getAllProductsFromMyCart()const
{
	return this->allMyProducts;
}

void Cart::showCart()const
{
	vector<Product*>::const_iterator itr = this->allMyProducts.begin();
	vector<Product*>::const_iterator itrEnd = this->allMyProducts.end();

	cout << "the content of the cart is: " << endl;
	for (int i=0;itr!=itrEnd; itr++,i++) 
	{
		cout << i << "." << (*itr)->getNameOfPRoduct() << " price: " << (*itr)->getPrice() << " shekels" << endl;
	}
}

void Cart::cleanCart()
{
	this->allMyProducts.clear();
	//delete allMyProducts;
}

