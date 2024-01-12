/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:15:03 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/01/12 13:26:29 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

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
			return(i+1);
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
	return (rtn);
}
int manage_storage(char **storage, int n)
{
	char *tmp;
	
	tmp = NULL;
	if ( n > 0)
	{
		tmp = ft_strljoin(NULL, &(*storage[n]), -1);
		if (!tmp)
		return (-1);
	}
		my_free(storage, NULL, NULL);
		*storage = tmp;
	if (n < 0)
		return (0);
	return(1);
}
int	check_storage(char **storage, char **rtn)
{
	int	n;
	
	if (!*storage)
		return(0);
	n = where_is_n(*storage);
	// if (n == -1)
	// {
	// 	printf("\n en check storage\n rtn = %s\n storage=%s\n", *rtn, *storage);
	// 	*rtn = *storage;
	// 	*storage = NULL;
	// 	printf("\n en check storage\n rtn = %s\n storage=%s\n", *rtn, *storage);
	// 	return (0);
	// } 
	*rtn = ft_strljoin(NULL, *storage, n);
	return (manage_storage(storage, n));
}

char *add_buffer_to_line(char **line, char *buffer)
{
	char *tmp;
	
	tmp = ft_strljoin(*line, buffer, -1);
	my_free(line, NULL, NULL);
	return (tmp);
}

int read_line(char **line, int fd)
{
	char	*buffer;
	int		nb;
	int		n;
	
	buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (-1);
	nb = read(fd, buffer, BUFFER_SIZE);	
	buffer[nb] = '\0';
	n = where_is_n(buffer);
	*line = add_buffer_to_line(line, buffer);
	if (!*line)
	{	my_free(&buffer,  NULL, NULL);
		return (-1);
	}
	while (nb == BUFFER_SIZE && n == -1)
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		buffer[nb] = '\0';
		n = where_is_n(buffer);
		*line = add_buffer_to_line(line, buffer);
		if (!*line)
		{	
			my_free(&buffer,  NULL, NULL);
			return (-1);
		}
	}
	my_free(&buffer, NULL, NULL);
	return(0);
}

int manage_end(char **rtn, char **line, char **storage)
{
	int	n;
	char *tmp;
	char *tmp2;
	char *l;

	n = where_is_n(*line);
	tmp = ft_strljoin(*rtn, *line, n);
	tmp2 = NULL;
	if (!tmp)
		return(-1);
	my_free(rtn, NULL, NULL);
	*rtn = tmp;
	if (n > 0)
	{
		if (n < ft_strlen(*line))
		{
			l = *line;
			tmp2 = ft_strljoin(*storage, &l[n], -1);
		}
		my_free(storage, NULL, NULL);
		*storage = tmp2;
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
	if (fd < 0)
		return (NULL);
	if (storage)
		r_code = check_storage(&storage, &rtn);
	if (r_code == 1)
		return (rtn);
	else if (r_code == 0)
	{
		r_code = read_line(&line, fd);
		if (r_code != -1)
			r_code = manage_end(&rtn, &line, &storage);
		if (r_code != -1)
			return (rtn);
	}
	else
	{
		my_free(&rtn, &storage, &line);
		return (NULL);
	}
	return (NULL);
}


int main (int argc, char *argv[])
{
	int fd;
	char *str;
	int i = 5;
	
	printf("entro al prorama con %d y el primer argumento %s\n", argc, argv[1]);
	if (argc > 1)
	{
		printf("entro al if\n");
		fd = open(argv[1], O_RDONLY);
		str = NULL;
		str = get_next_line(fd);
		while (i--)
		{
			printf(">%s",str);
			free(str);
			str = get_next_line(fd);
		}
		
		close(fd); 
	} 
	return(0);
}	
		
