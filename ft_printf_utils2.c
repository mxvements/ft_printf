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

# include "ft_printf_utils.h"

//void *-> pointer address
//no flags apply to this specifier
//since its a memory address, should always be positive
static size_t ft_printnbr_v_base(t_interp *plh, void *nbr, char *b)
{
	size_t			len;
	int				nb;
	const size_t	b_size = ft_strlen(b);

	nb = nbr; //check this
	len = 0;
	len += write(1, "0x", 2);
	if (nb >= b_size)
		ft_putnbr_base(nb, b, &b_size, &len);
	return (len);
}

static size_t ft_printnbr_base(t_interp *plh, int nbr, char *b)
{
	size_t			len;
	const size_t	b_size = ft_strlen(b);

	if (nbr < 0)
	{
		plh->sign = '-';
		nbr *= (-1);
	}
	len = 0;
	if (plh->plus_flag == 1)
		len += write(1, plh->sign, 1);
	if (nbr >= b_size)
		ft_putnbr_base((unsigned int)nbr, b, &b_size, &len);
	return (len);
}

static size_t ft_printnbr_u_base(t_interp *plh, unsigned int nbr, char *b)
{
	size_t			len;
	const size_t	b_size = ft_strlen(b);

	len = 0;
	if (plh->plus_flag == 1)
		len += write(1, plh->sign, 1);
	if (nbr >= b_size)
		ft_putnbr_base(nbr, b, &b_size, &len);
	return (len);
}

static size_t ft_printnbr_lower_base(t_interp *plh, int nbr, char *b)
{
	size_t			len;
	const size_t	b_size = ft_strlen(b);

	len = 0;
	return (len);
}

static size_t ft_printfnbr_upper_base(t_interp *plh, int nbr, char *b)
{
	size_t	len;

	len = 0;
	return (len);
}
