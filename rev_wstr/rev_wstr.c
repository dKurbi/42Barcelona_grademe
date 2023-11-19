/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:26:10 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/09/25 14:43:24 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
	}
}
void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int print_word(int start, int end, char *str)
{
	int 	i;
	char	*word;
	int		len_w;
	i = 0;

	len_w =  end - start ;
	word = malloc(len_w + 1 * sizeof(char));
	if (word == NULL)
		return (1);
	word[len_w] = '\0';
	start++;
	while (len_w > 0)
	{
		word[i] = str[start];
		i++;
		start++;
		len_w--;
	}
	ft_putstr(word);
	free (word);
	word = NULL;
	return(0);
}

int main(int argc, char **argv)
{
	int		i;
	int		len_s;
	int 	end;
	char	*str;

	if (argc != 2)
	{
		ft_putchar('\n');
		return(0);
	}
	str = argv[1];
	len_s = ft_strlen(str) - 1;
	end = len_s;
	while (len_s >= 0)
	{	
		while (str[len_s] != ' ' && len_s > 0)
			len_s--;
		if (len_s > 0 )
		{
			if (print_word(len_s, end, str))
				return(1);			
			ft_putchar(' ');
		}
		else
			if (print_word(-1, end, str))
				return(1);
		len_s--;
		end = len_s;
	}
	ft_putchar('\n');
}

