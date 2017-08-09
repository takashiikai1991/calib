



//#include <Random1.h>
#include <iostream>
#include <cmath>
using namespace std;


#include "MyRandom.h"
#include "newton.h"


void main() {
	std::cout <<"HELLo "<< std::endl;

	const double tenor = 100/365.;
	const double strike = 100;
	const double spot = 100;
	const double vol = 0.10;
	const double rate = 0.01;

	newton::BS usdyenPrice(tenor , strike , spot, vol, rate );

	return;

}




double SimpleMonteCarlo1(double Expiry,
	double Strike,
	double Spot,
	double Vol,
	double r,
	unsigned long NumberOfPaths)
{
	double variance = Vol*Vol*Expiry;
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5*variance;
	double movedSpot = Spot*exp(r*Expiry + itoCorrection);
//	double thisSpot;
	double runningSum = 0;
	for (unsigned long i = 0; i < NumberOfPaths; i++)
	{
		//double thisGaussian = GetOneGaussianByBoxMuller();
		//thisSpot = movedSpot*exp(rootVariance*thisGaussian);
		//double thisPayoff = thisSpot - Strike;
		//thisPayoff = thisPayoff >0 ? thisPayoff : 0;
		//runningSum += thisPayoff;
	}
	double mean = runningSum / NumberOfPaths;
	mean *= exp(-r*Expiry);
	return mean;
}