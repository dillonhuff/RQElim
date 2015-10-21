#ifndef __RQELIM_RATIONAL_H__
#define __RQELIM_RATIONAL_H__


namespace RQElim {
  
  // Horrible temporary fill in for a real big num implementation
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

    inline bool isZero() const {
      return numerator == 0;
    }

    Rational operator*(const Rational other) const {
      return Rational(numerator*other.numerator, denominator*other.denominator);
    }

    friend std::ostream& operator<<(std::ostream& stream, const Rational& r) {
      if (r.denominator == 0) {
	stream << r.numerator;
      } else {
	stream << "(" << r.numerator << "/" << r.denominator << ")";
      }
      return stream;
    }
  };

}
#endif
