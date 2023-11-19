/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:23:47 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/09/20 17:52:07 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int check_str(char *s1, char *s2)
{
	int len;
	int found;
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	len = ft_strlen(s1);
	found = 0;
	while (s1[i])
	{
		while (s2[j] && flag == 0)
		{
			if (s1[i] == s2[j])
			{
				found++;
				flag = 1;
			}
			j++;
		}
	flag = 0;
	i++;
	}
	if (len == found)
		return (1);
	return (0);
}

int main (int argc, char **argv)
{
	int i;
	
	i = 0;
	if (argc != 3)
	{
		write (1,"\n",1);
		return (0);
	}
	if (ft_strlen(argv[1]) == 0)
	{
		write(1, "1\n", 2);
		return (0);
	}
	while(argv[2][i])
	{
		if (argv[2][i] == argv[1][0])
		{	
			if (check_str(argv[1], &argv[2][i]))
			{
				write (1, "1\n", 2);
				return (0);
			}
		}
		i++;
	}
	write (1, "0\n", 2);
	return (0);
}

