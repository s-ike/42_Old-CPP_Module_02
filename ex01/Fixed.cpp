/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:31:00 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/13 00:45:04 by sikeda           ###   ########.fr       */
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
	std::cout << "Default constructor called" << std::endl;
}

/*
固定小数点分（_bits = 8）左にずらして格納
*/
Fixed::Fixed(const int x)
{
	std::cout << "Int constructor called" << std::endl;
	_fixed_point_val = x << _bits;
}

/*
1. Calculate x = floating_input * 2^(fractional_bits)
2. Round x to the nearest whole number (e.g. round(x))
3. Store the rounded x in an integer container
*/
Fixed::Fixed(const float x)
{
	std::cout << "Float constructor called" << std::endl;
	_fixed_point_val = static_cast<int>(std::roundf(x * (1 << _bits)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed &other)
{
	std::cout << "Assignation operator called" << std::endl;
	_fixed_point_val = other._fixed_point_val;
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
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
