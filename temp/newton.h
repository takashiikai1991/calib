#pragma once

#include <vector>
#include <string>
#include <iostream>

namespace newton {
	class BS{
	public:

		BS(const double& Expiry,
			const double& Strike,
			const double& Spot,
			const double& Vol,
			const double& r);
		
		
		//present value
		const double calcPV();

		//calibration volatility
		//const double calcVol(const double initVol, const double precision);
		//const double getVol();

	private:
		//for calibration 
		const double calibrateVol(const double& initVol, const double& targetPrice , const double& precision);

		const double derivVol(const double vol, const double precision);

		const double newton(const double& precision);

		const double calcStandardCallPrice(	
			const double Expiry,
			const double Strike,
			const double Spot,
			const double Vol,
			const double r );


	private:

		const double& _tau;
		const double& _r;
		const double& _vol;
		const double& _strike;
		const double& _init;

		//double& _tauCalculated;
		//double& _rCalculated;
		//double& _volCalculated;
		//double& _strikeCalculated;
		//double& _initCalculated;
			
	};


}


