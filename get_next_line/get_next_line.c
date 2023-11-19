/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:36:03 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/11/19 14:19:22 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE
#endif

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int str_len(char *str)
{
	int i;
	
	i = 0;
	if (str)
	{
		while(str[i])
			i++;
	}
	return (i);
}
int where_is_n(char *str)
{
	int i;

	i = 0;
	if (str_len(str) > 0)
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			return (i);
		else 
			return (-1);
	}
	return (0);
}
char *str_join(char *str1, char *str2, int len)
{
	int size;
	char *rtn;
	int i;
	int j;
	
	if (len < 0)
		size = str_len(str1) + str_len(str2);
	else if (len == 0)
		return (str1);
	else 
		size = str_len(str1) + len;
	rtn = malloc(sizeof(char) * (size + 1));
	if (rtn == NULL)
		return (rtn);
	i = -1;
	while (str1[++i])
		rtn[i] = str1[i];
	j = -1;
	while(str2[++j])
		rtn[i++] = str2[j];
	rtn[i] = '\0';
	return (rtn);
}


int manage_storage(char **str, char *rtn)
{
	if (where_is_n(*str) > 0)
		return(0);
	return(0);
}	

char	*get_next_line(int fd)
{
	static char *storage;
	
	return(NULL);
	
}

int main(int argc, char **argv)
{
	char *str;
	if  (argc == 3)
	{
		printf("str 1 = %s\n", argv[1]);
		printf("str 2 = %s\n", argv[2]);
		str = str_join(argv[1], argv[2], -1);
		printf("str_join = %s\n", str);
		free (str);
	}
	if  (argc == 4)
	{
		printf("str 1 = %s\n", argv[1]);
		printf("str 2 = %s\n", argv[2]);
		printf("%d\n", atoi(argv[3]));
		str = str_join(argv[1], argv[2], atoi(argv[3]));
		printf("str_join = %s\n", str);
		free (str);
	}

}


