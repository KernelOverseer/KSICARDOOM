#include "doom_nukem.h"

int	ft_server_sync_scene_client(t_doom_env *env,
	t_multiplayer_remote_client *client)
{
	t_sector	*sector;
	t_sprite	*sprite;

	env->main_scene.sectors.iterator = env->main_scene.sectors.first;
	write(client->socket_fd, &env->main_scene.sectors.size,
		sizeof(env->main_scene.sectors.size));
	while ((sector = ttslist_iter_content(&env->main_scene.sectors)))
	{
		sector->sprites.iterator = sector->sprites.first;
		write(client->socket_fd, &sector->id, sizeof(sector->id));
		write(client->socket_fd, &sector->sprites.size, sizeof(sector->sprites.size));
		while ((sprite = ttslist_iter_content(&sector->sprites)))
			ft_serialize_sprite(client->socket_fd, sprite);
	}
	return (1);
}

static void ft_destroy_sprite(void *sprite)
{
	free(sprite);
}

static int ft_clear_sector_sprites(t_sector *sector)
{
	ttslist_purge(&sector->sprites, ft_destroy_sprite);
	return (1);
}

int	ft_client_sync_scene_server(t_doom_env *env,
	t_multiplayer_client *client)
{
	size_t		sector_count;
	size_t		sprite_count;
	int			sector_id;
	t_sector	*sector;
	t_sprite	*sprite;

	read(client->socket_fd, &sector_count, sizeof(sector_count));
	while (sector_count--)
	{
		read(client->socket_fd, &sector_id, sizeof(sector_id));
		read(client->socket_fd, &sprite_count, sizeof(sprite_count));
		sector = ttslist_get_id_content(&env->main_scene.sectors, sector_id);
		if (sector)
			ft_clear_sector_sprites(sector);
		while (sprite_count--)
		{
			sprite = ft_memalloc(sizeof(t_sprite));
			ft_deserialize_sprite(client->socket_fd, sprite);
			if (sector)
				sector->sprites.push(&sector->sprites, sprite);
		}
	}
	return (1);
}