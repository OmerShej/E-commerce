#define _CRT_SECURE_NO_WARNINGS
#include "System.h"

System::System(const string NameOFSystem)
{
	this->systemName = NameOFSystem;
	this->numOfUsers  = 0;
}
System::~System()
{
	ITR itr = AllSellersAndBuyers.begin();
	ITR itrEnd = AllSellersAndBuyers.end();

	if (!AllSellersAndBuyers.empty())
	{
		for (; itr !=itrEnd; itr++)
		{
			delete (*itr); // free each buyer/seller/buyerAndSeller 
		}
	}
	
	 AllSellersAndBuyers.clear();
}

void System::saveUsers()
{
	vector<User*>::iterator itr = this->AllSellersAndBuyers.begin();
	vector<User*>::iterator itrEnd = this->AllSellersAndBuyers.end();

	ofstream outFile("Users.txt",ios::trunc);
	for (; itr != itrEnd; itr++)
	{
		outFile << typeid(*(*itr)).name() + 6 << endl;
		outFile << (*itr)->getAddress().getCity() << endl;
		outFile << (*itr)->getAddress().getStreet() << endl;
		outFile << (*itr)->getAddress().gethouseNum() << endl;
		outFile << (*itr)->getAddress().getzipCode() << endl;
		outFile << (*itr)->getUserName() << endl;
		outFile << (*itr)->getPassword() << endl;
	}
	outFile.close();
}

void System::loadUsers() 
{
	string type;
	ifstream inFile(fileName, ios::in);
	while (!inFile.eof() && inFile.is_open())
	{
		inFile >> type;
		if (type == "Buyer")
		{
			this->AllSellersAndBuyers.push_back(new Buyer(inFile));
		}
		else if (type == "Seller") 
		{
			this->AllSellersAndBuyers.push_back(new Seller(inFile));
		}
		else if (type == "SellerAndBuyer") 
		{
			this->AllSellersAndBuyers.push_back(new SellerAndBuyer(inFile));
		}
		type = "";
	}
	inFile.close();
}

void  System::operator+=(User* user)
{
	this->AllSellersAndBuyers.push_back(user);
}

// show all buyers/sellers/sellersAndBuyers according to  indication 
void System::showAllUsers(BuyerOrSeller SellerOrBuyer)const
{
	for (int i = 0; i < this->AllSellersAndBuyers.size(); i++)
	{
		Buyer* tempBuyer = dynamic_cast<Buyer*>(AllSellersAndBuyers[i]);
		Seller* tempSeller = dynamic_cast<Seller*>(AllSellersAndBuyers[i]);
		SellerAndBuyer* tempSellerAndBuyer = dynamic_cast<SellerAndBuyer*>(AllSellersAndBuyers[i]);

		switch (SellerOrBuyer)
		{
		case buyer:
			if (tempBuyer != NULL) {
				tempBuyer->show();
			}
			break;
		case seller:
			if (tempSeller != NULL) {
				tempSeller->show();
			}
			break;
		case BuyerAndSeller:
			if (tempSellerAndBuyer != NULL) {
				tempSellerAndBuyer->show();
			}
			break;
		default:
			break;
		}
	}
}

//10 
//indication true - with search . false - without search
void System::showAllProductsWithSpecificName(string search, bool indication)	const
{
	constITR userIter = this->AllSellersAndBuyers.begin();
	constITR userIterEnd = this->AllSellersAndBuyers.end();

	int flagNumOfPRoducts = 0;
	for (int i=0;userIter != userIterEnd; userIter++,i++)
	{
		Seller* tmpSeller = dynamic_cast <Seller*>(*userIter);
		if (tmpSeller)
		{
			prdctConstITR prdctItr = tmpSeller->getAllPRoductsOfSeller().begin();
			prdctConstITR prdctItrEnd = tmpSeller->getAllPRoductsOfSeller().end();

			cout << i << "." << (*userIter)->getUserName() << ":" << endl;
			for (int j=0; prdctItr != prdctItrEnd;prdctItr++,j++)
			{
				if (indication)
				{
					if ((*prdctItr)->getNameOfPRoduct() == search)
					{
						cout << j << ".name: " << (*prdctItr)->getNameOfPRoduct() << " , price " << (*prdctItr)->getPrice() << " shekels" << endl;
						flagNumOfPRoducts++;
					}
				}
				else // show products without index of search
				{
					cout << j << ".name: " << (*prdctItr)->getNameOfPRoduct() << " , price " << (*prdctItr)->getPrice() << " shekels" << endl;
					flagNumOfPRoducts++;
				}
			}
		}
	}
	if (flagNumOfPRoducts == 0 && indication)
	{
		cout << "no products with this name" << endl;
	}
}

bool System::checkIfProductExist(const string sellerName, int indexOfProduct, Product **prdctPtr)const
{
	Seller* sellerPtr = nullptr;
	if (checkIfUserExists(sellerName, BuyerOrSeller::seller, nullptr, &sellerPtr, nullptr))
	{
		if (sellerPtr != nullptr) 
		{
			prdctConstITR itr = sellerPtr->getAllPRoductsOfSeller().begin();
			prdctConstITR itrEnd = sellerPtr->getAllPRoductsOfSeller().end();
			
			for (int i=0;itr != itrEnd;itr++,i++)
			{
				if (i == indexOfProduct) 
				{
					*prdctPtr = (*itr);
					return true;
				}	
			}
			cout << "there is a problem with index of prodcut " << endl;
		}
		else
		{
			cout << "error with the name of the seller, please try again later" << endl;
		}
		return false;
	}
}

//////check if specific name is already exist  according to indication buyer/seller/sellerAndBuyer and update the pointer 
bool System::checkIfUserExists(const string userName, BuyerOrSeller user, Buyer** buyerPtr, Seller** sellerPtr, SellerAndBuyer** sellerAndBuyerPtr)const
{
	Buyer* tempBuyer;
	Seller* tempSeller;
	SellerAndBuyer* tempSellerAndBuyer;

	constITR userItr = this->AllSellersAndBuyers.begin();
	constITR userItrEnd = this->AllSellersAndBuyers.end();

	for (; userItr != userItrEnd; userItr++)
	{
		User* tempUser = *userItr;
		switch (user)
		{
		case buyer:
			tempSellerAndBuyer = dynamic_cast<SellerAndBuyer*>(tempUser);
			tempBuyer = dynamic_cast<Buyer*>(tempUser);
			if (tempBuyer != NULL)
			{
				if (userName == tempBuyer->getUserName())
				{
					if (buyerPtr != nullptr)
					{
						*buyerPtr = tempBuyer;
					}
					return true;
				}
			}
			else if (tempSellerAndBuyer != NULL)
			{
				if (userName == tempSellerAndBuyer->getUserName())
				{
					*sellerAndBuyerPtr = tempSellerAndBuyer;
					return true;
				}
			}
			break;

		case seller:
			tempSeller = dynamic_cast<Seller*>(tempUser);
			tempSellerAndBuyer = dynamic_cast<SellerAndBuyer*>(tempUser);
			if (tempSeller != NULL)
			{
				if (userName == tempSeller->getUserName())
				{
					*sellerPtr = tempSeller;
					return true;
				}
			}
			else if (tempSellerAndBuyer != NULL)
			{
				if (userName == tempSellerAndBuyer->getUserName())
				{
					*sellerAndBuyerPtr = tempSellerAndBuyer;
					return true;
				}
			}
			break;
		default:
			break;
		}
	}
	return false;
}
	

	

int System::getNumOfUsers()const
{
	return this->AllSellersAndBuyers.size();
}



bool System::checkIfExistAtLeastOneProdcut()const
{
	if (this->AllSellersAndBuyers.empty())
	{
		return false;
	}
	Seller* tempSeller;
	SellerAndBuyer* tempSellerAndBuyer;

	constITR itrUser = this->AllSellersAndBuyers.begin();
	constITR itrUserEND = this->AllSellersAndBuyers.end();

	for (;itrUser != itrUserEND;itrUser++)
	{
		tempSeller = dynamic_cast<Seller*>(*itrUser);
		tempSellerAndBuyer = dynamic_cast<SellerAndBuyer*>(*itrUser);
		if (tempSeller)
		{
			if (!tempSeller->getAllPRoductsOfSeller().empty())
			{
				return true;
			}
		}
		else if(tempSellerAndBuyer)
		{
			if (!tempSellerAndBuyer->getAllPRoductsOfSeller().empty()) 
			{
				return true;
			}
		}
	}
	return false;

	/*for (int i = 0; i < numOfUsers; i++) 
	{
		Seller* tmpSeller = dynamic_cast <Seller*>(AllSellersAndBuyers[i]);
		if (tmpSeller!=NULL)
		{
			if (tmpSeller->getNumOfProduct() > 0)
				return true;
		}
	}
	return false;*/
}

