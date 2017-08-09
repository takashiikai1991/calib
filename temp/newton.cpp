
#include "newton.h"

namespace newton {


	BS::BS(const double& Expiry,
		const double& Strike,
		const double& Spot,
		const double& Vol,
		const double& r)
		: _tau(Expiry), _strike(Strike) ,
		 _init(Spot), _vol(Vol), _r(r)
	{}

	const double BS::calcPV() {
		return calcStandardCallPrice( _tau , _strike , _init , _vol , _r );
	};

	const double BS::calibrateVol(const double& initVol, const double& targetPrice, const double& precision) {
		const size_t maxloop = 200;

		double iiVol = initVol; // = _vol?
		double calibratedVol = 0;

		for (size_t ii = 0; ii < maxloop; ++ii) {
			const double price = calcStandardCallPrice(_tau, _strike, _init, iiVol, _r);
			const double deriv = this->derivVol(iiVol, precision);
			double newVol = (targetPrice - price) / deriv + initVol;

			if (std::fabs(newVol - iiVol) > precision) {
				iiVol = newVol;
				continue;
			}
			else {
				calibratedVol = iiVol;
				break;
			}

		}//for

		return calibratedVol;
	};



	const double BS::derivVol(const double initVol , const double precision) {
		const double vol1 = initVol*(1 + precision/2);
		const double vol2 = initVol*(1 - precision/2);
		const double pv1 = calcStandardCallPrice(_tau, _strike, _init, vol1, _r);
		const double pv2 = calcStandardCallPrice(_tau, _strike, _init, vol2, _r);
		return (pv1-pv2)/precision;
	};

	/*
	Newton Rapson method	
	*/

	const double BS::calcStandardCallPrice(
		const double Expiry,
		const double Strike,
		const double Spot,
		const double Vol,
		const double r) {

		//	double dp = calcDplus();
		double logPart = log(Spot / Strike);
		double dtPart = (r - Vol*Vol / 2)*Expiry;
		double denom = Vol*sqrt(Expiry);

		double dm = (logPart+dtPart)/denom;
		double dp = dm + Vol*sqrt(Expiry);

		//double price = Spot*CDF(dp) + std::exp(-1 * r*Expiry)*Strike*CDF(dm);
		
		return 0;
	}



}