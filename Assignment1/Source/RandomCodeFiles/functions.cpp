#include "functions.h"
#include "CommonHeader.h"

int CreateRandomNumber(int minimumValue, int maximumValue ) 
{
	RandomNumberGenerator RNG(minimumValue , maximumValue);// allows us to use the number generator and make it so we can set it as two numbers

	int randomNumber = 0;
	RNG.Generate(randomNumber);

	return randomNumber;

}

double CreateRandomNumber(double minimumValue, double maximumValue )
{
	RandomNumberGenerator RNG(minimumValue , maximumValue);

	int randomNumber = 0;
	RNG.Generate(randomNumber);

	return randomNumber;

}
