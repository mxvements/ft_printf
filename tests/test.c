/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:24:34 by luciama2          #+#    #+#             */
/*   Updated: 2023/10/26 12:24:36 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "../ft_printf.h"
#include "limits.h"

int	main(void)
{
	/* printf placeholders (specifier & output)
	->	%c			character
	->	%d or %i	signed decimal integer
		%e			scientific noation (mantissa/exponent) using e char
		%E			Scientific notation (mantissa/exponent) using E char
		%f			decimal floating point
		%g			uses the shorter of %e or %f
		%G			uses the shorter of %E or %f
		%o			signed octal
	->	%s			string of characters
	->	%u			unsigned decimal integer
	->	%x			unsigned hexadecimal integer
	->	%X			unsigned hexadecimal integer (capital letters)
	->	%p			pointer address
		%n			nothing printed
	->	%				% char
	*/

	/* printf flags & description
		-			left-justify within the given field width
					right justification is the default
	->	+			forces to precede the result with a plus or minus sign 
					(+ or -) even for positive numbers. By default, only 
					negative numbers are preceded with a -ve sign.
	->	(space)		if no sign is going to be written, a blank spcace is 
					inserted before the value
	->	#			%#o %#x %#X		value precede with 0, 0x, 0X values != 0
					%#e %#E %#f		forces to contain a decimal point even
									if no digits would follow
					%#g %#G		the same as w/ e or E, removing trailing 0
		0			left-pads the number with zeros (0) instead of spaces, 
					where padding is specified (see width sub-specifier)
	
	*/

	int		rslt;

	//%c
	ft_printf("___USE OF (%%c) VARIABLE INTERPOLATION___\n");
	ft_printf("_FLAGS: n/a, ' 'results in undefined behavior_\n");
	rslt = ft_printf("(%c) _ (%c) _ (%c) _ (%c) _ (%c) _ (%c)\n", 'a', '\t', '\0', '\x7F', CHAR_MIN, CHAR_MAX);
	ft_printf("_LEN: %d\n", rslt);
	rslt = printf("(%c) _ (%c) _ (%c) _ (%c) _ (%c) _ (%c)\n", 'a', '\t', '\0', '\x7F', CHAR_MIN, CHAR_MAX);
	printf("_LEN: %d\n", rslt);
	printf("\n");

	//%d
	ft_printf("___USE OF (%%d) VARIABLE INTERPOLATION___\n");
	ft_printf("_FLAGS: (%% d), (%%+d), ' ' is ignored when '+' is present_\n");
	rslt = ft_printf("(%d) _ (% d) _ (% d) _ (%+d)\n", INT_MIN, INT_MAX, INT_MIN, INT_MAX);
	ft_printf("_LEN: %d\n", rslt);
	rslt = printf("(%d) _ (% d) _ (% d) _ (%+d)\n", INT_MIN, INT_MAX, INT_MIN, INT_MAX);
	ft_printf("_LEN: %d\n", rslt);
	printf("\n");

	//%i
	ft_printf("___USE OF (%%i) VARIABLE INTERPOLATION___\n");
	ft_printf("_FLAGS: (%% i), (%%+i), ' ' is ignored when '+' is present_\n");
	rslt = ft_printf("(%i) _ (% i) _ (% i) _ (%+i)\n", INT_MIN, INT_MAX, INT_MIN, INT_MAX);
	ft_printf("_LEN: %i\n", rslt);
	rslt = printf("(%i) _ (% i) _ (% i) _ (%+i)\n", INT_MIN, INT_MAX, INT_MIN, INT_MAX);
	ft_printf("_LEN: %i\n", rslt);
	printf("\n");

	//%s
	char	*emptystr = "";
	char	*smplestr = "This is a simple test.\tSecond sentence.";
	char	*nullstr = NULL;
	ft_printf("___USE OF (%%s) VARIABLE INTERPOLATION___\n");
	ft_printf("_FLAGS: n/a, ' ' results in undefined behavior\n");
	rslt = ft_printf("(%s) - (%s) - (NULL %s)\n", emptystr, smplestr, nullstr);
	ft_printf("_LEN: %i\n", rslt);
	rslt = printf("(%s) - (%s) - (NULL %s)\n", emptystr, smplestr, nullstr);
	ft_printf("_LEN: %i\n", rslt);
	printf("\n");

	//%u

	//%x
	//rslt = printf("x: %x\n", 17);
	//printf("x, len: %d\n", rslt);
	//rslt = printf("#x: %#x\n", 17);
	//printf("#x, len: %d\n", rslt);
	//printf("\n");

	//%X
	//rslt = printf("X: %X\n", 17);
	//printf("X, len: %d", rslt);
	//rslt = printf("#X: %#X\n", 17);
	//printf("#X, len: %d\n", rslt);
	//printf("\n");

	//%p, void *, prints the pointer address
	//warning: flag ' ' results in undefined behavior with 'p' conversion specifier
	//warning: flag '+' results in undefined behavior with 'p' conversion specifier 
	/*int		nbr = 17;
	void 	*ptr = &nbr;
	char	*base =  "0123456789ABCDEF";
	int 	base_size = 16;
	int		len;
	int		*mem = &nbr;
	rslt = printf("p: %p\n", ptr);
	printf("p, len: %d", rslt);
	printf("prueba de imprimir ptr como int: %u\n", (unsigned int)mem);
	printf("prueba de imprimir ptr como int: %lli\n", (long long)mem);
	printf("prueba de imprimir ptr como int: %lli\n", (unsigned long long)mem);
	printf("\n");*/

	//%%
	/*rslt = printf("percentage: %%%c\n", 'a');
	printf("percentage, len: %d\n", rslt);
	printf("\n");*/

	return (0);
}
