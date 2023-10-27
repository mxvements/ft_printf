/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:50:39 by luciama2          #+#    #+#             */
/*   Updated: 2023/10/27 16:50:40 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf_utils.h"

static int	ft_printchar(interp_var *plh, char c)
{
	//if space flag, print also a space
	return (write(1, c, 1)); 
}

static int ft_printstr(interp_var *plh, char *s)
{

}

static int ft_printnbr_base(interp_var *plh, void *nbr, char *base)
{

}

static int ft_printnbr_base(interp_var *plh, int nbr, char *base)
{

}

static int ft_printnbr_base(interp_var *plh, unsigned int nbr, char *base)
{

}

static int ft_printnbr_lower_base(interp_var *plh, int nbr, char *base)
{

}

static int ft_printfnbr_upper_base(interp_var *plh, int nbr, char *base)
{

}