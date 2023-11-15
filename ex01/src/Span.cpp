#include "Span.hpp"

Span::Span(unsigned int N) : _max_capacity(N), _shortest_span(0), _longest_span(0) {}

Span::~Span() {}

Span::Span(const Span& other)
{
	operator=(other);
}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->_numbers = other._numbers;
		this->_max_capacity = other._max_capacity;
		this->_shortest_span = other._shortest_span;
		this->_longest_span = other._longest_span;
	}
	return *this;
}

void	Span::addNumber(int num)
{
	if (_numbers.size() >= _max_capacity)
		throw std::runtime_error("there is no capacity left in Span");

	// sizeが0の時は、spanの計算をしない
	if (_numbers.size() == 0)
	{
		_numbers.push_back(num);
		return;
	}
	const int	second_last_element = _numbers.back();
	_numbers.push_back(num);

	// spanの絶対値を取得
	const unsigned int	span = num >= second_last_element ? num - second_last_element : second_last_element - num;

	if (span == 0)
		return;
	if (_shortest_span == 0)
	{
		_shortest_span = span;
		_longest_span = span;
		return;
	}
	if (span < _shortest_span)
		_shortest_span = span;
	if (span > _longest_span)
		_longest_span = span;
}

void	Span::addNumber(int begin, int end)
{
	while (begin <= end)
	{
		addNumber(begin);
		begin++;
	}
}

const unsigned int&	Span::shortestSpan() const
{
	if (_numbers.size() < _kNumRequiredElement)
		throw std::runtime_error("there is not enough elements to caluculate span");
	if (_shortest_span == 0)
		throw std::runtime_error("there is no span between elements");
	return _shortest_span;
}

const unsigned int&	Span::longestSpan() const
{
	if (_numbers.size() < _kNumRequiredElement)
		throw std::runtime_error("there is not enough elements to caluculate span");
	if (_longest_span == 0)
		throw std::runtime_error("there is no span between elements");
	return _longest_span;
}
