/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_players.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:58:37 by msidqi            #+#    #+#             */
/*   Updated: 2020/01/19 21:23:37 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	ft_bot_input(void *env, void *body) // pass env awsell
{
	unsigned char *input;
	t_body *b;
	t_doom_env *e;

	b = (t_body *)body;
	e = (t_doom_env *)env;
	input =	b->player->input;
	// control bot
}
