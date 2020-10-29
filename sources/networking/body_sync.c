#include "doom_nukem.h"

int	ft_client_sync_body_input_server(t_body *body,
	t_multiplayer_client *client)
{
	write(client->socket_fd, body->player->input, sizeof(body->player->input));
	write(client->socket_fd, body->player->mouse_buttons,
		sizeof(body->player->mouse_buttons));
	write(client->socket_fd, &body->player->mouse_rel,
		sizeof(body->player->mouse_rel));
	return (1);
}

int	ft_server_sync_body_input_client(t_body *body,
	t_multiplayer_remote_client *client)
{
	read(client->socket_fd, body->player->input, sizeof(body->player->input));
	read(client->socket_fd, body->player->mouse_buttons,
		sizeof(body->player->mouse_buttons));
	read(client->socket_fd, &body->player->mouse_rel,
		sizeof(body->player->mouse_rel));
	return (1);
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

	read(client->socket_fd, &body->pos, sizeof(body->pos));
	read(client->socket_fd, &body->forw, sizeof(body->forw));
	read(client->socket_fd, &body->right, sizeof(body->right));
	read(client->socket_fd, &body->up, sizeof(body->up));
	read(client->socket_fd, &body->player->height,
		sizeof(body->player->height));	
	read(client->socket_fd, &body->player->inventory,
		sizeof(body->player->inventory));
	read(client->socket_fd, &sector_id, sizeof(sector_id));
	if ((sector = ttslist_get_id_content(&g_parsed_scene->sectors, sector_id)))
		body->player->sector = sector;
	return (1);
}