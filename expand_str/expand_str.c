/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:58:51 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/09/25 13:22:24 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void ft_putchar(char c)
{
	write (1,&c,1);
}

void ft_putspace(void)
{
	write (1,"   ",3);
}

int is_last_word(char *str, int pos)
{
	int	i;

	i = pos;
	while(str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return(i);
		i++;
	}
	return (-1);
}
int main(int argc, char **argv)
{
	int		i = 0;
	char	*str;

	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}	
	i = 0;
	str = argv[1];
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			ft_putchar(str[i]);
			i++;
		}
		else if (str[i] == ' ' || str[i] == '\t') 
		{
			i = is_last_word(str, i);
			if (i == -1)
			{
				ft_putchar('\n');
				return(0);
			}
			ft_putspace();
		}
	}
	ft_putchar('\n');
	return (0);
}


