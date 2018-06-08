/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:36:56 by vomelchu          #+#    #+#             */
/*   Updated: 2018/05/29 14:36:58 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/FdF.h"

int 	**made_memmory(char **str, int **array, t_data *data)
{
	int q;
	int i;
	int j;

	q = 0;
	j = len(str);
	if (!(array = (int**)malloc(sizeof(int*) * j + 1))
		|| !(data->array_of_color= (int**)malloc(sizeof(int*) * j + 1)))
		return(0);
	i = len_int(str);
	while (q != j)
	{
		if (!(array[q] = (int*)malloc(sizeof(int) * i + 1))
			|| !(data->array_of_color[q] = (int*)malloc(sizeof(int) * i + 1)))
			return(0);
		q++;
	}
	data->array_height = j;
	data->array_width = i;
	return(array);
}

int 	**put_int(char **str, int **array, t_data *data)
{
	int q;
	int i;
	int j;

	q = 0;
	while (q != data->array_height)
	{
		i = 0;
		j = 0;
		while (str[q][i])
		{
			if ((str[q][i] <= '9' && str[q][i] >= '0') || str[q][i] == '-')
			{
				array[q][j] = ft_atoi(&str[q][i]);
				while((str[q][i] <= '9' && str[q][i] >= '0') || str[q][i] == '-')
					i++;
				i = i + made_atoi_base(data, &str[q][i], q, j);
				j++;
			}
			if (str[q][i] != '\0') 
				i++;
		}
		if (j != data->array_width)
		{
			printf(" %d and q %d\n", j, q);
			ft_error(2);
		}
		q++;
	}
	return (array);
}

int 	**made_int_array(char **str, t_data *data)
{
	int **array;
	int q;

	q = 0;
	array = NULL;
	array =	 made_memmory(str, array, data);
	array =  put_int(str, array, data);
	return (array);
}
 
char	*readlines(t_data *data)
{
	int fd;
	char *line;
	char *str;

	str = NULL;
	if ((fd = open(data->name, O_RDONLY)) == -1)
		ft_error(3);
	get_next_line(fd, &line);
	str = ft_strdup(line);
	while (line != NULL)
	{
		str = ft_joinfree(str, "\n", 3);	
		get_next_line(fd, &line);
		if (line != NULL)		
			str = ft_joinfree(str, line, 3);
	}
	str[ft_strlen(str)] = '\0';
	close (fd);
	return(str);
}

int		main(int argc, char *argv[])
{
	t_data *data;
	int q;
	char **str;

	if (argc != 2)
		ft_error(3);
	if (!(data = (t_data *)malloc(sizeof(t_data))))
		ft_error(1);
	data->name = argv[1];
	str = ft_strsplit(readlines(data), '\n');
	q = 0;
	data->array = made_int_array(str, data);
	q = 0;
	draw_all(data);
	mlx_loop(data->mlx);
	return (0);
}
