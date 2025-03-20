#include "./Span.hpp"

int main()
{
	Span empty;

	try
	{
		empty.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Span one(1);

	one.addNumber(1);
	try
	{
		one.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		one.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Span A(10);
	
	A.addNumber(1);
	A.addNumber(6);
	A.addNumber(21);
	A.addNumber(100);
	A.addNumber(4);
	A.addNumber(43);
	A.addNumber(90);
	A.addNumber(56);
	A.addNumber(32);
	A.addNumber(7);

	std::cout << A.shortestSpan() << std::endl;
	std::cout << A.longestSpan() << std::endl;
}