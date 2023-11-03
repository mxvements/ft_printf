/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:50:39 by luciama2          #+#    #+#             */
/*   Updated: 2023/10/27 16:50:40 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** int ft_printfchar(t_interp *plh, char c)
 * @brief Function to write a char on the standard ouput. 
 * It uses the write  * funciton with fd = 1. No protection on the write funct.
 * It manages the output of the space flag (' ') for the printf funct.
 * @param plh, structure of the interpolated var on the printf function, saves
 * information about flags and specificator
 * @param c, char to print
 * @return int, length printed on the standard output
 */
int	ft_printchar(t_interp *plh, char c)
{
	int	len;

	len = 0;
	if (plh->space_flag == 1)
		len += write(1, " ", 1);
	len += write(1, &c, 1);
	return (len);
}

/** int ft_printstr(t_interp *plh, char *s)
 * @brief Function to print a string (char *) on the standard ouput. It iterates
 * through 's' and prints each char using write (without protection)
 * When 's' is null, '(null)' should be printed.
 * It also handles the space flag ' ' of the printf function. 
 * @param plh, structure of the interpolated var on the printf function, saves
 * information about flags and specificator
 * @param s, string to print on the standard ouput
 * @return int, length printed on the standard ouput
 */
int	ft_printstr(t_interp *plh, char *s)
{
	int		len;
	size_t	i;

	len = 0;
	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	if (plh->space_flag == 1)
		len += write(1, " ", 1);
	while (s[i] != '\0')
		len += write(1, &s[i++], 1);
	return (len);
}

/** void ft_putnbr_base(unsigned long long nb, char *b, size_t *sb, int *len)
 * @brief Function to print a number on the standard output. It uses recursion
 * to print each digit on reverse order.
 * @param nb, number to print on the standard ouput
 * @param b, bnumber base
 * @param sb, size of base
 * @param len, length printed on the standard output, passed onto the function
 * by reference
 */
void	ft_putnbr_base(unsigned long long nb, char *b, size_t *sb, int *len)
{
	char	c;

	if (nb >= *sb)
		ft_putnbr_base((nb / *sb), b, sb, len);
	c = b[nb % *sb];
	*len += write(1, &c, 1);
	return ;
}

/** size_t ft_strlen(const char *s)
 * @brief Function to return the length of a string 's' * 
 * @param s, string to handle
 * @return size_t, length of the string
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
