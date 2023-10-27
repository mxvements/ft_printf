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
#include <stdio.h>
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
		return (i + ft_putstr(va_args(vargs, char *))); //int ft_putstr(va_args(vargs, char *))
	if (c == 'p') //void *
		return (i + ft_putnbr_base(va_args(vargs, void *), base16));///int ft_putnbr_base(var_args(vargs, int), base = 16)
	if (c == 'd') //digit, base 10
		return (i +ft_putnbr_base(var_args(vargs, int), base10));// int ft_putnbr_base(va_args(vargs, int), base = 10)
	if (c == 'i') //integer , base 10
		return (i + ft_putnbr_base(var_args(vargs, int), base10));//int ft_putnbr_base(va_args(vargs, int), base = 10)
	if (c == 'u') //unsigned int, base 10
		return (i + ft_putnbr_base(var_args(vargs, unsigned int), base10));//int ft_putnbr(va_args(vargs, unsigned int), base = 10)
	if (c == 'x') //hexadecimal, lowercase
		return (i + ft_putnbr_lower_base(va_args(vargs, int), base16));//int ft_putnbr_base(va_args, int)) using ft_tolower()
	if (c == 'X') //hexadecimal, uppercase
		return (i + ft_putnbr_upper_base(va_args(vargs, int), base16));//int ft_putnbr_bse(va_args, int)) using ft_toupper()
	if (c == '%') //just %
		return (i + ft_putchar(var_args(vargs, c)));
	return (0);
}

static int put_interp_var(interp_var *plh)
{

}

/** static void reset_interp_var(interp_var *plh)
 * @brief function to apply zero to all values in the interpolated_var struc
 * @param plh 
 */
static void reset_interp_var(interp_var *plh)
{
	plh->hash_flag = 0;
	plh->plus_flag = 0;
	plh->space_flag = 0;
	plh->specifier = '0';
}
 
/** stacic int check_interp_var(interp_var *plh)
 * @brief function to check the logic behind the application of the flags
 * and the specifiers on the format string's interpolated var.
 * Specifications:
 * 		flag ' ' is ignored when flag '+' is present
 * 		'#' flag only applies to 'x' or 'X' specifiers
 * 		'+' flag only applies to 'd' or 'i' specifiers
 * 		a permited specifier should always appear after '%'
 * 		permited flags can be missing after '%' 
 * @param plh struct interpolated_var
 * @return int 
 * 		0 if flags are ok
 * 		non-zero (-1) if error
 */
static int check_interp_var(interp_var *plh)
{
	if (plh->specifier == NULL)
		return (-1);
	if (plh->hash_flag == 1 && (plh->specifier != 'x' || plh->specifier != 'X'))
		retunr (-1);
	if (plh->plus_flag == 1 && (plh->specifier != 'd' || plh->specifier != 'i'))
		return (-1);
	if (plh->plus_flag == 1 && plh->space_flag == 1)
		plh->space_flag = 0;
	return (0);
}

/** static int update_interp_var(const char *s, interp_var *plh)
 * @brief function to set all the interpolated_var attributes to their
 * corresponding value when present in the format string
 * the function iterates on the format string, returns the index at which the 
 * iteration ends 
 * @param s, format string to iterate
 * @param plh, interp_var struct
 * @return int, index at which the iteration ends
 * the function iterates the format str when the the char doesnt equivalate to
 * any of the flags & specifiers
 */
static int update_interp_var(const char *s, interp_var *plh)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			plh->space_flag = 1;
		else if (s[i] == '#')
			plh->hash_flag = 1;
		else if (s[i] == '+')
			plh->plus_flag = 1;
		else if (s[i] =='c' || s[i] == 's' || s[i] == 'p' || s[i] == 'd' ||
				s[i] == 'i' || s[i] == 'u' || s[i] == 'x' || s[i] == 'X' ||
				s[i] == '%')
		 	plh->specifier = s[i];
		else
			return (i);
		i++;
	}
	return (i);
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
	interp_var	plh;
	
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
			reset_interp_var(&plh);
			update_interp_var((format + i), &plh);
			check_interp_var(&plh);
			len += ;
			//if len == (-1) -> error
			//else len += (count) y count = 0,
			//habrá que sumar lo que ya haya leido y resetear el count a 0
		}
		i++;
	}
	va_end(vargs);
	return (count);
}
