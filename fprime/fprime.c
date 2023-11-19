/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:55:17 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/09/25 17:29:33 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int is_prime(int n)
{
	int i;

	i = 2;
	while (i < n)
	{
		if ((n % i) == 0)
			return  (0);
		i++;
	}
	return (1);
}

int main(int argc, char	**argv)
{
	int num;
	int flag;
	int i;

	flag = 0;
	i = 2;
	if (argc != 2)
	{
		printf("\n");
		return(0);
	}
	num = atoi(argv[1]);
	while(i <= num)
	{
		if ((num % i) == 0)
		{
		//	printf("%d divide a %d\n",i, num);	
			if  (is_prime(i))
			{
				if (flag == 1)
					printf("*");
				else
					flag = 1;	
				printf("%d",i);
				num = num / i;
			}
			else 
				i++;	
		}
		else
			i++;
	}
	printf("\n");
	return(0);
}
