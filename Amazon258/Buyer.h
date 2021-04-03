#pragma once
#include <iostream>
#include "Address.h"
#include "Product.h"
#include "Cart.h"
#include "Order.h"
#include "User.h"
#include <vector>

class Order; // forward declatrion 
class Cart;// forward declatrion 

class Buyer: virtual public User // virtual inheritance
{
protected:
	Cart* myCart;
	Order* currOrder;
	vector<Order*>historyOfOrder;
	int numOforderInHistory;
   
public:
	Buyer(string userName, string password,const Address &buyerAddress);
	Buyer(const Buyer& buyer);
	Buyer();
	Buyer(ifstream& inFile);
	virtual ~Buyer();
    const string getPassWord() ;
	Cart* getCart()const ;
	Order* getOrder()const;
	bool checkIfProductExistInMyCart(const Product* newProduct) const;
	void cleanCart();
	void exeOrderForBuyer(int** indexArray,int numOfIndexes);
	bool checkIfOrderExist()const ;
	void addOrderTohistoryOrders();
	void showHistoryOfORder() const;
	bool checkIFcanWrithFeedBAckOnSeller(const string sellerName);
	virtual void show() const;
	bool operator>(Buyer* buyer)const;
};
