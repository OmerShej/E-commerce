#include "FeedBack.h"


FeedBack::FeedBack(Buyer*buyerPtr, Date* datePtr, string verbalAssesment) 
{
	this->buyerFB = buyerPtr;
	this->dateFB = datePtr;
	this->vrtbalAssesment = verbalAssesment;
}
FeedBack::FeedBack(const FeedBack& feedBack)
{
	this->buyerFB = feedBack.buyerFB;
	this->dateFB = feedBack.dateFB; // shallow copy cause no allocating 
	this->vrtbalAssesment = feedBack.vrtbalAssesment;
}

FeedBack::~FeedBack()
{
	if (this->dateFB != nullptr)
		delete this->dateFB;
}