/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forkey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 17:10:08 by vomelchu          #+#    #+#             */
/*   Updated: 2018/06/12 17:10:09 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		exit_x(void)
{
	exit(1);
	return (0);
}

void	change_color(int key, t_data *data)
{
	if (key == 18)
		data->ar_col = 0xE32636;
	if (key == 19)
		data->ar_col = 0xF2F3F4;
	if (key == 20)
		data->ar_col = 0x00FFFF;
	if (key == 49)
		data->ar_col = 0;
	if (key == 124)
		data->forangle = 1;
	if (key == 123)
		data->forangle = 0;
	mlx_clear_window(data->mlx, data->win);
	draw_all(data);
	mlx_key_hook(data->win, hook_keydown, data);
	mlx_hook(data->win, 17, 1L << 17, exit_x, NULL);
}

int		hook_keydown(int key, t_data *data)
{
	if (key == 53)
		exit(1);
	if (key == 18 || key == 19 || key == 20 || key == 49
		|| key == 124 || key == 123)
		change_color(key, data);
	return (0);
}

void	tips(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 20, 10, 0xE5AA70,
		"COLOUR: 1 || 2 || 3");
	mlx_string_put(data->mlx, data->win, 20, 30, 0xE5AA70,
		"VIEWING ANGLE: left || right");
	mlx_string_put(data->mlx, data->win, 20, 50, 0xE5AA70,
		"RESET_ALL: space");
}
