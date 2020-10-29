#include "doom_nukem.h"
#include <errno.h>

int	ft_client_sync_body_input_server(t_body *body,
	t_multiplayer_client *client)
{
	int i;

	i = 0;
	i = write(client->socket_fd, &body->player->input,
		sizeof(body->player->input));
	if (i < 0)
		return (-1);
	i = write(client->socket_fd, &body->player->mouse_buttons,
		sizeof(body->player->mouse_buttons));
	if (i < 0)
		return (-1);
	i = write(client->socket_fd, &body->player->mouse_rel,
		sizeof(body->player->mouse_rel));
	if (i < 0)
		return (-1);
	return (i);
}

int	ft_server_sync_body_input_client(t_body *body,
	t_multiplayer_remote_client *client)
{
	int i = 0;

	i += read(client->socket_fd, body->player->input,
		sizeof(body->player->input));
	i += read(client->socket_fd, body->player->mouse_buttons,
		sizeof(body->player->mouse_buttons));
	i += read(client->socket_fd, &body->player->mouse_rel,
		sizeof(body->player->mouse_rel));
	return (i);
}

int	ft_server_sync_body_client(t_body *body,
	t_multiplayer_remote_client *client)
{
	write(client->socket_fd, &body->pos, sizeof(body->pos));
	write(client->socket_fd, &body->forw, sizeof(body->forw));
	write(client->socket_fd, &body->right, sizeof(body->right));
	write(client->socket_fd, &body->up, sizeof(body->up));
	write(client->socket_fd, &body->player->height,
		sizeof(body->player->height));	
	write(client->socket_fd, &body->player->inventory,
		sizeof(body->player->inventory));
	write(client->socket_fd, &body->player->sector->id,
		sizeof(body->player->sector->id));
	return (1);
}

int	ft_client_sync_body_server(t_body *body,
	t_multiplayer_client *client)
{
	int			sector_id;
	t_sector	*sector;
	int			i;

	i = 0;
	i += read(client->socket_fd, &body->pos, sizeof(body->pos));
	i += read(client->socket_fd, &body->forw, sizeof(body->forw));
	i += read(client->socket_fd, &body->right, sizeof(body->right));
	i += read(client->socket_fd, &body->up, sizeof(body->up));
	i += read(client->socket_fd, &body->player->height,
		sizeof(body->player->height));	
	i += read(client->socket_fd, &body->player->inventory,
		sizeof(body->player->inventory));
	i += read(client->socket_fd, &sector_id, sizeof(sector_id));
	if ((sector = ttslist_get_id_content(&g_parsed_scene->sectors, sector_id)))
		body->player->sector = sector;
	return (i);
}