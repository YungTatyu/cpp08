#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
private:
	std::vector<int>	_numbers;
	unsigned int	_max_capacity;
	unsigned int	_shortest_span;
	unsigned int	_longest_span;
	const static int	_kNumRequiredElement = 2; // spanの計算に必要な最低要素数
	Span();
public:
	Span(unsigned int N);
	Span(const Span& other);
	virtual	~Span();
	Span&	operator=(const Span& other);
	void	addNumber(int num);
	void	addNumber(int begin, int end);
	const unsigned int&	shortestSpan() const;
	const unsigned int&	longestSpan() const;
};

#endif
