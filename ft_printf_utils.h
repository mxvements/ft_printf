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
# include <stdarg.h>
# include <ctype.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	interpolated_var
{
	int		plus_flag;
	int		hash_flag;
	int		space_flag;
	char	specifier;
}				interp_var;

static int		put_interp_var(interp_var *plh, va_list vargs);
static void 	reset_interp_var(interp_var *plh);
static int		check_interp_var(interp_var *plh);
static size_t	update_interp_var(const char *s, interp_var *plh);
static int		ft_printchar(interp_var *plh, char c);
static int		ft_printstr(interp_var *plh, char *s);
static int		ft_printnbr_base(interp_var *plh, void *nbr, char *base);
static int		ft_printnbr_base(interp_var *plh, int nbr, char *base);
static int		ft_printnbr_base(interp_var *plh, unsigned int nbr, char *base);
static int		ft_printnbr_lower_base(interp_var *plh, int nbr, char *base);
static int		ft_printfnbr_upper_base(interp_var *plh, int nbr, char *base);

#endif