#pragma once
#include"Order.h"
#include "Product.h"
#include "Buyer.h"
#include "Array.h"
#include <vector>

class Buyer;
class Product;
class Seller;

typedef vector<Seller*>::const_iterator itr;
typedef vector<Seller*>::const_iterator itrEnd;

class Order 
{
private:
	Array<Product*>finallProdcuts;
	double totalPrice;
	vector <Seller*>allSellersInvolved;
	int numOfSellerInvolved;
	Buyer* currBuyer;
	int numOfProducts;
	
public:
     Order(Buyer* buyer, const Array<Product*>&allfinallProdcuts,int numOfproducts);
	 Order();
	 ~Order();

	 bool checkIfSellerExist(const string sellerName)const;
	 void showOrder()const;
	 const vector<Seller*>& getAllSellersInolved();
};