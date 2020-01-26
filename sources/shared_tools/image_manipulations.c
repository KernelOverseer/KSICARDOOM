/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   image_manipulations.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: abiri <abiri@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/01/04 12:56:19 by abiri			 #+#	#+#			 */
/*   Updated: 2020/01/19 21:21:10 by abiri			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "doom_nukem.h"

void	ft_blit_image(t_rect rect, t_sdl_image *texture,
		t_sdl_image *main_image)
{
	double x_inc;
	double y_inc;
	double x;
	double y;
	int	 rect_x;


	if (!texture || !main_image)
		return ;
	x_inc = (double)texture->width / (double)rect.w;
	y_inc = (double)texture->height / (double)rect.h;
	y = 0;
	rect_x = rect.x;
	int xmax = rect.x + rect.w;
	int ymax = rect.y + rect.h;
	int color;
	while (rect.y < ymax && y < texture->height)
	{
		x = 0;
		rect.x = rect_x;
		while (rect.x < xmax && x < texture->width)
		{
			color = texture->pixels[(int)y * texture->width + (int)x];
			if (!RGB_A(color))
				ft_sdl_set_image_pixel(main_image, rect.x, rect.y, color);
			x += x_inc;
			rect.x++;
		}
		rect.y++;
		y += y_inc;
	}
}
