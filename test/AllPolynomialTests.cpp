#include <vector>

#include "src/Polynomial.h"
#include "test/AllPolynomialTests.h"
#include "test/TestUtils.h"

namespace RQElim {

  void equivalenceTestFail() {
    std::vector<int> d1;
    d1.push_back(2);
    d1.push_back(5);
    std::vector<Monomial> t1;
    t1.push_back(Monomial(Rational(3,2), d1));
    Polynomial p1(t1);

    std::vector<int> d2;
    d2.push_back(4);
    d2.push_back(0);
    std::vector<Monomial> t2;
    t2.push_back(Monomial(Rational(4,2), d2));
    Polynomial p2(t2);

    testAssertion(p1 != p2, "equivalenceTestFail");
  }

  void oneTermDerivative() {
    std::vector<int> d;
    d.push_back(3);
    d.push_back(7);
    d.push_back(0);
    std::vector<Monomial> terms;
    terms.push_back(Monomial(Rational(2, 1), d));
    Polynomial p(terms);
    auto derivative = p.derivative(0);

    std::vector<int> c;
    c.push_back(2);
    c.push_back(7);
    c.push_back(0);
    std::vector<Monomial> derivTerms;
    derivTerms.push_back(Monomial(Rational(6, 1), c));
    Polynomial correct(derivTerms);

    testAssertion(correct == derivative, "oneTermDerivative");
  }
  
  void allPolynomialTests() {
    equivalenceTestFail();
    oneTermDerivative();
    return;
  }

}
