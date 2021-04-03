#pragma once
using namespace std;
#include "SellerAndBuyer.h"
#include <vector>
#include <fstream>

static const int PASS_MINIMUM = 8;
static const int PASS_MAXIMUM = 30;
static const int MINIMUM_NAME = 3;
static const int MAXIMUM_NAME = 30;
static const string fileName = "Users.txt";

typedef vector<User*>::iterator ITR;
typedef vector<User*>::const_iterator constITR;

typedef vector<Product*>::iterator prdctITR;
typedef vector<Product*>::const_iterator prdctConstITR;

// enum for indication between buyer and seller 
enum BuyerOrSeller { buyer, seller,BuyerAndSeller };

class System
{
private:
	string  systemName;
	vector<User*>AllSellersAndBuyers;
	int numOfUsers;

public:
	System(const string NameOFSystem);
	~System();
	void operator+=(User* user);
	void showAllUsers(BuyerOrSeller userOrSeller)const;
	bool checkIfUserExists(const string userName, BuyerOrSeller user, Buyer** buyerPtr = nullptr, Seller** sellerPtr = nullptr,SellerAndBuyer** sellerAndBuyerPtr=nullptr)const; 
	//indication true - with search . false - without search
	void showAllProductsWithSpecificName(string search, bool indication)const;
	int getNumOfUsers()const;

	bool checkIfProductExist(const string  sellerName, int numOfProduct,Product** prdctPtr)const; 
	bool checkIfExistAtLeastOneProdcut()const;

	void saveUsers();
	void loadUsers();
};