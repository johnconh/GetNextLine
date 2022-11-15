/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:58:06 by daampuru          #+#    #+#             */
/*   Updated: 2022/09/30 18:44:50 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		id;
	int		i;

	id = open("testFiles/fichero", O_RDONLY);
	line = "";
	i = 0;
	while (line != NULL && i <= 8)
	{
		line = get_next_line(id);
		printf("Text: (%s)\n", line);
		i++;
		free(line);
	}
	close(id);
	return (0);
}
