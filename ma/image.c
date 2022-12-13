/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:57:17 by matef             #+#    #+#             */
/*   Updated: 2022/12/13 13:12:58 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

	if (0 <= x && x < WINDOW_WIDTH && 0 <= y && y < WINDOW_HEIGHT)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *)pixel = color;
	}
}

void create_image(t_data *data)
{
    data->img.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);
    render(data);
}


int render_rect(t_img *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
		{
			img_pix_put(img, j, i, rect.color);
			j++;
		}
		++i;
	}
	return (0);
}

void	render_background(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			if (i < WINDOW_HEIGHT / 2)
				img_pix_put(img, j, i, 0xAAC4FF);
			else
				img_pix_put(img, j, i, 0x5F7161);
			j++;
		}
		i++;
	}
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);

	// render_rect(&data->img, (t_rect){data->p1.x / 10, data->p1.y / 10, 5, 5, YELLOW});
	// DDA(data, data->p1, data->p2);
	render_background(&data->img);
	ft_cast_rays(data);
	// draw_map(data);
	ft_mini_map(data);
	// ft_texture(data);

	

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}
