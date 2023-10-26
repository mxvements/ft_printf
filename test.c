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

	int	rslt;

	//%c

	//%d
	rslt = printf("+ d: %d\n", 17);
	printf("+ d, len: %d\n", rslt);

	//%i

	//%s

	//%u

	//%x
	rslt = printf("x: %x\n", 17);
	printf("x, len: %d\n", rslt);
	rslt = printf("#x: %#x\n", 17);
	printf("#x, len: %d\n", rslt);

	//%X
	rslt = printf("X: %X\n", 17);
	printf("X, eln: %d\n %X", rslt);
	rslt = printf("#X: %#X\n", 17);
	printf("#X, len: %d\n", rslt);

	//%p

	//%%
	rslt = printf("perc: %       %c\n");
	printf("perc, len: %d\n", rslt);


	
}
