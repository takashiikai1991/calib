#pragma once

#include <iostream>
#include <cmath>
#include <vector>

namespace myRand {
	class ran {
	public:

		ran(const double& mean , const double& sigma)
			: _mean(mean) , _sigma(_sigma)
		{}


		const double pi = 3.14159;

		const vector<double> get2DGaussian()
		{
			//generate random values
			const double ran1 = 0.5; //between 0~1
			const double ran2 = 0.5; //between 0~1

			const double radius = sqrt(-2 * _sigma*_sigma * log(1 - ran1));
			const double theta = ran2 * 2 * pi;

			const double x = radius * sin(theta) + _mean;
			const double y = radius * cos(theta);
			vector < double > output{ x, y };

			return output;
		}



	private:
		int _num;
		double _mean;
		double _sigma;





	};



}