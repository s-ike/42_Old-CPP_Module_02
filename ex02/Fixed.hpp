/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:21:22 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/13 11:35:59 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <sstream>

class Fixed
{
	int					_fixed_point_val;
	static const int	_bits = 8;

public:
	Fixed();
	Fixed(const int x);
	Fixed(const float x);
	~Fixed();
	Fixed(const Fixed& other);
	Fixed&	operator=(const Fixed& other);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	bool	operator>(const Fixed& rhs) const;
	bool	operator<(const Fixed& rhs) const;
	bool	operator>=(const Fixed& rhs) const;
	bool	operator<=(const Fixed& rhs) const;
	bool	operator==(const Fixed& rhs) const;
	bool	operator!=(const Fixed& rhs) const;

	Fixed	operator+(const Fixed& rhs) const;
	Fixed	operator-(const Fixed& rhs) const;
	Fixed	operator*(const Fixed& rhs) const;
	Fixed	operator/(const Fixed& rhs) const;

	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);

	static Fixed&		min(Fixed& x, Fixed& y);
	static const Fixed&	min(const Fixed& x, const Fixed& y);
	static Fixed&		max(Fixed& x, Fixed& y);
	static const Fixed&	max(const Fixed& x, const Fixed& y);

	class	DividedByZero {};
};

std::ostream&	operator<<(std::ostream& lhs, const Fixed& rhs);

#endif
