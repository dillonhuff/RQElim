#include <iomanip>
#include <iostream>

#include "test/TestUtils.h"

namespace RQElim {
  
  void testAssertion(bool assertion, std::string testName) {
    std::cout << std::setw(50) << std::left << testName;
    std::cout << " ";
    if (assertion) {
      std::cout << std::setw(10) << std::left << " passed" << std::endl;
    } else {
      std::cout << std::setw(10) << " FAILED" << std::endl;
    }
  }

}
