/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:31:00 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/13 11:36:18 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

/* ************************************************************************** */
/*   public                                                                   */
/* ************************************************************************** */

Fixed::Fixed()
	: _fixed_point_val(0)
{
#ifndef TEST
	std::cout << "Default constructor called" << std::endl;
#endif
}

/*
固定小数点分（_bits = 8）左にずらして格納
*/
Fixed::Fixed(const int x)
{
#ifndef TEST
	std::cout << "Int constructor called" << std::endl;
#endif
	_fixed_point_val = x << _bits;
}

/*
1. Calculate x = floating_input * 2^(fractional_bits)
2. Round x to the nearest whole number (e.g. round(x))
3. Store the rounded x in an integer container
*/
Fixed::Fixed(const float x)
{
#ifndef TEST
	std::cout << "Float constructor called" << std::endl;
#endif
	_fixed_point_val = static_cast<int>(roundf(x * (1 << _bits)));
}

Fixed::~Fixed()
{
#ifndef TEST
	std::cout << "Destructor called" << std::endl;
#endif
}

Fixed::Fixed(const Fixed& other)
{
#ifndef TEST
	std::cout << "Copy constructor called" << std::endl;
#endif
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
#ifndef TEST
	std::cout << "Assignation operator called" << std::endl;
#endif
	_fixed_point_val = other._fixed_point_val;
	return *this;
}

int	Fixed::getRawBits( void ) const
{
#ifndef TEST
	std::cout << "getRawBits member function called" << std::endl;
#endif
	return _fixed_point_val;
}

void	Fixed::setRawBits( int const raw )
{
	_fixed_point_val = raw;
}

/*
divide fixed_point_value by (2^fractional_bits), putting the result into a float
*/
float	Fixed::toFloat( void ) const
{
	return static_cast<float>(_fixed_point_val) / static_cast<float>(1 << _bits);
}

/*
固定小数点分（_bits = 8）右にずらしてリターン
*/
int	Fixed::toInt( void ) const
{
	return _fixed_point_val >> _bits;
}

std::ostream&	operator<<(std::ostream& lhs, const Fixed& rhs)
{
	return lhs << rhs.toFloat();
}

/* ************************************************************************** */
/*   Six comparison operators: >, <, >=, <=, == and !=                        */
/* ************************************************************************** */

bool	Fixed::operator>(const Fixed& rhs) const
{
	return _fixed_point_val > rhs._fixed_point_val;
}

bool	Fixed::operator<(const Fixed& rhs) const
{
	return _fixed_point_val < rhs._fixed_point_val;
}

bool	Fixed::operator>=(const Fixed& rhs) const
{
	return _fixed_point_val >= rhs._fixed_point_val;
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	return _fixed_point_val <= rhs._fixed_point_val;
}

bool	Fixed::operator==(const Fixed& rhs) const
{
	return _fixed_point_val == rhs._fixed_point_val;
}

bool	Fixed::operator!=(const Fixed& rhs) const
{
	return !(*this == rhs);
}

/* ************************************************************************** */
/*   Four arithmetic operators: +, -, *, and /                                */
/* ************************************************************************** */

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	if (rhs.toFloat() == 0)
		throw DividedByZero();
	return Fixed(this->toFloat() / rhs.toFloat());
}

/* ************************************************************************** */
/*   pre-increment, post-increment, pre-decrement and post-decrement          */
/* ************************************************************************** */

// ++(*this)
// 2^-8（0.00390625）を足す
Fixed&	Fixed::operator++()
{
	_fixed_point_val += 1;
	return *this;
}

// (*this)++
Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	++(*this);
	return temp;
}

// --(*this)
Fixed&	Fixed::operator--()
{
	_fixed_point_val -= 1;
	return *this;
}

// (*this)--
Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	--(*this);
	return temp;
}

/* ************************************************************************** */
/*   min, max                                                                 */
/* ************************************************************************** */
// 等価な要素の場合には、左の要素を返す

Fixed&	Fixed::min(Fixed& x, Fixed& y)
{
	if (y < x)
		return y;
	return x;
}

const Fixed&	Fixed::min(const Fixed& x, const Fixed& y)
{
	if (y < x)
		return y;
	return x;
}

Fixed&	Fixed::max(Fixed& x, Fixed& y)
{
	if (x < y)
		return y;
	return x;
}

const Fixed&	Fixed::max(const Fixed& x, const Fixed& y)
{
	if (x < y)
		return y;
	return x;
}
