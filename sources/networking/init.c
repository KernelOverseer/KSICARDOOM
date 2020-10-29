#include "networking.h"

int	ft_init_client(t_multiplayer_client	*client)
{
	int					sockfd;
    struct sockaddr_in	serv_addr;
    struct hostent		*server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        return (0);
    server = gethostbyname("localhost");
    if (server == NULL)
		return (0);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(NETWORK_PORT_NUMBER);
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        return (0);
	client->serv_addr = serv_addr;
	client->server = server;
	client->socket_fd = sockfd;
	return (1);
}

int	ft_init_server(t_multiplayer_server *server)
{
	int					sockfd;
    struct sockaddr_in	serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
		return (0);
    ft_bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(NETWORK_PORT_NUMBER);
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
    	sizeof(serv_addr)) < 0) 
		return (0);
	server->server_addr = serv_addr;
	server->socket_fd = sockfd;
	ttslist_init(&server->clients);
	return (1);
}

int	ft_listen_for_client(t_multiplayer_server *server)
{
	int							clilen;
	int							client_fd;
	struct sockaddr_in			cli_addr;
	t_multiplayer_remote_client	*remote_client;

	listen(server->socket_fd, 5);
    clilen = sizeof(cli_addr);
    client_fd = accept(server->socket_fd,
		(struct sockaddr *) &cli_addr, &clilen);
    if (client_fd < 0)
		return (0);
	if (!(remote_client = ft_memalloc(sizeof(t_multiplayer_remote_client))))
		return (0);
	remote_client->client_addr = cli_addr;
	remote_client->socket_fd = client_fd;
	fcntl(remote_client->socket_fd, F_SETFL, fcntl(remote_client->socket_fd,
		F_GETFL, 0) | O_NONBLOCK);
	server->clients.push(&server->clients, remote_client);
	return (1);
}