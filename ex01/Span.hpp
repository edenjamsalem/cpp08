#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include "./Span.hpp"

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _nums;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int n);
		int shortestSpan();
		int longestSpan();

		class NoSpanPossibleException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class ContainerFullException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
