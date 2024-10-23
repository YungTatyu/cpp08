#include "Span.hpp"
#include <stdexcept>

Span::Span(unsigned int N)
    : max_capacity_(N), shortest_span_(0), longest_span_(0) {}

Span::~Span() {}

Span::Span(const Span &other) { operator=(other); }

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    this->numbers_ = other.numbers_;
    this->max_capacity_ = other.max_capacity_;
    this->shortest_span_ = other.shortest_span_;
    this->longest_span_ = other.longest_span_;
  }
  return *this;
}

void Span::addNumber(int num) {
  if (numbers_.size() >= max_capacity_)
    throw std::runtime_error("there is no capacity left in Span");

  // sizeが0の時は、spanの計算をしない
  if (numbers_.size() == 0) {
    numbers_.push_back(num);
    return;
  }
  const int second_last_element = numbers_.back();
  numbers_.push_back(num);

  // spanの絶対値を取得
  const unsigned int span = num >= second_last_element
                                ? num - second_last_element
                                : second_last_element - num;

  if (span == 0)
    return;
  if (shortest_span_ == 0) {
    shortest_span_ = span;
    longest_span_ = span;
    return;
  }
  if (span < shortest_span_)
    shortest_span_ = span;
  if (span > longest_span_)
    longest_span_ = span;
}

void Span::addNumber(int begin, int end) {
  while (begin <= end) {
    addNumber(begin);
    begin++;
  }
}

const unsigned int &Span::shortestSpan() const {
  if (numbers_.size() < kNumRequiredElement_)
    throw std::runtime_error("there is not enough elements to caluculate span");
  if (shortest_span_ == 0)
    throw std::runtime_error("there is no span between elements");
  return shortest_span_;
}

const unsigned int &Span::longestSpan() const {
  if (numbers_.size() < kNumRequiredElement_)
    throw std::runtime_error("there is not enough elements to caluculate span");
  if (longest_span_ == 0)
    throw std::runtime_error("there is no span between elements");
  return longest_span_;
}
