/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:12:18 by luciama2          #+#    #+#             */
/*   Updated: 2023/11/02 17:12:20 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "../ft_printf.h"
#include "limits.h"

int	main(void)
{
	int rslt;

	rslt = ft_printf("% +d\n", INT_MAX);
	printf("%d\n", rslt);
}
