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


/*
** init_game() is where scene gets initialized and the home view is rendered with level picker.
** when the level is chosen the fd of the level's map should be assigned to scene->config.world_fd.
*/

void    init_game(t_scene *scene)
{
  scene->config.win_ptr = mlx_new_window((scene->config.mlx_ptr = mlx_init()),
                          HEIGHT, WIDTH, EXEC_NAME);

}

int     main(int argc, char **argv)
{
  t_scene scene;

  init_game(&scene);
  scene_parser(&scene);
  player_event_loop(scene);
}