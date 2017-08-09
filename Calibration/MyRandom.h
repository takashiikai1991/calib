#pragma once

#include <iostream>
#include <cmath>
#include <vector>

namespace myRand {
	class ran {
	public:

		ran(const double& mean, const double& sigma)
			: _mean(mean), _sigma(_sigma)
			, _mean2(0)  , _sigma2(1)

		{}
		ran(const double& mean , const double& sigma,
			const double& mean2, const double& sigma2)
			: _mean(mean), _sigma(_sigma)
			, _mean2(mean2), _sigma2(_sigma2)
		{}

		const double pi = 3.14159;

		const vector<double>& get2DGaussian()
		{
			//generate random values
			const double ran1 = 0.5; //between 0~1
			const double ran2 = 0.5; //between 0~1

			const double radius = sqrt(-2 * log(ran1));
			const double theta = ran2 * 2 * pi;

			const double x = radius /_sigma  * sin(theta) + _mean;
			const double y = radius /_sigma2 * cos(theta) + _mean2;

			const vector < double > output{ x, y };
			return output;
		}
		
	private:
		int _num;
		double _mean;
		double _sigma;
		double _mean2;
		double _sigma2;
		
	};



}