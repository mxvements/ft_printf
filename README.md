<div align="center">
    <img src="https://img.shields.io/badge/status-finished-success?color=00ABAD&style=flat-square" />
    <img src="https://img.shields.io/badge/started-23%20%2F%2010%20%2F%202023-success?color=00ABAD&style=flat-square" />
    <img src="https://img.shields.io/badge/score-110%20%2F%20100-success?color=00ABAD&style=flat-square" />
    <img src="https://img.shields.io/github/languages/top/mxvements/ft_printf?color=00ABAD&style=flat-square" />
    <img src="https://img.shields.io/github/last-commit/mxvements/ft_printf?color=00ABAD&style=flat-square" />
    <br>
    <a href='https://www.linkedin.com/in/luciami' target="_blank"><img alt='Linkedin' src='https://img.shields.io/badge/LinkedIn-100000?style=flat-square&logo=Linkedin&logoColor=white&labelColor=1323233&color=323233'/></a>
    <a href='https://profile.intra.42.fr/users/luciama2' target="_blank"><img alt='42' src='https://img.shields.io/badge/Madrid-100000?style=flat-square&logo=42&logoColor=white&labelColor=323233&color=323233'/></a>
    <br>
</div>

# ft_printf
The goal of this project is pretty straightforward: to recode printf(). The projects is about learning variable numbber of arguments (variadic functions), as well as adding a couple more functions to the ft_libft.

| Program name | libftprintf.a |
| ----- | ------|
| Turn in files | Makefile, *.h, *.c, */*.h, */*.c |
| Makefile | NAME, all, clean, fclean, re and bonus (if done) |
| External functs | malloc, free, write, va_start, va_arg, va_copy, va_end |
| Libft authorized | Yes |
| Description | Write a library that contains ft_printf(), a function that will mimic the original printf() |

* Mandatory part
	-  Don’t implement the buffer management of the original printf().
	-  Your function has to handle the following conversions: cspdiuxX%
	-  Your function will be compared against the original printf().
	-  You must use the command ar to create your library. Using the libtool command is forbidden.
	-  Your libftprintf.a has to be created at the root of your repository.
	-  You have to implement the following conversions:
		-  %c Prints a single character.
		-  %s Prints a string (as defined by the common C convention).
		-  %p The void * pointer argument has to be printed in hexadecimal format.
		-  %d Prints a decimal (base 10) number.
		-  %i Prints an integer in base 10.
		-  %u Prints an unsigned decimal (base 10) number.
		-  %x Prints a number in hexadecimal (base 16) lowercase format.
		-  %X Prints a number in hexadecimal (base 16) uppercase format.
		-  %% Prints a percent sign.
* Bonus
	-  Manage any combination of the following flags: ’-0.’ and the field minimum width under all conversions.
	-  Manage all the following flags: ´#´ ´ ´ ´+´ (Yes, one of them is a space)

Note: if you plan to implement the bonus part, think abouut the impllementation of your extra features from the start. This way, youu will avoid the pitfalls of a naive approach.

# How to use
1 - Clone the repository
```
git clone git@github.com:mxvements/ft_printf.git 
```
2 - Enter the project folder and run `make`, Makefile rules:
```
`make` - compile printf mandatory files
`make bonus` - compile printf bonus files
`make all` - compile all (mandatory + bonus) files
`make clean` - delete all *.o files
`make fclean` - delete all *.o & *.a (executable) files
`make re` - use fclean + all, recompile printf
```
3 - To incluide it in your code, include the header
````
# include "ft_printf.h"
````
 # Notes
 ## On the printf() specifiers and flags
 1 - Specifiers and output
| sp | ft_printf() | description |
| -- | ----------- | -------- |
| %c |  √ | character | 
| %d or %i | √ | signed decimal integer | 
| %e |  | scientific noation (mantissa/exponent) using e char |
| %E |  | Scientific notation (mantissa/exponent) using E char | 
| %f |  | decimal floating point | 
| %g |  | uses the shorter of %e or %f | 
| %G |  | uses the shorter of %E or %f | 
| %o |  | signed octal | 
| %s | √ | string of characters | 
| %u | √ | unsigned decimal integer | 
| %x | √ | unsigned hexadecimal integer | 
| %X | √ | unsigned hexadecimal integer (capital letters) | 
| %p | √ | pointer address | 
| %n |  | nothing printed | 
| % | √ | % char | 
 
 2 - Flags and description
| specifier | ft_printf() | description |
| --------- | ----------- | ----------- |
| +	| √ |  forces to precede the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a -ve sign.
| (space) | √ |  if no sign is going to be written, a blank spcace is inserted before the value
| # | √ |  %#o %#x %#X -> value precede with 0, 0x, 0X values != 0 / %#e %#E %#f -> forces to contain a decimal point even if no digits would follow / %#g %#G -> the same as w/ e or E, removing trailing 0
| 0 |  |  left-pads the number with zeros (0) instead of spaces, where padding is specified (see width sub-specifier)

## On variadic functions

**void	va_start(va_list argument_list, last_known_parameter);**

- DESCRIPTION
: va_start() macro, intializes your argument_list for use by va_arg() and va_end(), and must be called first. The last_known_parameter is the name of the last known parameter of the calling function, here, ft_printf();

**argument_type	va_arg(va_list argument_list, argument_type)**

- DESCRIPTON: everytime it is called, it modifies argument_list so that the next time is is called, it will return the next argument.
- RETURN VALUE: Expands to an expression that has the type and value of the next arg. in the call. The 1st use of the va_arg() macro after that of the va_start() macro returns the argument after last_known_parameter.
- NOTES: Successive invocations return the values of the remaining arguments. It is your job to make sure you're giving va_arg() the correct type of variable to return, it will assume you know what's being sent.

**void va_end(va_list argument_list)** 

- DESCRIPTION: Each invocation of va_start() must be matched by a corresponding invocation of va_end() in the same function. After the call to va_end(), the variable argument_list is undefined.

# Other

## Norminete
At 42 School, it is expected that almost every project is written in accordance with the Norm, which is the coding standard of the school.

<a href="https://github.com/42School/norminette">
<a>Norminette's repository</a>

```
- No for, do...while, switch, case, goto, ternary operators and variable-length arrays are allowed
- Each function must be a maximum of 25 lines, not counting the function's curly brackets
- Each line must be at most 80 columns wide, comments included
- A function can take 4 named parameters maximum
- No assigns and declarations in the same line (unless static or const)
- You can't declare more than 5 variables per function
- ...
```
## Aknowledgments
- This video by Nikito: https://www.youtube.com/watch?v=Hb2m7htiKWM

# License
[MIT License](https://github.com/mxvements/ft_license/blob/main/LICENSE.txt)
