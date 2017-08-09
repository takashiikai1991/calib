
#include "newton.h"

namespace newton {

	const double BS::calcPV() {
		return calcStandardCallPrice( _tau , _strike , _init , _vol , _r );
		return 0;

	};

	const double BS::calibrateVol(const double vol , const double precision) {
		const double vol1 = vol*(1 + precision);
		const double vol2 = vol*(1 - precision);
		const double pv1 = 0;
		const double pv2 = 0;

		// _init* CDF(_dplus) + exp(-1*_r*_tau) * CDF(d_minus);

		return (pv1-pv2)/2/precision;

	};


	const double BS::calcVol(const double initVol , const double precision) {

		return 0;
	};

	/*
private
	calculate "d+" for range CDF (-inf,d+) 
	*/
	const double BS::calcDplus() {
		double logPart = log(_init / _strike);
		double dtPart  = (_r + _vol*_vol / 2)*_tau;
		double denom   = _vol*sqrt(_tau);

		_dplus = (logPart + dtPart) / denom;
		return (logPart+dtPart)/ denom;
	};

	const double BS::getDplus() {
		return _dplus;
	}

	/*
	calculate "d+" for range CDF (-inf,d+)
	*/
	const double BS::calcDminus() {
		double logPart = log(_init / _strike);
		double dtPart = (_r - _vol*_vol / 2)*_tau;
		double denom = _vol*sqrt(_tau);

		_dminus = (logPart + dtPart) / denom;
		return (logPart + dtPart) / denom;
	};

	const double BS::getDminus() {
		return _dminus;
	}

	/*
	Newton Rapson method	
	*/
	const double BS::newton(const double& precision) {
		
		return 0;
	};


	const double BS::derivative(const double& precision) {

		return 0;
	};




	const double BS::calcStandardCallPrice(
		double Expiry,
		double Strike,
		double Spot,
		double Vol,
		double r) {

		return 0;
	}



}