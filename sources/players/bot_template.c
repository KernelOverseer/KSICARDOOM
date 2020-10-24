/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot_template.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 20:12:33 by abiri             #+#    #+#             */
/*   Updated: 2020/10/24 12:49:10 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

/*
**	In here you should create a new bot,
**	which is just a body you give various properties to
*/

t_body	*ft_default_bot_setup(t_doom_env *env, t_sector *sector, t_vec3 pos)
{
	t_body	*body;

	if (!(body = ft_memalloc(sizeof(t_body))))
		return (NULL);
	*body = ft_default_body(pos);
	body->player = ft_player_construct(0);
	body->player->sector = sector;
	ft_create_player_sprite(body->player);
	ft_fill_player_sprite_textures(&env->main_scene, body->player, 0, 8);
	return body;
}

/*
**	In here you should write the code that gets executed everytime, every frame
**	To make the bot dynamic and do various things
*/

int		ft_default_bot_iter(void *e, void *b)
{
	t_doom_env	*env;
	t_body		*body;

	env = e;
	body = b;
	return (1);
}