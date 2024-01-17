/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:15:03 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/01/17 21:18:09 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main (int argc, char *argv[])
{
	int fd;
	char *str;

	
	printf("entro al prorama con %d y el primer argumento %s\n", argc, argv[1]);
	if (argc > 1)
	{
		printf("entro al if\n");
		fd = open(argv[1], O_RDONLY);
		str = NULL;
		str = get_next_line(fd);
		while (str)
		{
			printf(">%s",str);
			free(str);
			str = get_next_line(fd);
		}
		free(str);
		close(fd); 
		fd = open(argv[1], O_RDONLY);
		str = NULL;
		str = get_next_line(fd);
		while (str)
		{
			printf(">%s",str);
			free(str);
			str = get_next_line(fd);
		}
		free(str);
		close(fd); 
	} 
	return(0);
}	 