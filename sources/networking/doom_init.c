#include "doom_nukem.h"

int	ft_init_doom_multiplayer(t_doom_env *env, int network_role)
{
	env->multiplayer.role = network_role;
	if (network_role == NETWORK_ROLE_SERVER)
		return (ft_init_server(&env->multiplayer.server) &&
			ft_listen_for_client(&env->multiplayer.server));
	else if (network_role == NETWORK_ROLE_CLIENT)
		return (ft_init_client(&env->multiplayer.client));
	else
		return (1);
}