/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:21:22 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/13 11:36:47 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	int					_fixed_point_val;
	static const int	_bits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& other);
	Fixed&	operator=(const Fixed& x);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif
