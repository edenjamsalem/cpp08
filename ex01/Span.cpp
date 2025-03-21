#include "./Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int n) : _N(n) {}

Span::Span(const Span& other)
{
	*this = other;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		*this = other;	
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (_nums.size() >= _N)
		throw ContainerFullException();
	_nums.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_nums.size() + std::distance(begin, end) > _N)
		throw ContainerFullException();
	_nums.insert(_nums.end(), begin, end);
}

int Span::shortestSpan()
{
	int shortestSpan;
	int currentSpan;

	if (_N < 2)
		throw NoSpanPossibleException();
	std::sort(_nums.begin(), _nums.end());
	shortestSpan = _nums[1] - _nums[0];
	for (unsigned int i = 1; i < _N; i++)
	{
		currentSpan = _nums[i] - _nums[i - 1];
		if (currentSpan < shortestSpan)
			shortestSpan = currentSpan;
	}
	return (shortestSpan);
}

int Span::longestSpan()
{
	if (_N < 2)
		throw NoSpanPossibleException();
	
	std::vector<int> tmp = _nums;
	std::sort(tmp.begin(), tmp.end());
	return (tmp.back() - tmp.front());
}

const char *Span::NoSpanPossibleException::what() const throw()
{
	return ("No span as less than 2 numbers stored.");
}

const char *Span::ContainerFullException::what() const throw()
{
	return ("No space left to add num.");
}
