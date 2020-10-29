#ifndef NETWORKING_H
# define NETWORKING_H
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netdb.h>
# include "ttslist.h"
# include "centropy.h"
# define NETWORK_PORT_NUMBER 7331
# define NETWORK_ROLE_NONE 0
# define NETWORK_ROLE_CLIENT 1
# define NETWORK_ROLE_SERVER 2
# define NETWORK_MAX_PLAYERS 5

typedef struct	s_multiplayer_client
{
	int					socket_fd;
	struct	sockaddr_in	serv_addr;
	struct	hostent		*server;
}				t_multiplayer_client;

typedef struct s_multiplayer_remote_client
{
	int					socket_fd;
	struct sockaddr_in	client_addr;
}				t_multiplayer_remote_client;


typedef struct s_multiplayer_server
{
	int					socket_fd;
	struct sockaddr_in	server_addr;
	t_list_head			clients;
}				t_multiplayer_server;

typedef struct s_doom_multiplayer
{
	t_multiplayer_client	client;
	t_multiplayer_server	server;
	int						role;
}				t_doom_multiplayer;

/*
**	CLIENT FUNCTIONS
*/

int	ft_init_client(t_multiplayer_client	*client);

/*
**	SERVER FUNCTIONS
*/

int	ft_init_server(t_multiplayer_server *server);
int	ft_listen_for_client(t_multiplayer_server *server);
int	ft_listen_for_client_async(t_multiplayer_server *server, int max_clients);


#endif