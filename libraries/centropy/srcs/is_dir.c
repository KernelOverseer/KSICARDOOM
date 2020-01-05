/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 17:48:09 by merras            #+#    #+#             */
/*   Updated: 2019/08/02 17:53:32 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

int	is_directory(char *filename)
{
	struct stat sbuff;

	stat(filename, &sbuff);
	return (S_ISDIR(sbuff.st_mode));
}
