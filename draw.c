/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:37:54 by vomelchu          #+#    #+#             */
/*   Updated: 2018/06/04 17:37:56 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	changestep(t_data *data)
{
	if (data->array_width < 30)
	{
		data->step_for_x = 20;
		data->step_for_y = 20;
		data->width_for_x = 8;
	}
	else if (data->array_width < 100 && data->array_width >= 30)
	{
		data->step_for_x = 10;
		data->step_for_y = 10;
		data->width_for_x = 4;
	}
	else if (data->array_width >= 100 && data->array_width <= 200)
	{
		data->step_for_x = 5;
		data->step_for_y = 4;
		data->width_for_x = 2;
	}
	else if (data->array_width > 200)
	{
		data->step_for_x = 3;
		data->step_for_y = 3;
		data->width_for_x = 1;
	}
}

void	transform(t_data *data, int x, int y)
{
	data->x0 = data->start_x + (x * data->step_for_x) - (y * data->width_for_x);
	data->y0 = data->start_y + (y * data->step_for_y) -
	(data->array[y][x] * data->height_for_y);
	if (x != data->array_width - 1)
	{
		data->x1 = data->start_x + ((x + 1) * data->step_for_x) -
		(y * data->width_for_x);
		data->y1 = data->start_y + (y * data->step_for_y) -
		(data->array[y][x + 1] * data->height_for_y);
		bresenham_line(data);
	}
	if (y != data->array_height - 1)
	{
		data->x1 = data->start_x + (x * data->step_for_x) -
		((y + 1) * data->width_for_x);
		data->y1 = data->start_y + ((y + 1) * data->step_for_y) -
		(data->array[y + 1][x] * data->height_for_y);
		bresenham_line(data);
	}
}

void	angle(t_data *data)
{
	if (data->forangle == 1)
	{
		data->width_for_x = 0 - data->width_for_x;
		data->start_x = data->start_x - 100;
	}
}

void	draw_all(t_data *data)
{
	int x;
	int y;

	y = -1;
	tips(data);
	changestep(data);
	angle(data);
	data->start_x = (WIDTH / 2) - ((data->step_for_x * data->array_width)
		/ 2) + 100;
	data->start_y = (HEIGHT / 2) - ((data->step_for_y * data->array_height)
		/ 2);
	data->height_for_y = 2;
	while (++y != data->array_height)
	{
		x = 0;
		while (x != data->array_width)
		{
			if (data->ar_col == 0)
				data->color = data->array_of_color[y][x];
			else
				data->color = data->ar_col;
			transform(data, x, y);
			x++;
		}
	}
}
