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

# include "ft_printf_utils.h"

static int	ft_printchar(interp_var *plh, char c)
{
	//if space flag, print also a space
	return (write(1, c, 1)); 
}

static int ft_printstr(interp_var *plh, char *s)
{

}
