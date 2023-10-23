/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:06:33 by luciama2          #+#    #+#             */
/*   Updated: 2023/10/23 18:21:19 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <ctype.h>
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

static int	ft_putchar(char c)
{
	return (write(1, c, 1)); 
}

//base10 and base16 are placeholders for the moment
//all functions to be done
static int	var_type(char c, va_list vargs)
{
	if (c == 'c')
		return (ft_putchar(va_args(vargs, int))); //int ft_putchar(va_arg(vargs, char))
	if (c == 's')
		return (ft_putstr(va_args(vargs, char *))); //int ft_putstr(va_args(vargs, char *))
	if (c == 'p')
		return (ft_putnbr_base(va_args(vargs, void *), base16));///int ft_putnbr_base(var_args(vargs, int), base = 16)
	if (c == 'd')
		return (ft_putnbr_base(var_args(vargs, int), base10));// int ft_putnbr_base(va_args(vargs, int), base = 10)
	if (c == 'i')
		return (ft_putnbr_base(var_args(vargs, int), base10))//int ft_putnbr_base(va_args(vargs, int), base = 10)
	if (c == 'u')
		return (ft_putnbr_base(var_args(vargs, unsigned int), base10))//int ft_putnbr(va_args(vargs, unsigned int), base = 10)
	if (c == 'x')
		return (ft_putnbr_lower_base(va_args(vargs, int), base16));//int ft_putnbr_base(va_args, int)) using ft_tolower()
	if (c == 'X')
		return (ft_putnbr_upper_base(va_args(vargs, int), base16));//int ft_putnbr_bse(va_args, int)) using ft_toupper()
	if (c == '%')
		return (ft_putchar(var_args(vargs, c)));
	return (0);
}

/* La funcion printf retorna el numero de caracteres impresos o un valor
 * negativo si ocurre un error. 
*/
int ft_printf(const char *format, ...)
{
	va_list	vargs;
	int		len;
	size_t	i;
	
	va_start(vargs, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
			len = var_type(format[i + 1], vargs); //if len == (-1) -> error
		i++;
	}
	va_end(vargs);
	len += (i - 1);
	return (len);
}
