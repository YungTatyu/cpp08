#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
private:
  std::vector<int> numbers_;
  unsigned int max_capacity_;
  unsigned int shortest_span_;
  unsigned int longest_span_;
  const static int kNumRequiredElement_ = 2; // spanの計算に必要な最低要素数
  Span();

public:
  Span(unsigned int N);
  Span(const Span &other);
  virtual ~Span();
  Span &operator=(const Span &other);
  void addNumber(int num);
  void addNumber(int begin, int end);
  const unsigned int &shortestSpan() const;
  const unsigned int &longestSpan() const;
};

#endif
