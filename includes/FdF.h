/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:37:29 by vomelchu          #+#    #+#             */
/*   Updated: 2018/05/29 14:37:31 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "../includes/get_next_line.h"
# include "../libft/includes/libft.h"

# define BUFF_SIZE 	200
# define HEIGHT 	1000
# define WIDTH 		1500

typedef	struct	s_data
{
	char		*name;
	void		*mlx;
	void		*win;
	int			**array;
	int			**array_of_color;
	int			array_height;
	int			array_width;
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			deltax;
	int			deltay;
	int			x_step;
	int			y_step;
	int			color;
	int			step_for_x;
	int			step_for_y;
	int			start_x;
	int			start_y;
	int			height_for_y;
	int			width_for_x;
	int			ar_col;
	int			forangle;
}				t_data;

void			tips(t_data *data);
int				exit_x(void);
void			ft_error(int i);
int				len(char **str);
int				len_int(char **str);
int				made_atoi_base(t_data *data, char *str, int q, int j);
int				made_memmory(char **str, t_data *data);
int				put_int(char **str, t_data *data, int q);
int				made_int_array(char **str, t_data *data);
char			**readlines(t_data *data);
void			bresenham_line(t_data *data);
char			*ft_joinfree(char *s1, char *s2, int j);
int				get_next_line(int const fd, char **line);
void			changestep(t_data *data);
void			transform(t_data *data, int x, int y);
void			draw_all(t_data *data);
int				ft_atoi_base(char *nb, int base);
int				hook_keydown(int key, t_data *data);

#endif
