#ifndef __RQELIM_RATIONAL_H__
#define __RQELIM_RATIONAL_H__

namespace RQElim {
  
  class Rational {
    int numerator;
    int denominator;
    
  public:
    Rational(int num, int denom)
      : numerator(num), denominator(denom) {}

    inline bool operator==(const Rational other) const {
      return numerator == other.numerator && denominator == other.denominator;
    }

    inline bool operator!=(const Rational other) const {
      return !(*this == other);
    }
  };

}
#endif
