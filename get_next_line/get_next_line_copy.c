/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:23:33 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/01/17 21:24:35 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

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
			return(i + 1);
	}
	return (-1);
}
void	my_free(char **str1, char **str2, char **str3)
{
	if (str1 !=NULL && *str1 != NULL)
	{
		free(*str1);
		*str1 = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
	if (str3 && *str3)
	{
		free(*str3);
		*str3 = NULL;
	}
}

char	*ft_strljoin(char *str1, char *str2, int len)
{
	int i;
	int j;
	char *rtn;
	int	size;
	
	if (len < 0)
		size = ft_strlen(str1) + ft_strlen(str2);
	else 
		size = ft_strlen(str1) + len;
	rtn = malloc(sizeof(char) * (size + 1));
	if (!rtn)
		return (NULL);
	i = 0;
	while (str1 && str1[i])
	{
		rtn[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2 && str2[j] && i < size)
		rtn[i++] = str2[j++];
	rtn[i] ='\0'; 
	my_free(&str1, NULL, NULL);
	return (rtn);
}

int	check_storage(char **storage, char **rtn)
{
	int		n;
	char	*s;

	n = where_is_n(*storage);
	if (n == -1)
	{
		*rtn = *storage;
		*storage = NULL;
		return (0);
	}
	else if (n == ft_strlen(*storage))
	{
		*rtn = *storage;
		*storage = NULL;
		return (1);
	}
	else
	{
		*rtn = ft_strljoin(NULL, *storage, n);
		if (!*rtn)
			return(-1);
		s = *storage;
		if (n < ft_strlen(s))
		{
			*storage = ft_strljoin(NULL, &s[n], -1);
			if (!*storage)
				return (-1);
		}
		my_free(&s, NULL, NULL);
			
		return(1);
	}
	
}

int read_line(char **line, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		nb;
	int		n;

	nb = read(fd, buffer, BUFFER_SIZE);
	if (nb < 0)
		return (-2);
	if (nb == 0)
			return (1);
	buffer[nb] = '\0';
	n = where_is_n(buffer);
	*line = ft_strljoin(*line, buffer, -1);
	if (!*line)
		return (-1);
	while (nb == BUFFER_SIZE && n == -1)
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		if (nb < 0)
			return (-2);
		buffer[nb] = '\0';
		n = where_is_n(buffer);
		*line = ft_strljoin(*line, buffer, -1);
		if (!*line)
			return (-1);
	}
	return (0);
}

int manage_exit(char **rtn, char **line, char **storage)
{
	int	n;
	char *l;

	n = where_is_n(*line);
	
	*rtn = ft_strljoin(*rtn, *line, n);
	if (!*rtn)
	{
		my_free(line, NULL, NULL);
		return(-1);
	}
	if (n > 0 && n  < ft_strlen(*line))
	{
		l = *line;	
		*storage = ft_strljoin(NULL, &l[n], -1);
	}
	my_free(line, NULL, NULL);
	return (0);
}

char *get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*rtn;
	char		*line;
	int 		r_code;		

	rtn = NULL;
	line = NULL;
	r_code = 0;
	if (fd < 0 || BUFFER_SIZE  <= 0 || read(fd, NULL, 0) < 0 )
	{
		my_free(&storage, NULL, NULL);
		return (NULL);
	}
	if (storage)
		r_code = check_storage(&storage, &rtn);
	if (r_code == -1)
	{	
		my_free(&storage, &rtn, NULL);
		return (NULL);
	}
	else if (r_code == 1)
		return(rtn);
	else if (r_code == 0)
	{
		r_code = read_line(&line, fd);
		if (r_code == -2)
		{
			my_free(&storage, &rtn, &line);
			return (NULL);
		}
		else if (r_code == -1)
		{
			my_free(&storage, &rtn, &line);
			return (NULL);
		} 
		else if (r_code == 1)
			return (rtn);
		else if  (r_code == 0)
		{
			r_code = manage_exit(&rtn, &line, &storage);
			if (r_code == -1)
			{
				my_free(&storage, &rtn, &line);
				return (NULL);
			}
		}
	}
	return (rtn);
}

