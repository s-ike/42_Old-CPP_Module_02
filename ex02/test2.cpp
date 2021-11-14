/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:42:25 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/14 18:58:47 by sikeda           ###   ########.fr       */
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

void	comp(const Fixed& x, const Fixed& y, bool b)
{
	std::string	bs = b ? "true" : "false";
	std::cout << "x(" << std::setw(10) << x << "), y(" << std::setw(10) << y << "): " << bs << std::endl;
}

void	calc(const Fixed& x, const Fixed& y, const std::string& op, const Fixed& ans)
{
	std::cout << std::fixed;
	std::cout << "x(" << std::setw(10) << x << ") " << op << " y(" << std::setw(10) << y << ") = " << ans << std::endl;
}

void	test_comp()
{
	Fixed	a(0.0078125f);
	Fixed	b(Fixed(5.05f) * Fixed(2));
	Fixed	c(0);
	Fixed	d(c);

	print_header(">");
	comp(a, b, a > b);
	comp(b, c, b > c);
	comp(c, d, c > d);

	print_header("<");
	comp(a, b, a < b);
	comp(b, c, b < c);
	comp(c, d, c < d);

	print_header(">=");
	comp(a, b, a >= b);
	comp(b, c, b >= c);
	comp(c, d, c >= d);

	print_header("<=");
	comp(a, b, a <= b);
	comp(b, c, b <= c);
	comp(c, d, c <= d);

	print_header("==");
	comp(a, b, a == b);
	comp(b, c, b == c);
	comp(c, d, c == d);

	print_header("!=");
	comp(a, b, a != b);
	comp(b, c, b != c);
	comp(c, d, c != d);
}

void	test_calc()
{
	Fixed	a(0.0078125f);
	Fixed	b(Fixed(5.05f) * Fixed(2));
	Fixed	c(0);
	Fixed	d(c);
	Fixed	x, y;

	std::string	test = "+";
	print_header(test);
	calc(a, b, test, Fixed(a) + Fixed(b));
	calc(b, c, test, Fixed(b) + Fixed(c));
	calc(c, d, test, Fixed(c) + Fixed(d));
	x = Fixed(8388605.996f);
	y = Fixed(1);
	calc(x, y, test, Fixed(x) + Fixed(y));
	x = Fixed(8388606.996f);
	calc(x, y, test, Fixed(x) + Fixed(y));

	test = "-";
	print_header(test);
	calc(a, b, test, Fixed(a) - Fixed(b));
	calc(b, c, test, Fixed(b) - Fixed(c));
	calc(c, d, test, Fixed(c) - Fixed(d));
	x = Fixed(-8388606.996f);
	y = Fixed(1);
	calc(x, y, test, Fixed(x) - Fixed(y));
	x = Fixed(-8388607.996f);
	calc(x, y, test, Fixed(x) - Fixed(y));
	x = Fixed(-8388608.996f);
	calc(x, y, test, Fixed(x) - Fixed(y));

	test = "*";
	print_header(test);
	calc(a, b, test, Fixed(a) * Fixed(b));
	calc(b, c, test, Fixed(b) * Fixed(c));
	calc(c, d, test, Fixed(c) * Fixed(d));
	x = Fixed(3);
	y = Fixed(0.5f);
	calc(x, y, test, Fixed(x) * Fixed(y));
	y = Fixed(0.1f);
	calc(x, y, test, Fixed(x) * Fixed(y));
	x = Fixed(1.1f);
	y = Fixed(-0.3f);
	calc(x, y, test, Fixed(x) * Fixed(y));
	x = Fixed(8388606.996f);
	y = Fixed(1);
	calc(x, y, test, Fixed(x) * Fixed(y));
	y = Fixed(2);
	calc(x, y, test, Fixed(x) * Fixed(y));

	Fixed	e(256);
	Fixed	f(-42.0f);

	test = "/";
	print_header(test);
	calc(a, b, test, Fixed(a) / Fixed(b));
	calc(e, f, test, Fixed(e) / Fixed(f));
	calc(b, f, test, Fixed(b) / Fixed(f));
	x = Fixed(3);
	y = Fixed(0.5f);
	calc(x, y, test, Fixed(x) / Fixed(y));
	y = Fixed(0.1f);
	calc(x, y, test, Fixed(x) / Fixed(y));
	x = Fixed(1.1f);
	y = Fixed(-0.3f);
	calc(x, y, test, Fixed(x) / Fixed(y));
	x = Fixed(-8388607.996f);
	y = Fixed(1);
	calc(x, y, test, Fixed(x) / Fixed(y));
	y = Fixed(2);
	calc(x, y, test, Fixed(x) / Fixed(y));

	try
	{
		print_header("division by zero");
		calc(a, c, test, Fixed(a) / Fixed(c));
	}
	catch (const std::logic_error& err)
	{
		std::cout << err.what() << std::endl;
	}
}

void	test_increment_and_decrement()
{
	std::string	tests[] = {"++(value)", "(value)++", "--(value)", "(value)--"};
	Fixed	a(0.0078125f);
	Fixed	c(0);
	Fixed	f(-42.0f);

	for (unsigned i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
	{
		print_header(tests[i]);
		switch (i)
		{
		case 0:
			std::cout << std::setw(10) << a << " -> " << tests[i] << ": " << std::setw(10) << ++a << ", after: " << a << std::endl;
			std::cout << std::setw(10) << c << " -> " << tests[i] << ": " << std::setw(10) << ++c << ", after: " << c << std::endl;
			std::cout << std::setw(10) << f << " -> " << tests[i] << ": " << std::setw(10) << ++f << ", after: " << f << std::endl;
			break;
		case 1:
			std::cout << std::setw(10) << a << " -> " << tests[i] << ": " << std::setw(10) << a++ << ", after: " << a << std::endl;
			std::cout << std::setw(10) << c << " -> " << tests[i] << ": " << std::setw(10) << c++ << ", after: " << c << std::endl;
			std::cout << std::setw(10) << f << " -> " << tests[i] << ": " << std::setw(10) << f++ << ", after: " << f << std::endl;
			break;
		case 2:
			std::cout << std::setw(10) << a << " -> " << tests[i] << ": " << std::setw(10) << --a << ", after: " << a << std::endl;
			std::cout << std::setw(10) << c << " -> " << tests[i] << ": " << std::setw(10) << --c << ", after: " << c << std::endl;
			std::cout << std::setw(10) << f << " -> " << tests[i] << ": " << std::setw(10) << --f << ", after: " << f << std::endl;
			break;
		case 3:
			std::cout << std::setw(10) << a << " -> " << tests[i] << ": " << std::setw(10) << a-- << ", after: " << a << std::endl;
			std::cout << std::setw(10) << c << " -> " << tests[i] << ": " << std::setw(10) << c-- << ", after: " << c << std::endl;
			std::cout << std::setw(10) << f << " -> " << tests[i] << ": " << std::setw(10) << f-- << ", after: " << f << std::endl;
		default:
			break;
		}
	}
}

void	test_min_and_max()
{
	Fixed		a(0.0078125f);
	const Fixed	b(Fixed(5.05f) * Fixed(2));
	Fixed		c(0);
	Fixed		d(c);
	const Fixed	e(256);
	Fixed		f(-42.0f);

	std::string	test = "min";
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

	print_header("Six comparison operators: >, <, >=, <=, == and !=");
	test_comp();

	print_header("Four arithmetic operators: +, -, *, and /");
	test_calc();

	print_header("pre-increment, post-increment, pre-decrement and post-decrement");
	test_increment_and_decrement();

	print_header("min, max");
	test_min_and_max();

	return 0;
}
