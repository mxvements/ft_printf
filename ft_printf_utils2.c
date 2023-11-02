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
int	ft_printnbr_vptr_base(void *nbr, char *base)
{
	int					len;
	unsigned long long	nb;
	size_t				base_size;

	base_size = ft_strlen(base);
	nb = (unsigned long long)nbr;
	len = 0;
	len += write(1, "0x", 2);
	ft_putnbr_base(nb, base, &base_size, &len);
	return (len);
}

//int or decimal
int	ft_printnbr_base(t_interp *plh, int nbr, char *base)
{
	int				len;
	size_t			base_size;
	long long		nb;

	base_size = ft_strlen(base);
	nb = (long long)nbr;
	if (nb < 0)
	{
		plh->plus_flag = 1;
		plh->sign = '-';
		nb *= (-1);
	}
	len = 0;
	if (plh->plus_flag == 1)
		len += write(1, &(plh->sign), 1);
	if (plh->space_flag == 1 && plh->plus_flag == 0)
		len += write(1, " ", 1);
	ft_putnbr_base((unsigned long long)nb, base, &base_size, &len);
	return (len);
}

int	ft_printnbr_u_base(t_interp *plh, unsigned int nbr, char *base)
{
	int				len;
	size_t			base_size;
	long long		nb;

	base_size = ft_strlen(base);
	nb = (long long)nbr;
	len = 0;
	if (plh->plus_flag == 1)
		len += write(1, &(plh->sign), 1);
	ft_putnbr_base((unsigned long long)nbr, base, &base_size, &len);
	return (len);
}

int	ft_printnbr_x_base(t_interp *plh, unsigned int nbr, char *base)
{
	int				len;
	size_t			base_size;
	long long		nb;

	base_size = ft_strlen(base);
	nb = (long long)nbr;
	len = 0;
	if (plh->hash_flag == 1 && nbr != 0)
		len += write(1, "0x", 2);
	ft_putnbr_base((unsigned long long)nb, base, &base_size, &len);
	return (len);
}

int	ft_printfnbr_xupp_base(t_interp *plh, unsigned int nbr, char *base)
{
	int				len;
	size_t			base_size;
	long long		nb;

	base_size = ft_strlen(base);
	nb = (long long)nbr;
	len = 0;
	if (plh->hash_flag == 1 && nbr != 0)
		len += write(1, "0X", 2);
	ft_putnbr_base((unsigned long long)nb, base, &base_size, &len);
	return (len);
}
