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

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H
# include <ctype.h>
# include <stdarg.h>
# include <ctype.h>
# include <stdio.h>
# include <unistd.h>

typedef struct interpolated_var
{
	int		plus_flag;
	int		hash_flag;
	int		space_flag;
	char	specifier;
	char	sign;
}	t_interp;

static int		put_interp_var(t_interp *plh, va_list vargs);
static void		reset_interp_var(t_interp *plh);
static int		check_interp_var(t_interp *plh);
static size_t	update_interp_var(const char *s, t_interp *plh);
static size_t	ft_printchar(t_interp *plh, char c);
static size_t	ft_printstr(t_interp *plh, char *s);
static size_t	ft_printnbr_v_base(t_interp *plh, void *nbr, char *b);
static size_t	ft_printnbr_base(t_interp *plh, int nbr, char *b);
static size_t	ft_printnbr_u_base(t_interp *plh, unsigned int nbr, char *b);
static size_t	ft_printnbr_lower_base(t_interp *plh, int nbr, char *b);
static size_t	ft_printfnbr_upper_base(t_interp *plh, int nbr, char *b);
static void		ft_putnbr_base(unsigned int nb, char *b, size_t *sb, size_t *l);

#endif