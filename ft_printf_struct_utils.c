/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:14:29 by luciama2          #+#    #+#             */
/*   Updated: 2023/10/27 16:14:31 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** static int put_interp_var(interp_var *plh, va_list vargs)
 * @brief function to choose each print function based on the specifier in the
 * interpolated var 
 * @param plh 
 * @param vargs 
 * @return int 
 */
int	put_interp_var(t_interp *plh, va_list vargs)
{
	char	*base10;
	char	*base16upper;
	char	*base16lower;

	base10 = "0123456789";
	base16upper = "0123456789ABCDEF";
	base16lower = "0123456789abcdef";
	if (plh->specifier == 'c') //char
		return (ft_printchar(plh, va_arg(vargs, int)));
	if (plh->specifier == 's') //string
		return (ft_printstr(plh, va_arg(vargs, char *)));
	if (plh->specifier == 'p') //void *
		return (ft_printnbr_vptr_base(va_arg(vargs, void *), base16lower));
	if (plh->specifier == 'd' || plh->specifier == 'i') //digit or int, base 10
		return (ft_printnbr_base(plh, va_arg(vargs, int), base10));
	if (plh->specifier == 'u') //unsigned int, base 10
		return (ft_printnbr_u_base(plh, va_arg(vargs, unsigned int), base10));
	if (plh->specifier == 'x') //hexadecimal, lowercase
		return (ft_printnbr_x_base(plh, va_arg(vargs, int), base16lower));
	if (plh->specifier == 'X') //hexadecimal, uppercase
		return (ft_printfnbr_xupp_base(plh, va_arg(vargs, int), base16upper));
	if (plh->specifier == '%') //just %,
		return (ft_printchar(plh, '%'));
	return (0);
}

/** static void reset_interp_var(interp_var *plh)
 * @brief function to apply zero to all values in the interpolated_var struc
 * @param plh 
 */
void	reset_interp_var(t_interp *plh)
{
	plh->hash_flag = 0;
	plh->plus_flag = 0;
	plh->space_flag = 0;
	plh->specifier = '0';
	plh->sign = '+';
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
int	check_interp_var(t_interp *plh)
{
	if (plh->specifier == '\0')
		return (-1);
	if (plh->hash_flag == 1 && (plh->specifier != 'x' || plh->specifier != 'X'))
		return (-1);
	if (plh->plus_flag == 1 && (plh->specifier != 'd' || plh->specifier != 'i'))
		return (-1);
	if (plh->plus_flag == 1 && plh->space_flag == 1)
		plh->space_flag = 0;
	return (0);
}

/** static size_t update_interp_var(const char *s, interp_var *plh)
 * @brief function to set all the interpolated_var attributes to their
 * corresponding value when present in the 'format' string
 * the function iterates on the 'format' string, returns the index at which the 
 * iteration ends 
 * @param s, format string to iterate
 * @param plh, interp_var struct
 * @return size_t, index at which the iteration ends
 * the function iterates the format str when the the char doesnt equivalate to
 * any of the flags & specifiers
 */
size_t	update_interp_var(const char *s, t_interp *plh)
{
	size_t	i;

	i = 0;
	reset_interp_var(plh);
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			plh->space_flag = 1;
		else if (s[i] == '#')
			plh->hash_flag = 1;
		else if (s[i] == '+')
			plh->plus_flag = 1;
		else if (s[i] == 'c' || s[i] == 's' || s[i] == 'p' || s[i] == 'd'
			|| s[i] == 'i' || s[i] == 'u' || s[i] == 'x' || s[i] == 'X'
			|| s[i] == '%')
		{
			plh->specifier = s[i];
			return (i);
		}
		else
			return (i);
		i++;
	}
	return (i);
}
