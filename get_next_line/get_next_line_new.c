/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:15:03 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/01/09 16:57:02 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int ft_strlen(char *str)
{
	int	i;

	if (str)
	{
		i = 0;
		while (str[i])
			i++;
		return (i);
	}
	return (0);
}

int where_is_n(char *str)
{
	int i;

	i = 0;

	if (str)
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			return(i);
	}
	return (-1);
}

void	my_free(char **str1, char **str2)
{
	if (str1 && *str1)
	{
		free(*str1);
		*str1 = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
}

int ft_strlcat(
int	check_storage(char **storage, char **rtn)
{
	if (!*storage)
		return(0);

	if (where_is_n(*storage) == -1)


}
char *get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*rtn;
	char		*line;



	if (fd < 0)
		return (NULL);
	if (
	
}
