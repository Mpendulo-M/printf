#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "main.h"
/* _printf - prints a string
 * @format: string to be printed
 * Return: Length of string
 */

int _printf(const char *format, ...)
{
    
    int i, chr, num, num2, len, n, count;
    
    char *str;
    
    va_list args;

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {
            putchar(format[i]);
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
                for (n = 0; n < len; n++)
                {
                    putchar(str[n]);
                }
                break;

            case 'd':
            case 'i':
                num = va_arg(args, int);
                  if (num == 0)
                {
                    putchar('0');
                }
                if (num < 0)
                {
                    num *= -1;
                    putchar(45);
                }
                    
                if (num > 0 && num < 10)
                {
                    putchar(num + '0');
                }
                else if (num > 0)
                {
                    while (num > 0)
                    {
                        count = num % 10;
                        num2 = num2 * 10 + count;
                        num /= 10;
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



    return i;
}