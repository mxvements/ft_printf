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

int	ft_printchar(t_interp *plh, char c)
{
	int	len;

	len = 0;
	if (plh->space_flag == 1)
		len += write(1, " ", 1);
	len += write(1, &c, 1);
	return (len);
}

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

void	ft_putnbr_base(unsigned long long nb, char *b, size_t *sb, int *len)
{
	char	c;

	if (nb >= *sb)
		ft_putnbr_base((nb / *sb), b, sb, len);
	c = b[nb % *sb];
	*len += write(1, &c, 1);
	return ;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
