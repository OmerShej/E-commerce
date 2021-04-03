#pragma once
#include "Address.h"
#include "Product.h"
#include "FeedBack.h"
#include "User.h"
#include <vector>

class Product; // forward declaration
class FeedBack;

typedef vector<Product*>::iterator productITR;

class Seller: virtual public User // virtual inherit'
{
protected:
	vector<Product*> allProductsSeller;
	int numOFproduct;
	vector<FeedBack*> allMyFeedbeck;
	int numOfFeedbacks;
	
public:
	Seller(string name, string passWord,const Address& sellerAdress);
	Seller(const Seller& seller);
	Seller(ifstream& inFile);
	Seller();
	virtual ~Seller();

	void addPrdctToSeller(Product* procudt);
	const vector<Product*>& getAllPRoductsOfSeller()const;
	void addFeedBack(FeedBack* feedBackptr);
	int getNumOfProduct()const;
	bool checkIfProductExist(const string name);
	virtual void show()const ;
	void operator=(const Seller& seller);
};