#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Buyer.h"
#include "Date.h"
using namespace std;

class Buyer;
static const int MAX_FEEDBACK_LEGNTH = 90;

class FeedBack
{
    private:
	Buyer* buyerFB;
	Date* dateFB;
	string vrtbalAssesment;

public:
	FeedBack(Buyer*buyerPtr, Date* datePtr, string verbalAssesment);
	FeedBack(const FeedBack& feedBack);
	~FeedBack();
};
