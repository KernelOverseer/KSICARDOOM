/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:23:47 by msidqi            #+#    #+#             */
/*   Updated: 2019/10/11 11:32:19 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgl.h"

static void		ft_ppm_format(t_data *data, int fd)
{
	ft_putstr_fd("P3\n", fd);
	ft_putnbr_fd(data->winwidth, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(data->winheight, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(255, fd);
	ft_putchar_fd('\n', fd);
}

static void		ft_save_screenshot(t_data *data, int *var)
{
	unsigned char	*buff;
	unsigned char	ppm;

	var[1] = -1;
	while (++var[1] < data->winheight)
	{
		var[2] = -1;
		while (++var[2] < data->winwidth)
		{
			var[3] = 3;
			buff = (unsigned char *)&data->image[var[2] +
				var[1] * data->winwidth];
			while (--var[3] >= 0)
			{
				ppm = buff[var[3]];
				ft_putnbr_fd(ppm, var[0]);
				ft_putchar_fd(' ', var[0]);
			}
		}
		ft_putchar_fd('\n', var[0]);
	}
	ft_putchar_fd('\n', var[0]);
}

void			*ft_screenshot(void *param)
{
	int				var[4];
	t_data			*data;
	static int		i = 0;

	data = (void *)param;
	if (!(var[0] = open("image.ppm", O_RDWR | O_CREAT, 0777)))
		pthread_exit(NULL);
	ft_ppm_format(data, var[0]);
	ft_save_screenshot(data, var);
	close(var[0]);
	i++;
	pthread_exit(NULL);
}
