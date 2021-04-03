#pragma once
#include "Product.h"
#include <vector>

class Product;


class Cart
{
private:
	vector<Product*> allMyProducts;

public:
	Cart();
	Cart(const Cart& cart);
	~Cart();

	void addProductToCart(Product* myProduct);
	int getNumOfProducts() const;
	double getCurrentCartTotalPrice();
	void showCart()const;
	void cleanCart();
	const vector<Product*>& getAllProductsFromMyCart()const;
};