#include "doom_nukem.h"

Mix_Chunk	*g_sound_list[SOUND_EFFECTS_COUNT];
char		*g_sound_file_names[SOUND_EFFECTS_COUNT] = {
	"sound/theme.wav",
	"sound/menu_effect.wav",
	"sound/gun.wav",
	"sound/fart.wav",
	"sound/empty_gun.wav",
};

int	ft_get_sound_body_distance(t_body *body)
{
	t_vec3	dist;

	dist = (t_vec3){g_doom_env->main_scene.camera.position.x - body->pos.x,
		g_doom_env->main_scene.camera.position.y - body->pos.y,
		g_doom_env->main_scene.camera.height - body->pos.z};
	return (ft_vec3_mag(dist));
}

int	ft_init_sound(void)
{
	int	i;

	i = 0;
	ft_bzero(g_sound_list, sizeof(g_sound_list));
	Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 2048 );
	while (i < SOUND_EFFECTS_COUNT)
	{
		g_sound_list[i] = Mix_LoadWAV(g_sound_file_names[i]);
		i++;
	}
	return (0);
}

int	ft_sound_play_track(uint32_t sound_index, double distance, int loop)
{
	if (distance == 0)
		distance = 1;
	if (sound_index >= SOUND_EFFECTS_COUNT || !g_sound_list[sound_index])
		return (0);
	g_sound_list[sound_index]->volume = 128 * (ft_min(0,
		MAX_SOUND_DISTANCE - distance) / MAX_SOUND_DISTANCE);
	Mix_PlayChannel( -1, g_sound_list[sound_index], loop );
	return (1);
}