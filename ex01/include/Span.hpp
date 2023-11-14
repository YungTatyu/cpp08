#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
private:
	std::vector<int>	_nums;
	unsigned int	_num_stored;
	unsigned int	_shortest_span;
	unsigned int	_longest_span;
	Span();
public:
	Span(unsigned int N);
	Span(const Span& other);
	virtual	~Span();
	Span&	operator=(const Span& other);
	void	addNumber(int num);
	void	addNumber(int begin, int end);
	const int&	shortestSpan() const;
	const int&	longestSpan() const;
};

#endif
