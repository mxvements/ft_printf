/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:24:13 by luciama2          #+#    #+#             */
/*   Updated: 2023/11/02 21:55:44 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** int ft_printnbr_vptr_base(void *nbr, char *base)
 * @brief Function to handle the a void pointer (specifier %p) interpolated 
 * variable. Prints a memory address (on hex base) of an address passed on 
 * base 10.
 * No flags apply to this specifier
 * @param nbr, void *, memory address passed on base10
 * @param base, number base 16 to print address as hex
 * @return int, length printed on the standard output
 */
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

/** int ft_print_base (t_interp *plh, int nbr, char *base)
 * @brief Function to handle the specifier 'i' and 'd' on the printf function.
 * It handles negative numbers updating the interpolated var struct and handles
 * the sign flag and space flag, printing the corresponding char when applicable
 * Prints the number using ft_putnbr_base funct. 
 * @param plh, ptr to the interpolated var strucct
 * @param nbr, nbr to print
 * @param base, base of number
 * @return int 
 */
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

/** int ft_printnbr_u_base(t_interp *plh, unsginned nbr, char *base)
 * @brief Function to handle the 'u' specifier on the printf function.
 * Handles the applicable flags (only plus flag). Space flag not applicable.
 * Prints the number using ft_putnbr_base.
 * @param plh, pointer to the interpolated var struct
 * @param nbr, nbr to print
 * @param base, number base
 * @return int, length of the string printed on the standard output
 */
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
	ft_putnbr_base((unsigned long long)nb, base, &base_size, &len);
	return (len);
}

/** ft_printnbr_x_base(t_interp *plh, unsinged int nbr, char *base)
 * @brief Function to handle the 'x' specifier on the printf function.
 * It also handles the applicable flags for the specifier (only '#').
 * @param plh, pointer to the interpolated var struct
 * @param nbr, nbr (on base 10) of the mem address to print
 * @param base, base16 in lowercase 
 * @return int, length of the printed string
 */
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
/** ft_printnbr_xupp_base(t_interp *plh, unsinged int nbr, char *base)
 * @brief Function to handle the 'X' specifier on the printf function.
 * It also handles the applicable flags for the specifier (only '#').
 * @param plh, pointer to the interpolated var struct
 * @param nbr, nbr (on base 10) of the mem address to print
 * @param base, base16 in uppercase
 * @return int, length of the printed string
 */
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
