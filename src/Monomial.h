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

    bool operator==(const Monomial& other) const {
      if (numVars() != other.numVars()) {
	std::cout << "Error: == of 2 monomials with different "
		  << "numbers of variables" << std::endl;
	throw;
      }
      if (coefficient != other.coefficient) {
	return false;
      }
      for (int i = 0; i < numVars(); i++) {
	if (multidegree[i] != other.multidegree[i]) {
	  return false;
	}
      }
      return true;
    }

    inline bool operator!=(const Monomial& other) const { return !(*this == other); }

    Comparison lexCmp(const Monomial& other) const {
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

    inline bool isZero() const {
      return coefficient.isZero();
    }

    std::vector<int> derivativeMultidegree(int var) const {
      std::vector<int> derivMD;
      for (int i = 0; i < numVars(); i++) {
	if (multidegree[i] == 0) {
	  derivMD.push_back(0);
	} else if (i == var) {
	  derivMD.push_back(multidegree[i] - 1);
	} else {
	  derivMD.push_back(multidegree[i]);
	}
      }
      return derivMD;
    }

    Monomial derivative(int var) {
      if (multidegree[var] == 0) {
	return Monomial(Rational(0, 1), multidegree);
      }
      auto rVal = Rational(multidegree[var], 1);
      auto resultCoeff = rVal * coefficient;
      auto derivMultidegree = derivativeMultidegree(var);
      return Monomial(resultCoeff, derivMultidegree);
    }

    friend std::ostream& operator<<(std::ostream& stream, const Monomial& m) {
      stream << m.coefficient;
      for (int i = 0; i < m.numVars(); i++) {
	stream << "x_" << i << "^" << m.multidegree[i] << " ";
      }
      return stream;
    }

  };

  struct MonomialLessThan {
    inline bool operator()(const Monomial& m1, const Monomial& m2) const {
      return m1.lexCmp(m2) == LT;
    }
  };
}
#endif
