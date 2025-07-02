#include <unistd.h>
#include <limits.h>
#include <stdarg.h>

int    put(char c)
{
    int i = 0;
    i += write(1, &c, 1);
    return(i);
}

int ft_putstr(char *s)
{
    int c = 0;
    if (!s)
         c += ft_putstr("(null)");
    while (*s)
        c += put(*s++);
    return c;
}

int    putn(int n)
{
    int c = 0;
    if(n == INT_MIN)
    {
        c += ft_putstr("-2147483648");
    }
    if(n < 0)
    {
        c += put('-');
        n = -n;
    }
    if(n > 9)
    {
        c += putn(n / 10);
    }
    c += put((n % 10) + 48);
    return(c);
}

int    put_hex(unsigned int nb)
{
    char *base = "0123456789abcdef";
    int c = 0;
    if(nb >= 16)
    {
        c += put_hex(nb / 16);
        c += put_hex(nb % 16);
    }
    else
        c += put(base[nb % 16]);
    return(c);
}
int ft_printf(const char *format, ...)
{
    va_list args;
    int c = 0;
    int i = 0;

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
       {
            if (format[i + 1] == 'c')
                c += put((char)va_arg(args, int));
            else if (format[i + 1] == 'd')
                c += putn(va_arg(args, int));
            else if (format[i + 1] == 'x')
                c += put_hex(va_arg(args, unsigned int));
            i++;
        }
        else
        {
            c += put(format[i]);
        }
        i++;
    }
    va_end(args);
    return c;
}
