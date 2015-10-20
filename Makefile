CC := clang++
CXX_FLAGS := -std=c++11 -I.

SRCS := test/AllTests.cpp test/AllMonomialTests.cpp test/TestUtils.cpp
HEADERS := test/AllMonomialTests.h src/Rational.h src/Monomial.h

rqelim-tests: $(SRCS) $(HEADERS)
	$(CC) $(CXX_FLAGS) $(SRCS) -o $@

clean:
	rm -f rqelim-tests
