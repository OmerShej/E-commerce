#pragma once
#include "Buyer.h"
#include "Seller.h"	
#include "User.h"

class SellerAndBuyer :public Seller, public Buyer
{
public:
	SellerAndBuyer(const Seller& seller, const Buyer& buyer);
	SellerAndBuyer(string name, string password, Address& userAddress);
	SellerAndBuyer(ifstream& inFile);
	virtual ~SellerAndBuyer();
	virtual void show()const;
};