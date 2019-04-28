#ifndef __RandomNumberGenerator_H__
#define __RandomNumberGenerator_H__


#include <random>


class RandomNumberGenerator
{
private: // required data members are all private
	int m_CurrentRandomNumber;
	double m_CurrentDecimalRandomNumber;

	std::mt19937 m_MT;
	std::uniform_int_distribution<int>
		m_UniformDistribution;
	std::uniform_real_distribution<double>
		m_UniformDistributionDecimal;

public:
	RandomNumberGenerator(const int maxValue);
	RandomNumberGenerator(const int minValue ,
		const int maxValue);

	RandomNumberGenerator(const double minValue ,
		const double maxValue);

	// overloaded method declarations note: 
	// all pass by reference
	void Generate(int & randomNumber);
	void Generate(double & randomNumber);

	void GetCurrentRandomNumber(int & randomNumber);
	void GetCurrentRandomNumber(double & randomNumber);

};

#endif //__RandomNumberGenerator_H__