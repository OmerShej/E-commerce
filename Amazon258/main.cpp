/**************************************************************
Omer Shejtman, id 316016708, in class with Keren Kalif on sunday.
***************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <string>
#include <crtdbg.h>


//test - memory leack check 
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
// test - end of memory le

#include <iostream>
using namespace std;

#include "System.h"
#include "Address.h"
#include "Product.h"


enum  checkType { CT_ONLY_LETTERS, CT_ONLY_LETTERS_AND_DIGITS }; // use for the input validation

void showMenu();
// help func 
void userInput(string& city, string& street, int& houseNum, int & zipcode, string& userName, string& password, System* system, BuyerOrSeller user);
bool inputValidation(string string, checkType indecation);
void addProductToSeller(System* system);
Product* productInput(Seller* seller);
Buyer* checkInputValidationAndIfBuyerExist(System* system1);
void convertStringToArrayOFIndex(int numOfProduct,int** indexArray, int *numOfidexes);
Date* createDate();
FeedBack* createFeedBack(Buyer* buyerPtr);
Address* addressInput();
//
void addUSerToSystem(BuyerOrSeller userKind, System* system1);
void addFeedBackToSEller(System* system1);
void addPRoductToCartOfBuyer(System* system1);
void executrOrderForBuyer(System* system1);
void payForOrder(System* system1);
void showAllPrdcsWithSpecifName(System* system1);
void comparToBuyersCartTotalPrice(System* system1);
void showAllUsersWithSpecType(System* system1);
void useTheOperatorDate();
void useTheOperatorAddress();
void useTheOperatorProduct();


int main()
{
  	int houseNum=0, zipcode, crdit_card = 0, menuIndex = 0;
	string systemName, userName;
	System *system1 = nullptr;
	Product* prdctPtr = nullptr;
	string sellerName;
	bool flag = true;


	//check system name 
	while (flag)
	{
		cout << "Welcome. Enter system name: " << endl;
		getline(cin, systemName);
		
		flag = !inputValidation(systemName, CT_ONLY_LETTERS);
		if (!flag)
		{
			system1 = new System(systemName);
		}
	}
	system1->loadUsers();
	while (menuIndex != 17)
	{
		showMenu();
		cout << "Enter your choose: " << endl;
		cin >> menuIndex;
		cin.ignore();
		switch (menuIndex)
		{
		case 1:// add buyer 
			addUSerToSystem(BuyerOrSeller::buyer, system1);
			break;
		case 2: // add seler 
			addUSerToSystem(BuyerOrSeller::seller, system1);
			break;
		case 3: // add a produbt to seller; 
			cout << "you choose to add prudoct to seller" << endl;
			if (system1->getNumOfUsers() != 0)
			{
				addProductToSeller(system1);
			}
			else
			{
				cout << "no seller at the system, try later" << endl;
			}
			break;
		case 4:// and SellerAndBuyer
			addUSerToSystem(BuyerOrSeller::BuyerAndSeller, system1);
			break;
		case 5:  // add feedback to seller 
			addFeedBackToSEller(system1);
			break;
		case 6: // add prodcut to cart of buyer 
			addPRoductToCartOfBuyer(system1);
			break;
		case 7: // exe oreder to buyer
			executrOrderForBuyer(system1);
			break;
		case 8: // pay for order 
			payForOrder(system1);
			break;
		case 9:// show all buyers 
			system1->showAllUsers(BuyerOrSeller::buyer);
			break;
		case 10: // show all sellers 
			system1->showAllUsers(BuyerOrSeller::seller);
			break;
		case 11: // show all prodcuts with spcefic name 
			showAllPrdcsWithSpecifName(system1);
			break;
		case 12:
			showAllUsersWithSpecType(system1);
			break;
		case 13:
			comparToBuyersCartTotalPrice(system1);
			break;
		case 14:  //use the operator << in class Date
			useTheOperatorDate();
			break;
		case 15:  //use the operator << in class Address
			useTheOperatorAddress();
			break;
		case 16:  //use the operator << in class Product
			useTheOperatorProduct();
			break;
		case 17:
			//system1->saveUsers();
			menuIndex = 17;
		
			//free internal things 
			break;

	
			break;
		default:
			break;
		}
	}
	delete system1;
	cout << "Bye bye" << endl;
	return 0;
}


void comparToBuyersCartTotalPrice(System* system1) 
{
	string pName1="chair";
	string pName2 = "Table";

	string  name1 = "Omer";
	string  name2="Dani";
	string ps="11111111";

	Address ad;
	Buyer buyer1(name1, ps, ad);
	Buyer buyer2(name2, ps, ad);
	Seller seller(name1, ps, ad);
	Product p1(pName1, (Category)0, 59.99, seller);
	Product p2(pName2, (Category)0, 99.99, seller);

	buyer1.getCart()->addProductToCart(&p1);
	cout << endl << "Omer cart is:" << endl << p1;
	buyer2.getCart()->addProductToCart(&p2);
	cout << endl << "Dani cart is:" << endl << p2;


	if (buyer1 > &buyer2)
		cout << name1 << " cart is bigger" << endl;
	else
		cout << name2 << " cart is bigger" << endl;
}


void showAllUsersWithSpecType(System* system1) 
{
	int index;

	cout << "please enter type, 1- buyer, 2 - seller, 3- sellerAndBuyer " << endl;
	cin >> index;
	switch (index)
	{
	case 1:
		system1->showAllUsers(BuyerOrSeller::buyer);
		break;
	case 2:
		system1->showAllUsers(BuyerOrSeller::seller);
		break;
	case 3:
		system1->showAllUsers(BuyerOrSeller::BuyerAndSeller);
		break;
	default:
		break;
	}

}

void useTheOperatorDate()
{

	Date* datePtr = createDate();
	cout << *datePtr;
	delete datePtr;
}

void useTheOperatorAddress()
{
	
	Address* adPtr = addressInput();
	cout << *adPtr;
	delete adPtr;
}

void useTheOperatorProduct()
{
	
	string name="Bamba";

	Seller seller;
	Product prdct(name, (Category)0, 55.5, seller);
	cout << prdct;
}

void showAllPrdcsWithSpecifName(System* system1) 
{
	bool flag = false;
	string prdctName;

	cout << "enter name of product to search" << endl;
	while (flag == false)
	{
		getline(cin,prdctName);
		flag = inputValidation(prdctName, CT_ONLY_LETTERS);
		if (flag == false) {
			cout << "name could be only with letters" << endl;
		}
	}
	system1->showAllProductsWithSpecificName(prdctName, true);
}

void payForOrder(System* system1) 
{
	Buyer* buyerPtr;
	int crdit_card;

	buyerPtr = checkInputValidationAndIfBuyerExist(system1);
	bool flag;
	if (buyerPtr != nullptr)
	{
		if (buyerPtr->checkIfOrderExist())
		{
			buyerPtr->getOrder()->showOrder();
			cout << "are you sure that you want order the products?, 1- for yes,0-for no" << endl;
			cin >> flag;
			if (flag)
			{
				cout << "please enter the number on your crdet card, enter for end" << endl;
				cin >> crdit_card;
				buyerPtr->addOrderTohistoryOrders();
				buyerPtr->cleanCart();
				cout << "order finished successfully" << endl;
			}
		}
		else
		{
			cout << "order isn't exist for curr buyer, please try again" << endl;
		}
	}
	else
	{
		cout << "buyer isn't exist, please try again" << endl;
	}
}

void executrOrderForBuyer(System* system1) 
{
	int* indexArray = NULL;
	Buyer* buyerPtr;
	int numOfindex;
	buyerPtr = checkInputValidationAndIfBuyerExist(system1);
	if (buyerPtr != nullptr)
	{
		if (buyerPtr->getCart()->getNumOfProducts() != 0)
		{
			buyerPtr->getCart()->showCart(); // show all the cart to the buyer 
// get the input of buyer by string and convert it to indexArray and update to &indexArray the chooses
			convertStringToArrayOFIndex(buyerPtr->getCart()->getNumOfProducts(), &indexArray, &numOfindex);
			buyerPtr->exeOrderForBuyer(&indexArray, numOfindex);

			cout << "products move to the cart" << endl;
		}
		else
		{
			cout << "the cart is empty, please try later" << endl;
		}

	}
}

void addPRoductToCartOfBuyer(System* system1) 
{
	Buyer* buyerPtr=nullptr;
	Product* prdctPtr;
	string sellerName;

	if (system1->checkIfExistAtLeastOneProdcut())
	{
		int proudctIndex;
		buyerPtr = checkInputValidationAndIfBuyerExist(system1);
		if (buyerPtr != nullptr) 
		{
			system1->showAllProductsWithSpecificName(" ", false);
			cout << "please enter the name of seller and number of product according to the manu" << endl;
			getline(cin, sellerName);
			cin >> proudctIndex;
			if (system1->checkIfProductExist(sellerName, proudctIndex, &prdctPtr))
			{
				if (prdctPtr != nullptr && buyerPtr != nullptr && !buyerPtr->checkIfProductExistInMyCart(prdctPtr))
				{
					buyerPtr->getCart()->addProductToCart(prdctPtr);
				}
				else
				{
					cout << "problem with the product please try again or product alreay at the cart" << endl;
				}
			}
		}
		else
		{
			cout << "no prodcuts in the system please try again later" << endl;
		}
	}
		
}

void addFeedBackToSEller(System* system1) 
{
	string userName;
	Buyer* buyerPtr=nullptr;
	Seller* sellerPtr = nullptr;
	FeedBack* newFeedback;

	cout << "you choose to add  feedback on seller" << endl;
	cout << "enter name of buyer please" << endl;
	getline(cin, userName);
	system1->checkIfUserExists(userName, BuyerOrSeller::buyer, &buyerPtr);
	if (buyerPtr != nullptr)
	{
		cout << "plese enter the name of the seller that you on writh feedback on" << endl;
		getline(cin, userName);
		system1->checkIfUserExists(userName, BuyerOrSeller::seller, nullptr, &sellerPtr);
		if (sellerPtr != nullptr)
		{
			if (buyerPtr->checkIFcanWrithFeedBAckOnSeller(sellerPtr->getUserName()))
			{
				//creat feedback
				newFeedback = createFeedBack(buyerPtr);
				sellerPtr->addFeedBack(newFeedback);
			}
			else
			{
				cout << "you can't write feedback on a seller that you never bought from him" << endl;
			}
		}
	}
	else
	{
		cout << "this buyer isn't exist in the system,please try again" << endl;
	}
}

// 1,2,4 in the menu
void addUSerToSystem(BuyerOrSeller userKind,System* system1)
{
	string city;
	string street;
	int houseNum;
	int zipcode;

	string userName;
	Seller* newSeller;
	Buyer* newBuyer;
	SellerAndBuyer* newSellerAndBuyer;
	Address* newUserAdr;
	string password;

	// 1 in the menu 
	if (userKind == BuyerOrSeller::buyer) 
	{
		cout << "you choose to add buyer" << endl;
		// taking all the inputs from the keyboard
		userInput(city, street, houseNum, zipcode, userName, password, system1, BuyerOrSeller::buyer);
		newUserAdr = new Address(street,city, houseNum, zipcode);
		newBuyer = new Buyer(userName, password, *newUserAdr);
		*system1 += newBuyer;
		//cout << newUserAdr;
		delete newUserAdr;

	} // 2 in the menu 
	else if(userKind == BuyerOrSeller::seller)
	{
		cout << "you choose to add seller" << endl;
		userInput(city, street, houseNum, zipcode, userName, password, system1, BuyerOrSeller::seller);
		newUserAdr = new Address(street, city, houseNum, zipcode);
		newSeller = new Seller(userName, password, *newUserAdr);
		*system1 += newSeller;
		//system1->showAllUsers(BuyerOrSeller::seller);

	}// 12 in the menu 
	else if(userKind== BuyerOrSeller::BuyerAndSeller)
	{
		cout << "you choose to add sellerAndBuyer" << endl;
		userInput(city, street, houseNum, zipcode, userName, password, system1, BuyerOrSeller::BuyerAndSeller);
		newUserAdr = new Address(street, city, houseNum, zipcode);
		newSellerAndBuyer = new SellerAndBuyer(userName, password, *newUserAdr);
		*system1 += newSellerAndBuyer;
	}
	
}

// show the menu options 
void showMenu()
{
	cout<< endl;
	cout << "1-to add buyer" << endl;
	cout << "2-to add seller" << endl;
	cout << "3-to add product to seller" << endl;
	cout << "4-to add buyer_seller" << endl;
	cout << "5-to add feedback to seller" << endl;
	cout << "6-to add product to buyers cart" << endl;
	cout << "7-to execut order for buyer" << endl;
	cout << "8-to pay buyers order" << endl;
	cout << "9-to show all buyers details " << endl;
	cout << "10-to show all seller details " << endl;
	cout << "11-to show all products with specific name" << endl;
	cout << "12-to show all user with specific type"<< endl;
	cout << "13-to compare buyers carts total price"<< endl;
	cout << "14-to use the operator << in class Date" << endl;
	cout << "15-to use the operator << in class Address" << endl;
	cout << "16-to use the operator << in class Product" << endl;
	cout << "17-to exit" << endl;
	cout << endl;
}
//create a feedback (handle the feedback user input) and return the new feedback   
FeedBack* createFeedBack(Buyer* buyerPtr)
{
	string verbalAssesment;
	Date* datePtr = createDate();
	cout << "please enter your verbal aseesment notice, you limitid to " << MAX_FEEDBACK_LEGNTH << " charcters" << endl;
	getline(cin, verbalAssesment);
	FeedBack* feedbackPtr = new FeedBack(buyerPtr, datePtr, verbalAssesment);
	return feedbackPtr;
}

//getting the data from the user and create date and return pointer to date. 
Date* createDate()
{
	int year=2030;
	int month=-1;
	int day=-1;

	cout << "please enter the date of today" << endl;
	while (day <= 0 || day > 31)
	{
		cout << "please enter the day: " << endl;
		cin >> day;
	}
	while (month <= 0 || month > 12)
	{
		cout << "please enter the month: " << endl;
		cin >> month;
	}
	while (year <= 1000 || year > 2025)
	{
		cout << "please enter the year, 4 digits: " << endl;
		cin >> year;
	}
	Date * datePtr = new Date(day, month, year);
	cin.ignore();


	return datePtr;
}

 //6 check if user name is valid and if already exist 
Buyer* checkInputValidationAndIfBuyerExist(System* system1)
{
	Buyer* buyerPtr = nullptr;
	string nameOfUser;
	bool flagUser = false;
	bool flagInput = false;

	while (flagUser==false)
	{

		cout << "enter the name of the buyer please" << endl;
		getline(cin, nameOfUser);
		//check if buyer exist and if valid name 
		flagUser =  system1->checkIfUserExists(nameOfUser, BuyerOrSeller::buyer, &buyerPtr);
		flagInput = inputValidation(nameOfUser, CT_ONLY_LETTERS);

		if (!flagUser) 
		{
			cout << "the user isn't exist" << endl;
			break;
		}
		if (!flagInput)
		{
			cout << "the userName  invalid" << endl;
			break;
		}

	}

	return buyerPtr;
}

Address* addressInput()
{
	string street;
	string city;
	int houseNum, zipcode;
	
	bool flagInputCorrect = false;

	// check the city input
	while (!flagInputCorrect)
	{
		cout << "Enter your city please: " << endl;
		getline(cin,city);
		flagInputCorrect = inputValidation(city, CT_ONLY_LETTERS);
	}
	flagInputCorrect = false;
	//check the street input
	while (!flagInputCorrect)
	{
		cout << "Enter your street please: " << endl;
		getline(cin, street);
		flagInputCorrect = inputValidation(street, CT_ONLY_LETTERS);
	}
	flagInputCorrect = false;
	// check the house number 
	while (!flagInputCorrect)
	{
		cout << "Enter your house number please : " << endl;
		cin >> houseNum;
		if (houseNum < 0 || houseNum>1000)
			flagInputCorrect = false;
		else
			flagInputCorrect = true;
	}
	flagInputCorrect = false;
	// check the zipcode 
	while (!flagInputCorrect)
	{
		cout << "Enter your zipcode please: " << endl;
		cin >> zipcode;
		if (zipcode < 0)
			flagInputCorrect = false;
		else
			flagInputCorrect = true;
	}
	flagInputCorrect = false;
	Address* newAddress = new Address(street, city, houseNum, zipcode);
	return newAddress;
}


// get the input from the user and create a prodcut, and add to a specific seller
void addProductToSeller(System* system) 
{
	bool isExist = false;
	Seller* sellerPtr=nullptr;

	cout << "enter the name of the seller please " << endl;
	string existSeller;
	while (!isExist) 
	{
		getline(cin, existSeller);
		// check if exists and if it does update the sellerPtr to the seller
		isExist = system->checkIfUserExists(existSeller, BuyerOrSeller::seller,nullptr,&sellerPtr);
		if (!isExist)
		{
			cout << "there is no seller with this name " << existSeller << "please try again" << endl;
		}
	}
	cout << "please insert the product details: " << endl;
	Product* newProduct = productInput(sellerPtr);
	sellerPtr->addPrdctToSeller(newProduct);
	cout << "product added to seller" << endl;	
}

// check the user input for a product. create a new product and return pointer to this new product 
Product* productInput(Seller* seller) 
{
	string name;
	double price;
    Category category;
	bool validInput = false;
	int categoryIndex;

	// get the name of the product and check if the name is valid 
	while (!validInput)
	{
		cout << "please enter the name of the product" << endl;
		getline(cin, name);
		validInput = inputValidation(name, CT_ONLY_LETTERS)&& !seller->checkIfProductExist(name);
		if (!validInput)
			cout << "please try again" << endl;
	}	
	validInput = false;
	// check the price input 
	while (!validInput)
	{
		cout << "please enter the price of the product" << endl;
		cin >> price;
		if (price < 0) 
		{
			validInput = false;
			cout << "price should be a positive number, please try again" << endl;
		}
		else
		{
			validInput = true;
		}
	}
	validInput = false;
	// check the category 
	while (!validInput)
	{
		cout << "please choose category:  0 - Kids, 1-Electricity, 2- Office, 3- Clothing " << endl;
		cin >> categoryIndex;
		if (categoryIndex == 0 || categoryIndex == 1 || categoryIndex == 2 || categoryIndex == 3) {
			validInput = true;
			category = (Category)categoryIndex; // convert from int to Category (enum)
		}
		else
		{
			cout << "you entered a wrong index, please try again" << endl;
			validInput = false;
		}
	}
	Product* newProduct = new Product(name, category, price,*seller);
	return newProduct;
}

// handles all the inputs from the user 
void userInput(string& city, string& street, int& houseNum, int & zipcode, string& userName, string& password,System* system, BuyerOrSeller user)
{
	bool flagInputCorrect=false;

	cout << " NOTICE : all inputs are a maximum of 25 characters"<< endl;


	// check the city input
	while (!flagInputCorrect) 
	{
		cout << "Enter your city please: " << endl;
		getline(cin, city);
		flagInputCorrect =inputValidation(city, CT_ONLY_LETTERS);
	}
	flagInputCorrect = false;
	//check the street input
	while (!flagInputCorrect)
	{
		cout << "Enter your street please: " << endl;
		getline(cin, street);
		flagInputCorrect = inputValidation(street, CT_ONLY_LETTERS);
	}
	flagInputCorrect = false;
	// check the house number 
	while (!flagInputCorrect)
	{
		cout << "Enter your house number please : " << endl;
		cin >> houseNum;
		if (houseNum < 0 || houseNum>1000)
			flagInputCorrect = false;
		else
			flagInputCorrect = true;
	}
	flagInputCorrect = false;
	// check the zipcode 
	while (!flagInputCorrect)
	{
		cout << "Enter your zipcode please: " << endl;
		cin >> zipcode;
		if (zipcode < 0 )
			flagInputCorrect = false;
		else
			flagInputCorrect = true;
	}
	flagInputCorrect = false;
	bool isExist = true;
	// check the userName 
	cin.ignore();
	while (!flagInputCorrect || isExist) 
	{
		cout << "Enter username: " << endl;
		getline(cin, userName);
		isExist = system->checkIfUserExists(userName,user);
		if (isExist) {
			cout << "this userName already exists, please try again " << endl;
		}
		flagInputCorrect = inputValidation(userName, CT_ONLY_LETTERS);
	}
	flagInputCorrect = false;
	// check the passWord
	while (!flagInputCorrect) {
		cout << "Enter password: " << endl;
		getline(cin, password);
		flagInputCorrect = inputValidation(password, CT_ONLY_LETTERS_AND_DIGITS);
	}
}

// check the user input 
bool inputValidation(string string, checkType indecation)
{
	bool flag = true;
	int wordLength = string.size();

	if (indecation == CT_ONLY_LETTERS_AND_DIGITS) // digits and letters 
	{
		if (wordLength < PASS_MINIMUM) {
			cout << "passWord  should be at least 8 character" << endl;
			return false;
		}
		if (string.find(' ')!=-1)
			return false;
	}
	else if (indecation == CT_ONLY_LETTERS) // only letters 
	{
			if (wordLength < MINIMUM_NAME)
			{
				cout << "The name should contain at least 3 charcters,please try again" << endl;
				return false;
			}
	}
	return flag;
}

// convert string that represents the users inputs to an array of indexes 
void convertStringToArrayOFIndex(int numOfProduct, int** indexArray,int* numOfindex)
{
	int i = 0;
	char *userChoices = NULL;
	
	userChoices = new char[numOfProduct * 2 + 1];

	cout << "choose your products by typing the number of the product and pressing the space button between each product" << endl;
	cout<<"to finish press enter" << endl;
	cin.getline(userChoices, numOfProduct*2+1);
	int  stirngInputLength = strlen(userChoices);
	
	if (stirngInputLength == 1)  
	{
		*indexArray = new int[1];
		*indexArray[0] = atoi(userChoices);
		*numOfindex = 1;
	}
	else
	{
		*indexArray = new int[stirngInputLength + 1];
		char* token = strtok(userChoices, " ");
		while (token != NULL)
		{
			int tokenInt = atoi(token);
			if (tokenInt<0 || tokenInt>numOfProduct)
			{
				cout << "invalid input" << endl;
				break;
			}
			(*indexArray)[i++] = tokenInt;
			token = strtok(NULL, " ");
		}
		*numOfindex = i;
	
	}
	delete[] userChoices; // free the userchoices 
}

