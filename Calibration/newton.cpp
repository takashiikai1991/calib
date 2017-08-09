

#include "newton.h"

namespace newton {

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

	const double BS::calcDminus() {
		double logPart = log(_init / _strike);
		double dtPart = (_r - _vol*_vol / 2)*_tau;
		double denom = _vol*sqrt(_tau);

		_dminus = (logPart + dtPart) / denom;
		return (logPart + dtPart) / denom;
	};

	const double BS::getDminus() {
		return _dminus;
		//return _dplus - _vol*sqrt(_tau);
	}


	const double BS:: newton(const double& precision) {
		
		return 0;
	};



	const double BS::calcPV() {
		
		return 0;

	};


	const double BS::calcVol() {
		return 0;
	
	};



}