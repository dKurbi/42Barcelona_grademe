/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:16:25 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/09/25 16:51:27 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_prime(int num)
{
	int	i;

	i = 2;

	while (i < num)
	{
		if ((num % i) == 0)
			return (0);
		i++;
	}
	return (1);
}

void ft_putnbr(int n)
{
	char c;

	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
		return;
	} 
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
int ft_atoi(char *str)
{
	int	i;
	int num;

	i = 0;
	num = 0;
	while (str[i])
	{
		num = num * 10 + (str[i] -'0');
		i++;
	}
	return (num);
}

int main(int argc, char **argv)
{
	int sum;
	int num;
	int i;
	
	i = 2;
	sum = 0;
	if (argc != 2)
	{
		ft_putnbr(0);
		write(1,"\n",1);
		return (0);
	}
	else if (argv[1][0] == '-')
		ft_putnbr(0);
	else
	{
		num = ft_atoi(argv[1]);		
		while (i <= num)
		{
			if (is_prime(i))
				sum = sum + i;
			i++;
		}
		ft_putnbr(sum);
	}
	write(1,"\n",1);
	return(0);
}
