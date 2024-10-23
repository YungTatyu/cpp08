
#include "Span.hpp"
#include <climits>
#include <iostream>

int main() {
  Span span(100000);
  // std::vector<int>	v;

  // std::cout << v.back() << '\n';
  // v.push_back(1);

  std::cout << static_cast<long>(INT_MAX) - INT_MIN << '\n';
  std::cout << UINT_MAX << '\n';

  // span.addNumber(1, 10000);

  span.addNumber(INT_MIN);
  span.addNumber(INT_MAX);
  std::cout << "longest=" << span.longestSpan() << '\n';
  std::cout << "shortest=" << span.shortestSpan() << '\n';

  return 0;
}
