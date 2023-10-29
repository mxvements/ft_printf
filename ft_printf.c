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

# include "ft_printf.h"
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

/* La funcion printf retorna el numero de caracteres impresos o un valor
 * negativo si ocurre un error. 
*/
int ft_printf(const char *format __attribute__((format(printf, 1, 2))), ...)
{
	va_list		vargs;
	int			len;
	size_t		count;
	size_t		i;
	t_interp	plh;
	
	va_start(vargs, format);
	i = 0;
	count = 0;
	len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i += update_interp_var((format + i), &plh);
			if (check_interp_var(&plh) == -1)
				return (-1); //error
			len += put_interp_var(&plh, vargs);
			len += count;
			count = 0;
		}
		else
		{
			count += write(1, format[i], 1);
			i++;
		}
	}
	va_end(vargs);
	return (len);
}
