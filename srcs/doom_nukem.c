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
                             +----------------------+
                             |                      |
+--------------+       +-----v-------+       +------+-------+
|  init_game   |------>|  load_home  |------>| load_gameplay|
+--------------+       +------|------+       +------|-------+
                           +--v---+              +--v---+
                           |eloop |              |eloop |
                           +------+              +------+
*/

void  load_gameplay(t_scene *scene)
{
  scene_parser(&scene);
  gameplay_event_loop(scene);
}

/*
** loading home functionality should be independant because it will be a handler for ESC button
** when a level is picked the correspondant map fd should be assigned to scene->config.world_fd
** should call load_gameplay()
*/

void    load_home(t_scene *scene)
{
  home_event_loop(scene);
  load_gameplay(scene);
}

/*
** init_game() is where scene gets initialized and load_home() should be called afterwards
*/

void    init_game(t_scene *scene)
{
  scene->config.mlx_ptr = mlx_init();
  scene->config.win_ptr = mlx_new_window(scene->config.mlx_ptr, HEIGHT, WIDTH, EXEC_NAME);
  load_home(scene);
}

int     main(int argc, char **argv)
{
  t_scene scene;

  init_game(&scene);
  return (0);
}