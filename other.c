/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:21:29 by vomelchu          #+#    #+#             */
/*   Updated: 2018/06/13 16:15:46 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	ft_error(int i)
{
	if (i == 1)
		ft_putstr("BAD MALLOC\n");
	else if (i == 2)
		ft_putstr("BAD MAP\n");
	else if (i == 3)
		ft_putstr("MORE THEN 2 ARGV (OR BAD NAME)\n");
	else if (i == 4)
		ft_putstr("IT IS FOLDER\n");
	else
		write(1, "error\n", 6);
	exit(0);
}

int		len(char **str)
{
	int q;

	q = 0;
	while (str[q])
		q++;
	return (q);
}

int		len_int(char **str)
{
	int q;
	int count;

	q = 0;
	count = 0;
	while (str[0][q])
	{
		if (str[0][q] <= '9' && str[0][q] >= '0')
		{
			while (str[0][q] <= '9' && str[0][q] >= '0')
				q++;
			count++;
		}
		if (str[0][q] != '\0')
			q++;
	}
	return (count);
}

int		made_atoi_base(t_data *data, char *str, int q, int j)
{
	int count;

	count = 0;
	if (str[count] == ',')
	{
		count = count + 3;
		data->array_of_color[q][j] = ft_atoi_base(&str[count], 16);
	}
	else
		data->array_of_color[q][j] = 0x0033CC;
	while (str[count] != ' ' && str[count] != '\0')
		count++;
	return (count);
}
