#ifndef __RQELIM_POLYNOMIAL_H__
#define __RQELIM_POLYNOMIAL_H__

#include <vector>

#include "src/Monomial.h"

namespace RQElim {

  class Polynomial {
    std::vector<Monomial> terms;
    
  public:
    Polynomial(std::vector<Monomial> ts)
      : terms(ts) {}

    inline int numTerms() const { return terms.size(); }

    bool operator==(const Polynomial& other) const {
      if (numTerms() != other.numTerms()) {
	return false;
      }
      for (int i = 0; i < numTerms(); i++) {
	if (terms[i] != other.terms[i]) {
	  return false;
	}
      }
      return true;
    }

    bool operator!=(const Polynomial& other) const { return !(*this == other); }

    Polynomial derivative(int var) {
      std::vector<Monomial> derivTerms;
      for (auto term : terms) {
	auto termDeriv = term.derivative(var);
	if (!termDeriv.isZero()) {
	  derivTerms.push_back(termDeriv);
	}
      }
      return Polynomial(derivTerms);
    }

    friend std::ostream& operator<<(std::ostream& stream, const Polynomial& p) {
      for (int i = 0; i < p.numTerms(); i++) {
	stream << p.terms[i];
	if (i != p.numTerms() - 1) {
	  stream << " + ";
	}
      }
      return stream;
    }
  };
}

#endif
