#include "CommonHeader.h"

#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator(const int maxValue)  :
	 m_CurrentRandomNumber(0),  m_CurrentDecimalRandomNumber(0.0) ,
	  m_UniformDistribution( 1 , maxValue)

{
	std::random_device rd;
	m_MT.seed(rd());
}
RandomNumberGenerator::RandomNumberGenerator(const int minValue ,
	const int maxValue)  :
	 m_CurrentRandomNumber(0),  m_CurrentDecimalRandomNumber(0.0) ,
	  m_UniformDistribution( minValue ,  maxValue )
{
	std::random_device rd;
	m_MT.seed(rd());
}

RandomNumberGenerator::	RandomNumberGenerator
	(const double minValue , const double maxValue) 
	:  m_CurrentRandomNumber(0),
	m_CurrentDecimalRandomNumber(0.0) ,
	m_UniformDistributionDecimal(minValue , maxValue)
{
	// note: the uniform_int_distribution will use its default constructor so it does not need to be initialized
	std::random_device rd;
	m_MT.seed(rd());
}



// overloaded method definitions note: all pass by reference

void RandomNumberGenerator::Generate(int & randomNumber)
{
	m_CurrentRandomNumber = m_UniformDistribution(m_MT);
	randomNumber = m_CurrentRandomNumber;
}

void RandomNumberGenerator::Generate(double & randomNumber)
{
	m_CurrentDecimalRandomNumber = m_UniformDistributionDecimal(m_MT);
	randomNumber = m_CurrentDecimalRandomNumber;
}

void RandomNumberGenerator::GetCurrentRandomNumber(int & randomNumber)
{
	randomNumber = m_CurrentRandomNumber;
}

void RandomNumberGenerator::GetCurrentRandomNumber(double & randomNumber)
{
	randomNumber = m_CurrentDecimalRandomNumber;
}
