/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:42:25 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/13 17:41:57 by sikeda           ###   ########.fr       */
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


	print_header("Four arithmetic operators: +, -, *, and /");

	Fixed		x, y;
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
