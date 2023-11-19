/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:57:46 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/09/25 12:38:42 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
	int	i;

	i = 0;

	while(str[i])
		i++;
	return (i);
}
int check_contained (char *str, char *rep_str)
{
	int i;

	i = 0;
	while (rep_str[i] != '\0')
	{
		if (rep_str[i] != str[i])
			return(0);
		i++;
	}	
	return (1);
}
int is_contained(char *str, char *rep_str)
{
	int	i;

	i = 0;
	if (ft_strlen(rep_str) < 2)
		return (1);
	while(str[i] != '\0')
	{
		if (str[i] == rep_str[0])
		{
			if (check_contained (&str[i], rep_str))
				return (1);
		}
		i++;
	}
	return (0);
}
int main(int argc, char	**argv)
{
	int	i;

	if (argc != 4 || !is_contained(argv[1], argv[2]))
	{
		write(1,"\n",1);
		return(0);
	}
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] != argv[2][0])
			write(1,&argv[1][i],1);
		else 
			write(1, &argv[3][0], 1);
		i++;
	}
	write (1,"\n",1);
	return (0);
}
