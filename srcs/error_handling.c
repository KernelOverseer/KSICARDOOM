char	*ft_strerror(int err)
{
	if (err == F_OPEN)
		return (F_OPEN_T);
	if (err == N_WORD)
		return (N_WORD_T);
	if (err == N_SCENE)
		return (N_SCENE_T);
	if (err == N_PROP)
		return (N_PROP_T);
	if (err == P_MIXED)
		return (P_MIXED_T);
	if (err == P_EXTRA)
		return (P_EXTRA_T);
	if (err == P_MISSING)
		return (P_MISSING_T);
	return (NULL);
}

int		ft_perror(char *command, char *arg, int err)
{
	if (command)
		ft_putstr_fd(command, 2);
	ft_putstr_fd(ft_strerror(err), 2);
	if (arg)
		ft_putendl_fd(arg, 2);
	else
		ft_putchar_fd('\n', 2);
	return (err);
}