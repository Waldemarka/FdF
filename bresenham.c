/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:54:50 by vomelchu          #+#    #+#             */
/*   Updated: 2018/05/31 15:54:51 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	for_dx(t_data *data)
{
	int error;
	int q;
	int x;
	int y;

	error = (data->deltay << 1) - data->deltax;
	x = data->x0 + data->x_step;
	y = data->y0;
	q = 1;
	mlx_pixel_put(data->mlx, data->win, data->x0, data->y0, data->color);
	while (q <= data->deltax)
	{
		if (error > 0)
		{
			y += data->y_step;
			error += (data->deltay - data->deltax) << 1;
		}
		else
			error += data->deltay << 1;
		mlx_pixel_put(data->mlx, data->win, x, y, data->color);
		x += data->x_step;
		q++;
	}
}

void	for_dy(t_data *data)
{
	int error;
	int q;
	int x;
	int y;

	error = (data->deltax << 1) - data->deltay;
	y = data->y0 + data->y_step;
	x = data->x0;
	q = 1;
	mlx_pixel_put(data->mlx, data->win, data->x0, data->y0, data->color);
	while (q <= data->deltay)
	{
		if (error > 0)
		{
			error += (data->deltax - data->deltay) << 1;
			x += data->x_step;
		}
		else
			error += data->deltax << 1;
		mlx_pixel_put(data->mlx, data->win, x, y, data->color);
		y += data->y_step;
		q++;
	}
}

void	bresenham_line(t_data *data)
{
	data->deltax = abs(data->x1 - data->x0);
	data->deltay = abs(data->y1 - data->y0);
	data->x_step = data->x1 >= data->x0 ? 1 : -1;
	data->y_step = data->y1 >= data->y0 ? 1 : -1;
	if (data->deltax > data->deltay)
		for_dx(data);
	else
		for_dy(data);
}
