#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "main.h"
/* _printf - prints a string
 * @format: string to be printed
 * Return: Length of string
 */

int _printf(const char *format, ...)
{
    
    int i, chr, num, num2, len, count, result;
    
    char *str;
    va_list args;
    i = 0;
    result = 0;

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {
            putchar(format[i]);
	    result++;
        } 

        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
            case 'c':
                chr = va_arg(args, int);
                putchar(chr);

                break;
            case 's':
                str = va_arg(args, char *);
                len = strlen(str);
		
		str = malloc(sizeof(char) * (len + 1));
                
		printf("%s", str);
                break;

            case 'd':
            case 'i':
                num = va_arg(args, int);

                  if (num == 0)
                {
                    putchar('0');
		    result = 1;
                }
                if (num < 0)
                {
                    num *= -1;
                    putchar(45);
		    result++;
                }
                    
                if (num > 0 && num < 10)
                {
                    putchar(num + '0');
		    result = 1;
                }
                else if (num > 0)
                {
                    while (num > 0)
                    {
                        count = num % 10;
                        num2 = num2 * 10 + count;
                        num /= 10;
			result++;
                    }
                    while (num2 > 0)
                    {
                        count = num2 % 10;
                        putchar(count + '0');
                        num2 /= 10;
                    }    
                    
                }
 
                break;
            case '%':
                putchar(37);
                break;
	    default:
		putchar(format[i]);
		break;
            }
        }
        i++;
    }



    return result;
}
