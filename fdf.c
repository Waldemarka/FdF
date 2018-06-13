/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:36:56 by vomelchu          #+#    #+#             */
/*   Updated: 2018/06/13 16:14:58 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		made_memmory(char **str, t_data *data)
{
	int q;
	int i;
	int j;

	q = 0;
	j = len(str);
	if (!(data->array = (int**)malloc(sizeof(int*) * j))
		|| !(data->array_of_color = (int**)malloc(sizeof(int*) * j)))
		return (0);
	i = len_int(str);
	while (q != j)
	{
		if (!(data->array[q] = (int*)malloc(sizeof(int) * i))
			|| !(data->array_of_color[q] = (int*)malloc(sizeof(int) * i)))
			return (0);
		q++;
	}
	data->array_height = j;
	data->array_width = i;
	return (0);
}

int		put_int(char **str, t_data *data, int q)
{
	int i;
	int j;

	while (++q != data->array_height)
	{
		i = 0;
		j = 0;
		while (str[q][i])
		{
			if ((str[q][i] <= '9' && str[q][i] >= '0') || str[q][i] == '-')
			{
				data->array[q][j] = ft_atoi(&str[q][i]);
				while ((str[q][i] <= '9' && str[q][i] >= '0')
					|| str[q][i] == '-')
					i++;
				i = i + made_atoi_base(data, &str[q][i], q, j);
				j++;
			}
			if (str[q][i] != '\0')
				i++;
		}
		if (j != data->array_width || j < 1)
			ft_error(2);
	}
	return (0);
}

int		made_int_array(char **str, t_data *data)
{
	int q;
	int i;

	q = -1;
	i = 0;
	made_memmory(str, data);
	put_int(str, data, q);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

char	**readlines(t_data *data)
{
	int		fd;
	char	*line;
	char	*str;
	char	**ret;

	str = NULL;
	line = NULL;
	if ((fd = open(data->name, O_RDONLY)) == -1)
		ft_error(3);
	get_next_line(fd, &line);
	if (!line || ft_strlen(line) < 1)
		ft_error(2);
	str = ft_strdup(line);
	while (line != NULL)
	{
		free(line);
		str = ft_joinfree(str, "\n", 3);
		get_next_line(fd, &line);
		if (line != NULL)
			str = ft_joinfree(str, line, 3);
	}
	close(fd);
	ret = ft_strsplit(str, '\n');
	free(str);
	return (ret);
}

int		main(int argc, char *argv[])
{
	t_data	*data;
	char	**str;
	int		fd;

	if (argc != 2)
		ft_error(3);
	if (!(data = (t_data *)malloc(sizeof(t_data))))
		ft_error(1);
	data->name = argv[1];
	fd = open(data->name, O_DIRECTORY);
	if (fd >= 0)
		ft_error(4);
	str = readlines(data);
	if (str == NULL)
		ft_error(0);
	made_int_array(str, data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->name);
	data->ar_col = 0;
	draw_all(data);
	mlx_key_hook(data->win, hook_keydown, data);
	mlx_hook(data->win, 17, 1L << 17, exit_x, NULL);
	mlx_loop(data->mlx);
	return (0);
}
