/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:42:25 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/13 16:05:17 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Fixed.hpp"

#define COLOR_RESET	"\033[m"
#define COLOR_CYAN	"\033[36m"

void	print_header(const std::string &str)
{
	std::cout << COLOR_CYAN "\n[ " << str << " ]" COLOR_RESET << std::endl;
}

int main( void ) {
	print_header("subject test");

	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;


	print_header("original test");

	Fixed		c(0);
	Fixed		d(c);
	const Fixed	e(256);
	Fixed		f(-42.0f);


	print_header("Six comparison operators: >, <, >=, <=, == and !=");

	std::string	test = ">";
	print_header(test);
	std::cout << "a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;
	if (a > b)
		std::cout << "a " << test << " b: true" << std::endl;
	else
		std::cout << "a " << test << " b: not true" << std::endl;
	if (b > c)
		std::cout << "b " << test << " c: true" << std::endl;
	else
		std::cout << "b " << test << " c: not true" << std::endl;
	if (c > d)
		std::cout << "c " << test << " d: true" << std::endl;
	else
		std::cout << "c " << test << " d: not true" << std::endl;

	test = "<";
	print_header(test);
	std::cout << "a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;
	if (a < b)
		std::cout << "a " << test << " b: true" << std::endl;
	else
		std::cout << "a " << test << " b: not true" << std::endl;
	if (b < c)
		std::cout << "b " << test << " c: true" << std::endl;
	else
		std::cout << "b " << test << " c: not true" << std::endl;
	if (c < d)
		std::cout << "c " << test << " d: true" << std::endl;
	else
		std::cout << "c " << test << " d: not true" << std::endl;

	test = ">=";
	print_header(test);
	std::cout << "a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;
	if (a >= b)
		std::cout << "a " << test << " b: true" << std::endl;
	else
		std::cout << "a " << test << " b: not true" << std::endl;
	if (b >= c)
		std::cout << "b " << test << " c: true" << std::endl;
	else
		std::cout << "b " << test << " c: not true" << std::endl;
	if (c >= d)
		std::cout << "c " << test << " d: true" << std::endl;
	else
		std::cout << "c " << test << " d: not true" << std::endl;

	test = "<=";
	print_header(test);
	std::cout << "a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;
	if (a <= b)
		std::cout << "a " << test << " b: true" << std::endl;
	else
		std::cout << "a " << test << " b: not true" << std::endl;
	if (b <= c)
		std::cout << "b " << test << " c: true" << std::endl;
	else
		std::cout << "b " << test << " c: not true" << std::endl;
	if (c <= d)
		std::cout << "c " << test << " d: true" << std::endl;
	else
		std::cout << "c " << test << " d: not true" << std::endl;

	test = "==";
	print_header(test);
	std::cout << "a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;
	if (a == b)
		std::cout << "a " << test << " b: true" << std::endl;
	else
		std::cout << "a " << test << " b: not true" << std::endl;
	if (b == c)
		std::cout << "b " << test << " c: true" << std::endl;
	else
		std::cout << "b " << test << " c: not true" << std::endl;
	if (c == d)
		std::cout << "c " << test << " d: true" << std::endl;
	else
		std::cout << "c " << test << " d: not true" << std::endl;

	test = "!=";
	print_header(test);
	std::cout << "a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;
	if (a != b)
		std::cout << "a " << test << " b: true" << std::endl;
	else
		std::cout << "a " << test << " b: not true" << std::endl;
	if (b != c)
		std::cout << "b " << test << " c: true" << std::endl;
	else
		std::cout << "b " << test << " c: not true" << std::endl;
	if (c != d)
		std::cout << "c " << test << " d: true" << std::endl;
	else
		std::cout << "c " << test << " d: not true" << std::endl;


	print_header("Four arithmetic operators: +, -, *, and /");

	test = "+";
	print_header(test);
	std::cout << "a(" << std::setw(10) << a << ") " << test << " b(" << std::setw(10) << b << ") = " << a + b << std::endl;
	std::cout << "b(" << std::setw(10) << b << ") " << test << " c(" << std::setw(10) << c << ") = " << b + c << std::endl;
	std::cout << "c(" << std::setw(10) << c << ") " << test << " d(" << std::setw(10) << d << ") = " << c + d << std::endl;

	test = "-";
	print_header(test);
	std::cout << "a(" << std::setw(10) << a << ") " << test << " b(" << std::setw(10) << b << ") = " << a - b << std::endl;
	std::cout << "b(" << std::setw(10) << b << ") " << test << " c(" << std::setw(10) << c << ") = " << b - c << std::endl;
	std::cout << "c(" << std::setw(10) << c << ") " << test << " d(" << std::setw(10) << d << ") = " << c - d << std::endl;

	test = "*";
	print_header(test);
	std::cout << "a(" << std::setw(10) << a << ") " << test << " b(" << std::setw(10) << b << ") = " << a * b << std::endl;
	std::cout << "b(" << std::setw(10) << b << ") " << test << " c(" << std::setw(10) << c << ") = " << b * c << std::endl;
	std::cout << "c(" << std::setw(10) << c << ") " << test << " d(" << std::setw(10) << d << ") = " << c * d << std::endl;

	test = "/";
	print_header(test);
	std::cout << "a(" << std::setw(10) << a << ") " << test << " b(" << std::setw(10) << b << ") = " << a / b << std::endl;
	std::cout << "e(" << std::setw(10) << e << ") " << test << " f(" << std::setw(10) << f << ") = " << e / f << std::endl;
	std::cout << "b(" << std::setw(10) << b << ") " << test << " f(" << std::setw(10) << f << ") = " << b / f << std::endl;

	try
	{
		print_header("division by zero");
		std::cout << "a(" << std::setw(10) << a << ") " << test << " c(" << std::setw(10) << c << ") = " << a / c << std::endl;
	}
	catch (const std::logic_error& err)
	{
		std::cout << COLOR_CYAN << err.what() << COLOR_RESET << std::endl;
	}


	print_header("pre-increment, post-increment, pre-decrement and post-decrement");

	test = "++(value)";
	print_header(test);
	std::cout << std::setw(10) << a << " -> " << test << ": " << std::setw(10) << ++a << ", after: " << a << std::endl;
	std::cout << std::setw(10) << c << " -> " << test << ": " << std::setw(10) << ++c << ", after: " << c << std::endl;
	std::cout << std::setw(10) << f << " -> " << test << ": " << std::setw(10) << ++f << ", after: " << f << std::endl;

	test = "(value)++";
	print_header(test);
	std::cout << std::setw(10) << a << " -> " << test << ": " << std::setw(10) << a++ << ", after: " << a << std::endl;
	std::cout << std::setw(10) << c << " -> " << test << ": " << std::setw(10) << c++ << ", after: " << c << std::endl;
	std::cout << std::setw(10) << f << " -> " << test << ": " << std::setw(10) << f++ << ", after: " << f << std::endl;

	test = "--(value)";
	print_header(test);
	std::cout << std::setw(10) << a << " -> " << test << ": " << std::setw(10) << --a << ", after: " << a << std::endl;
	std::cout << std::setw(10) << c << " -> " << test << ": " << std::setw(10) << --c << ", after: " << c << std::endl;
	std::cout << std::setw(10) << f << " -> " << test << ": " << std::setw(10) << --f << ", after: " << f << std::endl;

	test = "(value)--";
	print_header(test);
	std::cout << std::setw(10) << a << " -> " << test << ": " << std::setw(10) << a-- << ", after: " << a << std::endl;
	std::cout << std::setw(10) << c << " -> " << test << ": " << std::setw(10) << c-- << ", after: " << c << std::endl;
	std::cout << std::setw(10) << f << " -> " << test << ": " << std::setw(10) << f-- << ", after: " << f << std::endl;


	print_header("min, max");

	test = "min";
	print_header(test);
	std::cout << test << '(' << std::setw(10) << a << ", " << std::setw(10) << b << "): " << Fixed::min(a, b) << std::endl;
	std::cout << test << '(' << std::setw(10) << f << ", " << std::setw(10) << c << "): " << Fixed::min(f, c) << std::endl;
	std::cout << test << '(' << std::setw(10) << c << ", " << std::setw(10) << d << "): " << Fixed::min(c, d) << std::endl;

	test = "min(const)";
	print_header(test);
	std::cout << "min(" << b << ", " << e << "): " << Fixed::min(b, e) << std::endl;

	test = "max";
	print_header(test);
	std::cout << test << '(' << std::setw(10) << a << ", " << std::setw(10) << b << "): " << Fixed::max(a, b) << std::endl;
	std::cout << test << '(' << std::setw(10) << f << ", " << std::setw(10) << c << "): " << Fixed::max(f, c) << std::endl;
	std::cout << test << '(' << std::setw(10) << c << ", " << std::setw(10) << d << "): " << Fixed::max(c, d) << std::endl;

	test = "max(const)";
	print_header(test);
	std::cout << "max(" << b << ", " << e << "): " << Fixed::max(b, e) << std::endl;

	return 0;
}
