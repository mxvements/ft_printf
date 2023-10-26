/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:06:33 by luciama2          #+#    #+#             */
/*   Updated: 2023/10/26 15:34:38 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <ctype.h>
#include "ft_printf_utils.h"
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
static int	var_type(char c, va_list vargs, int i)
{
	if (c == 'c') //char
		return (i + ft_putchar(va_args(vargs, int))); //int ft_putchar(va_arg(vargs, char))
	if (c == 's') //string
		return (ft_putstr(va_args(vargs, char *))); //int ft_putstr(va_args(vargs, char *))
	if (c == 'p') //void *
		return (ft_putnbr_base(va_args(vargs, void *), base16));///int ft_putnbr_base(var_args(vargs, int), base = 16)
	if (c == 'd') //digit, base 10
		return (ft_putnbr_base(var_args(vargs, int), base10));// int ft_putnbr_base(va_args(vargs, int), base = 10)
	if (c == 'i') //integer , base 10
		return (ft_putnbr_base(var_args(vargs, int), base10))//int ft_putnbr_base(va_args(vargs, int), base = 10)
	if (c == 'u') //unsigned int, base 10
		return (ft_putnbr_base(var_args(vargs, unsigned int), base10))//int ft_putnbr(va_args(vargs, unsigned int), base = 10)
	if (c == 'x') //hexadecimal, lowercase
		return (ft_putnbr_lower_base(va_args(vargs, int), base16));//int ft_putnbr_base(va_args, int)) using ft_tolower()
	if (c == 'X') //hexadecimal, uppercase
		return (ft_putnbr_upper_base(va_args(vargs, int), base16));//int ft_putnbr_bse(va_args, int)) using ft_toupper()
	if (c == '%') //just %
		return (ft_putchar(var_args(vargs, c)));
	return (0);
}

static int	putflag(const char c, int spc, int pls, int hsh, va_list vargs)
{
	//use ft_putchar to print the char(s) corresponding for the flags
	//return if no error, de amount of chars printed by the flags
	return (-1);
}

/** static int	check_var_type(const char c)
 * @brief check if char is any of the placeholders implemented on the printf
 * function
 * @param c	char to check
 * @return int, 0 if false, non-zero (1) if true
 */
static int	check_var_type(const char c)
{
	if (c =='c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' ||
		c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int flag_type(const char *s, va_list vargs)
{
	int		spc;
	int		pls;
	int		hsh;
	size_t	i;

	i = 0;
	spc = 0;
	pls = 0;
	hsh = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			spc = 1;
		else if (s[i] == '#')
			hsh = 1;
		else if (s[i] == '+')
			pls = 1;
		else if (check_var_type(s[i]) == 1)
		 	return (putflag(s[i], spc, pls, hsh, vargs));
		else
			return (-1);
		i++;
	}
	return (-1);
}

/* La funcion printf retorna el numero de caracteres impresos o un valor
 * negativo si ocurre un error. 
*/
int ft_printf(const char *format, ...)
{
	va_list		vargs;
	int			len;
	size_t		count;
	size_t		i;
	placeholder	plh;
	
	va_start(vargs, format);
	i = 0;
	count = 0;
	len = 0;
	while (format[i] != '\0')
	{
		count++;
		//write each char, ft_putchar(format[i]) while is not %
		if (format[i] == '%')
		{
			len += flag_type((format + i), vargs);
			//if len == (-1) -> error
			//else len += (count) y count = 0,
			//habrá que sumar lo que ya haya leido y resetear el count a 0
		}
		i++;
	}
	va_end(vargs);
	return (count);
}
