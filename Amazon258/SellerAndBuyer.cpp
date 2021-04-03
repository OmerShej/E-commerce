#include "SellerAndBuyer.h"

SellerAndBuyer::SellerAndBuyer(const Seller& seller, const Buyer& buyer)
	:User(seller),Seller(seller),Buyer(buyer) { }

SellerAndBuyer::SellerAndBuyer (string name, string password, Address& userAddress)
	:User(name,password, userAddress) { }

SellerAndBuyer::SellerAndBuyer(ifstream& inFile):User(inFile) { }

SellerAndBuyer::~SellerAndBuyer() { }

void SellerAndBuyer::show()const
{
	Seller::show();
}
