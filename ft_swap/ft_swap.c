/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:53:40 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/09/20 17:05:00 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h> 

void ft_swap(int *a, int *b)
{
	int *temp;

	*temp = *a;
	*a = *b;
	*b = *temp;
}
/*
int main (int argc, char **argv)
{
	int	a;
	int b;

	a = (int) argv[1][0] - '0';
	b = (int) argv[2][0] - '0';
	
	printf("el numero a = %d, y el b = %d\n", a, b);
	ft_swap(&a,&b);
	printf("el numero a = %d, y el b = %d\n", a, b);
	return(0);

}
*/
