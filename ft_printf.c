/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:06:33 by luciama2          #+#    #+#             */
/*   Updated: 2023/10/29 20:50:54 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** int ft_printf(const char str, ...)
 * @brief Function to printf a 'format' string on the standard output using
 * interpolated variables.
 * Available specifiers: 'cspdiuxX%'
 * Available flags: '# +'
 * @param str, format string to print on the strandar output
 * @param ... , variadic param
 * @return int, length of the printed string on the standard output
 */
int	ft_printf(const char *str, ...)
{
	va_list		vargs;
	size_t		out_len;
	size_t		count;
	t_interp	plh;

	va_start(vargs, str);
	count = 0;
	out_len = 0;
	if (!str)
		return (-1);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str += update_interp_var((str), &plh);
			if (check_interp_var(&plh) == -1)
				return (-1);
			out_len += put_interp_var(&plh, vargs);
		}
		else
			count += write(1, &*str, 1);
		str++;
	}
	va_end(vargs);
	return (out_len + count);
}
