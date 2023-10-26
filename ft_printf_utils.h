/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:02:25 by luciama2          #+#    #+#             */
/*   Updated: 2023/10/26 18:02:26 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_UTILS_H
# define PRINTF_UTILS_H
# include <ctype.h>

typedef struct placeholder
{
	int		*plus_flag;
	int		*hash_flag;
	int		*space_flag;
	size_t	*i;
	char	*format;
}

#endif