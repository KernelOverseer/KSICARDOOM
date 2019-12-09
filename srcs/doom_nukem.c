/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 20:39:07 by merras            #+#    #+#             */
/*   Updated: 2019/10/28 12:59:46 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int     main(int argc, char **argv)
{
    t_scene scene;
    int     fd;

    if (argc != 2)
		return (ft_perror(EXEC_NAME, NULL, N_SCENE));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return(ft_perror(EXEC_NAME, argv[1], F_OPEN));
    scene_parser(fd, &scene);
    player_event_loop(scene);
}