/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:21:50 by fgiampa           #+#    #+#             */
/*   Updated: 2024/10/15 20:17:28 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void createRectangle(t_data *data, int startingX, int startingY, int width, int height, int color)
{
	int i;
	int j;

	j = startingY;
	while (j < height + startingY)
	{
		i = startingX;
		while (i < width + startingX)
		{
			my_mlx_pixel_put(data, i, j, color);
			i++;
		}
		j++;
	}
}

void createTriangle(t_data *data, int startingX, int startingY, int width, int height, int color)
{
	int i;
	int j;
	int correction;

	j = 0;
	correction = 0;
	while (j < height)
	{
		correction = (j * width) / (2 * height);
		i = 0;
		while (i < width)
		{
			if((i >= width / 2 - correction) && (i <= width / 2 + correction))
				my_mlx_pixel_put(data, i + startingX, j + startingY, color);
			i++;
		}
		j++;
	}
}

void createCircle(t_data *data, int centreX, int centreY, int r, int color)
{
	int x;
	int y;

	y = centreY - r;
	while (y <= centreY + r)
	{
		x = centreX - r;
		while (x <= centreX + r)
		{
			if ((x - centreX) * (x - centreX) + (y - centreY) * (y - centreY) <= r * r)
				my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}

void createHexagon(t_data *data, int startingX, int startingY, int r, int color)
{
	int i;
	int j;
	int correction;
	int d;
	int centerX;

	d = r * 2;
	centerX = startingX + r;
	j = 0;
	correction = 0;
	while (j < d)
	{
		if (j < r)
			correction = (j * r) / d + r / 2;
		else
			correction = ((d - j) * r) / d + r / 2;

		i = 0;
		while (i < d)
		{
			if((i >= centerX - correction) && (i <= centerX + correction))
				my_mlx_pixel_put(data, i + startingX, j + startingY, color);
			i++;
		}
		j++;
	}
}

void createGradientRectangle(t_data *data, int startingX, int startingY, int width, int height, unsigned int color)
{
	int i;
	int j;
	unsigned int increment;
	unsigned int initialColor;

	increment = 0x01;
	initialColor = color;
	j = startingY;
	while (j < height + startingY)
	{
		i = startingX;
		while (i < width + startingX)
		{
			my_mlx_pixel_put(data, i, j, color);
			i++;
		}
		if ((color + increment) <= (initialColor + 0xFF))
			color = color + increment;
		j++;
	}
}

void createLGBTRectangle(t_data *data, int startingX, int startingY, int width, int height)
{
	int i;
	int j;
	unsigned int color;
	int rowHeight;

	rowHeight = height / 7;
	j = startingY;
	while (j < height + startingY)
	{
		if (j - startingY <= rowHeight)
			color = 0x00FF0000;
		else if (j - startingY <= rowHeight * 2)
			color = 0x00FF7F00;
		else if (j - startingY <= rowHeight * 3)
			color = 0x00FFFF00;
		else if (j - startingY <= rowHeight * 4)
			color = 0x0000FF00;
		else if (j - startingY <= rowHeight * 5)
			color = 0x000000FF;
		else if (j - startingY <= rowHeight * 6)
			color = 0x002E2B5F;
		else if (j - startingY <= rowHeight * 7)
			color = 0x008B00FF;

		i = startingX;
		while (i < width + startingX)
		{
			my_mlx_pixel_put(data, i, j, color);
			i++;
		}
		j++;
	}
}

void createChessTexture(t_data *data, int startingX, int startingY, int width, int height, int multiplier, unsigned int color)
{
	int i;
	int j;
	int smSquareWidth;
	int reminder;

	smSquareWidth = width / multiplier;
	j = startingY;
	while (j < height + startingY)
	{
		if ((j - startingY) / smSquareWidth % 2 == 1)
			reminder = 1;
		else
			reminder = 0;

		i = startingX;
		while (i < width + startingX)
		{
			if((i - startingX) / smSquareWidth % 2 == reminder)
				my_mlx_pixel_put(data, i, j, color);
			i++;
		}
		j++;
	}
}

void createDiagonalTexture(t_data *data, int startingX, int startingY, int width, int height, int multiplier, unsigned int color)
{
	int i;
	int j;
	int lineWidth;
	int shift;

	shift = 0;
	lineWidth = width / multiplier;
	j = startingY;
	while (j < height + startingY)
	{
		i = startingX;
		while (i < width + startingX)
		{
			if((i - startingX + shift) / lineWidth % 2 == 1)
				my_mlx_pixel_put(data, i, j, color);
			i++;
		}
		shift++;
		j++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 800, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	createDiagonalTexture(&img, 200, 200, 600, 400, 10, 0x00FF4200);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
