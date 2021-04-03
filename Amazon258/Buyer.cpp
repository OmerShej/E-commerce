#define _CRT_SECURE_NO_WARNINGS
#include "Buyer.h"
#include "Array.h"

Buyer::Buyer(string userName, string password,const Address& buyerAddress)
	:User(userName,password,buyerAddress)
{
	this->myCart = new Cart();
	this->currOrder = nullptr;
}

Buyer::Buyer()
{
	this->myCart = new Cart();
	this->currOrder = nullptr;
}

Buyer::Buyer(const Buyer& buyer)
	:User(buyer)
{
	vector<Order*>::const_iterator itr = buyer.historyOfOrder.begin();
	vector<Order*>::const_iterator itrEnd = buyer.historyOfOrder.end();
	for (; itr != itrEnd; itr++) 
	{
		this->historyOfOrder.push_back((*itr));
	}
	this->myCart = new Cart();
	this->currOrder = nullptr;
}

Buyer::Buyer(ifstream& inFile):User(inFile)
{
	this->myCart = new Cart();
	this->currOrder = nullptr;
}

Buyer::~Buyer() 
{
	if (this->myCart != nullptr)
	{
		delete this->myCart; // free buyers cart
	}
	if (this->currOrder != nullptr) 
	{
		delete this->currOrder;// free buyers curr order 
	}
	if (!this->historyOfOrder.empty()) // free the array but not the products cause the seller still pointing to them 
	{
		vector<Order*> ::iterator itr = this->historyOfOrder.begin();
		vector<Order*> ::iterator itrEnd = this->historyOfOrder.end();

		for (;itr!=itrEnd;itr++) 
		{
			delete (*itr);
		}
		this->historyOfOrder.clear();
	}

}

const string Buyer:: getPassWord() 
{
	return this->userPassword;
}

void Buyer:: show()const 
{
	User::show();
}
bool Buyer::operator>(Buyer* buyer)const
{
	if (this->myCart != nullptr && buyer->myCart!=nullptr)// no empty carts  
	{
		return  this->myCart->getCurrentCartTotalPrice()> buyer->myCart->getCurrentCartTotalPrice();
	}
	else
	{
		cout << "can't compare there is empty cart" << endl;
	}
	return false;
}

Cart* Buyer::getCart() const
{
	return this->myCart;
}

// check if product is already at my cart (with comparing serial number)
bool Buyer::checkIfProductExistInMyCart(const Product* newProduct)const
{
	vector<Product*> ::const_iterator itr = this->myCart->getAllProductsFromMyCart().begin();
	vector<Product*> ::const_iterator itrEnd = this->myCart->getAllProductsFromMyCart().end();

	for (; itr != itrEnd; itr++) 
	{
		if((*itr)->getSeielNumber() == newProduct->getSeielNumber())
		{
			return true;
		}
	}
	return false;
}

void Buyer::exeOrderForBuyer(int** indexArray,int numOfindex) 
{
	Array<Product*>finallProdcuts(numOfindex);

	for (int i = 0; i < numOfindex; i++)
	{
		finallProdcuts += (this->myCart->getAllProductsFromMyCart())[(*indexArray)[i]];
	}
	this->currOrder = new Order(this,finallProdcuts, numOfindex);
	
	delete[] *indexArray;
}

bool Buyer::checkIfOrderExist() const
{
	if (this->currOrder != NULL) 
	{
		return true;
	}
	return false;
}
void Buyer::addOrderTohistoryOrders()
{
	this->historyOfOrder.push_back(this->currOrder);
	this->currOrder = NULL;
}

void Buyer::cleanCart() 
{
	this->myCart->cleanCart();
}

void Buyer::showHistoryOfORder()const
{
	for (int i = 0; i < this->numOforderInHistory; i++)
	{
		cout << "order number: " << i + 1 << ".";
		this->historyOfOrder[i]->showOrder();
	}
}


bool Buyer::checkIFcanWrithFeedBAckOnSeller(const string sellerName)
{
	vector<Order*>::iterator itr = this->historyOfOrder.begin();
	vector<Order*>::iterator itrEnd = this->historyOfOrder.end();

	for(;itr!=itrEnd;itr++)
	{
		vector<Seller*>::const_iterator itrPrdct = (*itr)->getAllSellersInolved().begin();
		vector<Seller*>::const_iterator itrPrdctEnd = (*itr)->getAllSellersInolved().end();
		
		for(; itrPrdct!= itrPrdctEnd;itrPrdct++)
		{
			if ( (*itrPrdct)->getUserName()== sellerName)
			return true;
		}
	}
	return false;
}

Order* Buyer::getOrder()const
{
	return this->currOrder;
}