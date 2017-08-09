#pragma once


#include <vector>
#include <string>
#include <iostream>

namespace newton {
	class BS{
	public:
		const double calcPV();

		const double calcDplus();
		const double calcDminus();
		const double getDplus();
		const double getDminus();

		const double calcVol();
		const double getVol();

		const double newton(const double& precision);



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


