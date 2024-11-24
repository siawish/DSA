#pragma once
class Term
{
public:
	int cofficient;
	int exponent;
	bool sign;
	Term* next;
	Term(int cofficient, int exponenet=0) : cofficient(abs(cofficient)) , exponent(exponent) , next(NULL){
	
		sign = (cofficient >= 0);

	}
	Term() {}
};

