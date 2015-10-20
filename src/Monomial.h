#ifndef __RQELIM_MONOMIAL_H__
#define __RQELIM_MONOMIAL_H__

#include <iostream>
#include <vector>

#include "src/Rational.h"

enum Comparison { EQ, LT, GT };

namespace RQElim {

  class Monomial {
    Rational coefficient;
    std::vector<int> multidegree;
    
  public:
    Monomial(Rational coeff, std::vector<int> mdegree)
      : coefficient(coeff), multidegree(mdegree) {}

    inline int numVars() const { return multidegree.size(); }

    Comparison lexCmp(const Monomial& other) {
      if (numVars() != other.numVars()) {
	std::cout << "Error: lexCmp of 2 monomials with different "
		  << "numbers of variables" << std::endl;
	throw;
      }
      for (int i = 0; i < numVars(); i++) {
	if (multidegree[i] > other.multidegree[i]) {
	  return GT;
	} else if (multidegree[i] < other.multidegree[i]) {
	  return LT;
	}
      }
      return EQ;
    }
  };

}
#endif
