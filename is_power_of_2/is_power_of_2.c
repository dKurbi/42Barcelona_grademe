/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:13:09 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/09/20 17:21:31 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>

int is_power_of_2(unsigned int n)
{
	int temp;
	if (n == 0)
		return (0);
	while(n > 2)
	{
		temp = n / 2;
		if (temp * 2 < n)
			return (0);
		n = temp;
	}
	return (1);
}
/*
int main (int argc, char **argv)
{
	unsigned int i;

	i = (unsigned int) atoi(argv[1]);

	if (is_power_of_2(i))
		printf("el numero %d es potencia de 2", i);
	else
		printf("el numero %d NO es potencia de 2", i);
	return (0);
}*/
