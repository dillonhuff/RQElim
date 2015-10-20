#include <vector>

#include "src/Monomial.h"
#include "test/AllMonomialTests.h"
#include "test/TestUtils.h"

namespace RQElim {

  void lexicographicEqual() {
    std::vector<int> d1;
    d1.push_back(2);
    d1.push_back(3);
    Monomial m1(Rational(1, 1), d1);

    std::vector<int> d2;
    d2.push_back(2);
    d2.push_back(3);
    Monomial m2(Rational(2, 1), d2);

    testAssertion(m1.lexCmp(m2) == EQ, "lexicographicEqual");
  }

  void lexicographicLessThan() {
    std::vector<int> d1;
    d1.push_back(5);
    d1.push_back(0);
    d1.push_back(7);
    Monomial m1(Rational(1, 1), d1);

    std::vector<int> d2;
    d2.push_back(5);
    d2.push_back(3);
    d2.push_back(0);
    Monomial m2(Rational(2, 1), d2);

    testAssertion(m1.lexCmp(m2) == LT, "lexicographicLessThan");
  }

  void lexicographicGreaterThan() {
    std::vector<int> d1;
    d1.push_back(5);
    d1.push_back(0);
    d1.push_back(7);
    d1.push_back(12);
    Monomial m1(Rational(1, 1), d1);

    std::vector<int> d2;
    d2.push_back(5);
    d2.push_back(0);
    d2.push_back(7);
    d2.push_back(11);
    Monomial m2(Rational(2, 1), d2);

    testAssertion(m1.lexCmp(m2) == GT, "lexicographicGreaterThan");
  }
  
  void allMonomialTests() {
    lexicographicEqual();
    lexicographicLessThan();
    lexicographicGreaterThan();
    return;
  }

}
