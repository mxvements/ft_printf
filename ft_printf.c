/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:06:33 by luciama2          #+#    #+#             */
/*   Updated: 2023/10/19 16:06:39 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"

/* notes on variadic functions
 *
 * void	va_start(va_list argument_list, last_known_parameter);
 * 		DESCRIPTION
 * 		va_start() macro, intializes your argument_list for use by va_arg() and
 * 		va_end8), and must be called first. The last_known_parameter is the 
 * 		name of the last known parameter of the calling function, here, 
 * 		ft_printf();
 *
 * argument_type	va_arg(va_list argument_list, argument_type)
 * 		DESCRIPTON
 * 		everytime it is called, it modifies argument_list so that the next time
 * 		is is called, it will return the next argument.
 * 		RETURN VALUE
 * 		Expands to an expression that has the type and value of the next arg.
 * 		in the call. The 1st use of the va_arg() macro after that of the
 * 		va_start() macro returns the argument after last_known_parameter.
 *		NOTES
 *		Successive invocations return the values of the remaining arguments.
 *		It is your job to make sure you're giving va_arg() the correct type
 *		of variable to return, it will assume you know what's being sent.
 *
 * void va_end(va_list argument_list)
 * 		DESCRIPTION
 * 		Each invocation of va_start() must be matched by a corresponding
 * 		invocation of va_end() in the same function.
 * 		After the call to va_end(), the variable argument_list is undefined. 	
 */

int ft_printf(const char *format, ...)
{
	va_list	vargs;
	int		len;
	
	va_start(vargs, char *);
	//...
	//len: longitud que devuelve en consola
	//entre medio -> va_arg();
	//
	//%c prints a single char
	//		-> ft_putchar(va_arg(vargs, char))
	//%s prints a str
	//		-> ft_putstr(va_args(vargs, char *))
	//%p prints void *
	//		-> ft_putnbr_base(var_args(vargs, int), base = 16)
	//%d prints a decimal(10) nbr
	//		-> ft_putnbr_base(va_args(vargs, int), base = 10) **
	//%i prints an int
	//		-> ft_putnbr(va_args(vargs, int))
	//%u prints unsinged decimal (b 10)
	//		-> ft_putnbr(va_args(vargs, unsigned int), base = 10) **
	//%x prints hex nbr lowercase
	//		-> ft_putnbr_base(va_args, int)) using ft_tolower()
	//%X prints hex nbr uppercase
	//		-> ft_putnbr_bse(va_args, int)) using ft_toupper()
	//%% prints % sign
	//		-> putchar(\%)
	//
	va_end(vargs);
	return (len);
}
