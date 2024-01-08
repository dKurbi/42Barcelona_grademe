/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:30:28 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/01/08 21:08:49 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int ft_putchar(char c)
{
	return(write(1,&c,1));
}

int ft_putstr(char *str)
{
	int	i;

	i = 0; 
	if (str)
	{
		while(str[i])
			ft_putchar(str[i++]);
		return (i);
	}
	return (ft_putstr("(null)"));
}
int error(va_list *ap)
{
	va_end (*ap);
	return (-1);
}


int write_hexa(unsigned int num)
{
	char n[16] = "0123456789abcdef";

	if (num < 16)
	{
		if (ft_putchar(n[num]) == -1)
			return (-1);
	}
	else
	{
		write_hexa(num / 16);
		write_hexa(num % 16);
	}
	return (0);
}
int ft_puthexa(unsigned int num)
{	
	int rtn;
	unsigned int tmp;

	rtn = 0;
	tmp = num;
	while (tmp != 0)
	{
		rtn++;
		tmp /= 16;
	}
	if (num == 0)
		rtn++;
	if (write_hexa(num) == -1)
		return (-1);
	return (rtn);
}


int write_num(int num)
{
	if (num < 10)
	{
		if (ft_putchar(num + '0') == -1)
			return (-1);
	}
	else
	{
		write_num(num / 10);
		write_num(num % 10);
	}
	return (0);
}

int ft_putnumber(int num)
{	
	int rtn;
	int tmp;
	
	if (num == INT_MIN)
		return(ft_putstr("-2147483648"));
	rtn = 0;
	if (num < 0)
	{
		rtn++;
		num = -num;
		if (ft_putchar('-') == -1)
			return (-1);
	}
	tmp = num;
	while (tmp != 0)
	{
		rtn++;
		tmp /= 10;
	}
	if (num == 0)
		rtn++;
	if (write_num(num) == -1)
		return (-1);
	return (rtn);
}

int ft_putarg(const char *str, int *i, va_list ap)
{
	if (str[*i] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (str[*i] == 'd')
		return (ft_putnumber(va_arg(ap, int)));
	else if (str[*i] == 'x')
		return (ft_puthexa(va_arg(ap, int)));
	return (0);
}

int ft_printf(const char *str, ...)
{
	va_list	ap;
	int 	i;
	int		rtn;
	int		rtn_f;

	rtn = 0;
	i = 0;
	if (str)
	{
		va_start(ap, str);
		while (str[i])
		{
			if (str[i] != '%')
			{
				if (ft_putchar(str[i]) ==-1)
					return (error(&ap));
				else
					rtn++;
			}
			else
			{
				i++;
				rtn_f = ft_putarg(str, &i, ap);
				if (rtn_f == -1)
					return (error(&ap));
				else
					rtn+= rtn_f;
			}
		i++;
		}
	return(rtn);
	}
	return (-1);
}
/*
int main(void)
{
	int	i;
	int j;
	int n;

	ft_putchar('c');
	ft_putchar('\n');
	ft_putstr("hola\n");
	n = -0;
	i =	ft_printf("el string es %s y el numero es %d y en hexa es %x\n", "", n, n);
	j = printf("el string es %s y el numero es %d y en hexa es %x\n", "", n, n);
	printf("el ft_printf devolvio %d, y el printf %d\n", i, j);
	j = ft_puthexa(n);
	printf("\nputhexa devolvio %d\n", j);
	i = ft_printf("el minimo int es %d\n", -2147483648);
 	j = printf("el minimo int es %ld\n", -2147483648);
	printf("el ft_printf devolvio %d, y el printf %d\n", i, j);

}
*/
