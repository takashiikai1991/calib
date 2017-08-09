#pragma once

#include <vector>
#include <string>
#include <iostream>

namespace newton {
	class BS{
	public:
		//present value
		const double calcPV();

		//estimate d+-
		const double calcDplus();
		const double calcDminus();
		const double getDplus();
		const double getDminus();

		//calibration volatility
		const double calcVol(const double initVol, const double precision);
		const double getVol();

	private:
		//for calibration 
		const double calibrateVol(const double vol, const double precision);
	
		const double newton(const double& precision);

		const double derivative(const double& precision);

		const double calcStandardCallPrice(	
			double Expiry,
			double Strike,
			double Spot,
			double Vol,
			double r );


	private:
		double& _dplus;
		double& _dminus;

		const double& _tau;
		const double& _r;
		const double& _vol;
		const double& _strike;
		const double& _init;

		double& _tauCalculated;
		double& _rCalculated;
		double& _volCalculated;
		double& _strikeCalculated;
		double& _initCalculated;
			
	};


}


