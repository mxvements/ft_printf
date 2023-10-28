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

static size_t	ft_printchar(interp_var *plh, char c)
{
	size_t	count;

	count = 0;
	if (plh->space_flag == 1)
		count += write(1, ' ', 1);
	count += write(1, c, 1);
	return (count); 
}

static size_t ft_printstr(interp_var *plh, char *s)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (plh->space_flag == 1)
		count += write(1, ' ', 1);
	while (s[i++] != '\0')
		count += write(1, s[i], 1);
	return (count);	
}
