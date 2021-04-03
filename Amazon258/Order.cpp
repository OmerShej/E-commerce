#include "Order.h"


Order::Order(Buyer* buyer,const Array<Product*>&allfinallProdcuts,int numOfproducts):finallProdcuts()
{
	double totalPrice = 0;

	for (int i = 0; i < numOfproducts; i++) 
	{
		totalPrice += allfinallProdcuts[i]->getPrice(); // calculate the total price to pay 
		
		{ // ckeck if the seller already at the array of all sellers 
			// and insert all the seller involved to allSellersInvovled  
			if (!checkIfSellerExist(allfinallProdcuts[i]->getSeller().getUserName()))
			{
				this->allSellersInvolved.push_back(&allfinallProdcuts[i]->getSeller());
			}
		}
	}
	this->totalPrice = totalPrice;
	this->finallProdcuts = allfinallProdcuts;
	this->currBuyer = buyer;
	this->numOfProducts = numOfproducts;
}

Order::Order()
{
	this->totalPrice = 0;
	this->currBuyer = NULL;
}

Order::~Order() 
{
	this->allSellersInvolved.clear(); 
	// just free the array not the content 
	//cause ther is pointers to sellers and they will free in seller's d'tor 
}


bool Order::checkIfSellerExist(const string sellerName)const
{
	vector<Seller*>::const_iterator itr=this->allSellersInvolved.begin();
	vector<Seller*>::const_iterator itrEnd=this->allSellersInvolved.end();

	for (;itr!=itrEnd;itr++)
	{
		if ((*itr)->getUserName()== sellerName)
			return true;
	}
	return false;
}

void Order::showOrder()const
{
	cout << "order details:" << endl;
	cout << "total price: "<< this->totalPrice << endl;
	cout << "num of products: " << this->numOfProducts << endl;
	for (int i = 0; i < numOfProducts; i++)
	{
		this->finallProdcuts[i]->showProdcut();
	}
}

const vector<Seller*>& Order::getAllSellersInolved()
{
	return this->allSellersInvolved;
}