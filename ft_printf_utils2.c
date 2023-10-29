/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:24:13 by luciama2          #+#    #+#             */
/*   Updated: 2023/10/27 18:24:17 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//void *-> pointer address
//no flags apply to this specifier
//since its a memory address, should always be positive
size_t	ft_printnbr_vptr_base(t_interp *plh, void *nbr, char *base)
{
	size_t				len;
	unsigned long long	nb;
	const size_t		base_size = ft_strlen(base);

	nb = (unsigned long long)nbr; //check this
	len = 0;
	len += write(1, "0x", 2);
	if (nb >= base_size)
		ft_putnbr_base(nb, base, &base_size, &len);
	return (len);
}

//int or decimal
size_t	ft_printnbr_base(t_interp *plh, int nbr, char *base)
{
	size_t			len;
	const size_t	base_size = ft_strlen(base);

	if (nbr < 0)
	{
		plh->sign = '-';
		nbr *= (-1);
	}
	len = 0;
	if (plh->plus_flag == 1)
		len += write(1, plh->sign, 1);
	if (nbr >= base_size)
		ft_putnbr_base((unsigned long long)nbr, base, &base_size, &len);
	return (len);
}

size_t	ft_printnbr_u_base(t_interp *plh, unsigned int nbr, char *base)
{
	size_t			len;
	const size_t	base_size = ft_strlen(base);

	len = 0;
	if (plh->plus_flag == 1)
		len += write(1, plh->sign, 1);
	if (nbr >= base_size)
		ft_putnbr_base((unsigned long long)nbr, base, &base_size, &len);
	return (len);
}

size_t	ft_printnbr_x_base(t_interp *plh, int nbr, char *base)
{
	size_t			len;
	const size_t	base_size = ft_strlen(base);

	len = 0;
	if (plh->hash_flag == 1)
		len += write(1, "0x", 2);
	if (nbr >= base_size)
		ft_putnbr_base((unsigned long long)nbr, base, &base_size, &len);
	return (len);
}

size_t	ft_printfnbr_xupp_base(t_interp *plh, int nbr, char *base)
{
	size_t			len;
	const size_t	base_size = ft_strlen(base);

	len = 0;
	if (plh->hash_flag == 1)
		len += write(1, "0X", 2);
	if (nbr >= base_size)
		ft_putnbr_base((unsigned long long)nbr, base, &base_size, &len);
	return (len);
}
