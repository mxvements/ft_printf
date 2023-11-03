/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:24:34 by luciama2          #+#    #+#             */
/*   Updated: 2023/11/02 22:52:46 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "../ft_printf.h"
#include "limits.h"

void	printf_purple(char *s)
{
	printf("\033[0;35m");
	printf("%s", s);
	printf("\033[0;0m\n");
	return ;
}

int	main(void)
{
	int		rslt;

	//%c
	printf_purple("___USE OF (%%c) VARIABLE INTERPOLATION___");	
	ft_printf("_FLAGS: n/a, ' 'results in undefined behavior_\n");
	rslt = ft_printf("(%c) _ (%c) _ (%c) _ (%c) _ (%c) _ (%c)\n", 'a', '\t', '\0', '\x7F', CHAR_MIN, CHAR_MAX);
	ft_printf("_LEN: %d\n", rslt);
	rslt = printf("(%c) _ (%c) _ (%c) _ (%c) _ (%c) _ (%c)\n", 'a', '\t', '\0', '\x7F', CHAR_MIN, CHAR_MAX);
	printf("_LEN: %d\n", rslt);
	printf("\n");

	//%d
	printf_purple("___USE OF (%%d) VARIABLE INTERPOLATION___");
	ft_printf("_FLAGS: (%% d), (%%+d), ' ' is ignored when '+' is present_\n");
	rslt = ft_printf("(%d) _ (% d) _ (% d) _ (%+d)\n", INT_MIN, INT_MAX, INT_MIN, INT_MAX);
	ft_printf("_LEN: %d\n", rslt);
	rslt = printf("(%d) _ (% d) _ (% d) _ (%+d)\n", INT_MIN, INT_MAX, INT_MIN, INT_MAX);
	ft_printf("_LEN: %d\n", rslt);
	printf("\n");

	//%i
	printf_purple("___USE OF (%%i) VARIABLE INTERPOLATION___");
	ft_printf("_FLAGS: (%% i), (%%+i), ' ' is ignored when '+' is present_\n");
	rslt = ft_printf("(%i) _ (% i) _ (% i) _ (%+i)\n", INT_MIN, INT_MAX, INT_MIN, INT_MAX);
	ft_printf("_LEN: %i\n", rslt);
	rslt = printf("(%i) _ (% i) _ (% i) _ (%+i)\n", INT_MIN, INT_MAX, INT_MIN, INT_MAX);
	ft_printf("_LEN: %i\n", rslt);
	printf("\n");

	//%s
	printf_purple("___USE OF (%%s) VARIABLE INTERPOLATION___");
	ft_printf("_FLAGS: n/a, ' ' results in undefined behavior\n");
	char	*emptystr = "";
	char	*smplestr = "This is a simple test.\tSecond sentence.";
	char	*nullstr = NULL;
	rslt = ft_printf("(%s) - (%s) - (NULL %s)\n", emptystr, smplestr, nullstr);
	ft_printf("_LEN: %i\n", rslt);
	rslt = printf("(%s) - (%s) - (NULL %s)\n", emptystr, smplestr, nullstr);
	ft_printf("_LEN: %i\n", rslt);
	printf("\n");

	//%u
	printf_purple("___USE OF (%%u) VARIABLE INTERPOLATION___");
	ft_printf("_FLAGS: n/a, ' ' and '+' results undefined behaviour\n");
	rslt = ft_printf("(%u) - (%u)\n", (unsigned int)17, UINT_MAX);
	ft_printf("_LEN: %i\n", rslt);
	rslt = printf("(%u) - (%u)\n", (unsigned int)17, UINT_MAX);
	ft_printf("_LEN: %i\n", rslt);
	printf("\n");

	//%x
	printf_purple("___USE OF (%%x) VARIABLE INTERPOLATION___");
	ft_printf("_FLAGS: (%%#x)\n");
	rslt = ft_printf("(%#x) - (%x) - (%#x) - (%x) - (%#x)\n", 0, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
	ft_printf("_LEN: %i\n", rslt);
	rslt = printf("(%#x) - (%x) - (%#x) - (%x) - (%#x)\n", 0, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
	ft_printf("_LEN: %i\n", rslt);
	printf("\n");

	//%X
	printf_purple("___USE OF (%%X) VARIABLE INTERPOLATION___");
	ft_printf("_FLAGS: (%%#X)\n");
	rslt = ft_printf("(%#X) - (%X) - (%#X) - (%X) - (%#X)\n", 0, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
	ft_printf("_LEN: %i\n", rslt);
	rslt = printf("(%#X) - (%X) - (%#X) - (%X) - (%#X)\n", 0, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
	ft_printf("_LEN: %i\n", rslt);
	printf("\n");

	//%p, void *, prints the pointer address
	printf_purple("___USE OF (%%p) VARIABLE INTERPOLATION___");
	ft_printf("_FLAGS: n/a, ' ' and '+' results in undefined behavior\n");
	void	*ptr1 = &emptystr;
	void	*ptr2 = &smplestr;
	void	*ptr3 = &nullstr;
	rslt = ft_printf("(%p) - (%p) - (%p) - (%p)\n", (void *)0, ptr1, ptr2, ptr3);
	ft_printf("_LEN: %i\n", rslt);
	rslt = printf("(%p) - (%p) - (%p) - (%p)\n", (void *)0, ptr1, ptr2, ptr3);
	ft_printf("_LEN: %i\n", rslt);
	printf("\n");
	
	//%%
	printf_purple("___USE OF (%%%%) VARIABLE INTERPOLATION___");
	ft_printf("_FLAGS: n/a\n");
	rslt = ft_printf("(%%.%%:%%.%%) - (%%c%%x%%d)\n");
	ft_printf("_LEN: %i\n", rslt);
	rslt = printf("(%%.%%:%%.%%) - (%%c%%x%%d)\n");
	ft_printf("_LEN: %i\n", rslt);

	return (0);
}
