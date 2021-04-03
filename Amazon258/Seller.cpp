#include "Seller.h"

Seller::Seller(string name, string passWord, const Address &sellerAddress)
	: User(name, passWord, sellerAddress) { }

Seller::Seller() { }

void Seller::show() const 
{
	User::show();
}

Seller::~Seller()
{
	productITR itr = allProductsSeller.begin();
	productITR itrEND = allProductsSeller.end();

	// free each product
	if (!this->allProductsSeller.empty())
	{
		for (; itr != itrEND; itr++)
		{
			delete *itr;
		}
	}
	allProductsSeller.clear();
	if (!this->allMyFeedbeck.empty())
	{
		for (; itr != itrEND; itr++)
		{
			delete *itr;
		}
	}
	allMyFeedbeck.clear();
}
	
// copy c'tor 
Seller::Seller(const Seller& seller) :User(seller)
{
	this->allProductsSeller = seller.allProductsSeller;
	this->allMyFeedbeck = seller.allMyFeedbeck;
}
Seller::Seller(ifstream& inFile):User(inFile)
{

}

void Seller::addPrdctToSeller(Product* currProcudt) 
{
	this->allProductsSeller.push_back(currProcudt);
}

const vector<Product*>& Seller::getAllPRoductsOfSeller()const
{
	return this->allProductsSeller;
}

int Seller::getNumOfProduct()const
{
	return this->allProductsSeller.size();
}

void Seller::addFeedBack(FeedBack* feedBackptr)
{
	this->allMyFeedbeck.push_back(feedBackptr);
}

void Seller::operator=(const Seller& seller)
{
	this->allMyFeedbeck = seller.allMyFeedbeck;
	this->numOFproduct = seller.numOfFeedbacks;
	this->allProductsSeller = seller.allProductsSeller;
	this->numOFproduct = seller.numOFproduct;
}

bool Seller::checkIfProductExist(const string name) 
{
	productITR itr = allProductsSeller.begin();
	productITR itrEND = allProductsSeller.end();

	for (; itr!=itrEND; itr++) 
	{
		if ( (*itr)->getNameOfPRoduct()==name ) 
		{
			return true;
		}
	}
	return false;
}