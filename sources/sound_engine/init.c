#include "doom_nukem.h"

t_sound_track	*ft_new_track(char *path)
{
	t_sound_track	*track;

	if (!(track = ft_memalloc(sizeof(t_sound_track))))
		return 0;
	if (SDL_LoadWAV(path, &track->spec, &track->buffer, &track->length) == NULL)
		return 0;
	return track;
}

int	ft_sound_play_track(t_sound_track *track)
{
	//track->spec.callback =  &ft_sound_default_audio_callback;
	//track->spec.userdata = track;
	SDL_AudioSpec want;
	SDL_memset(&want, 0, sizeof(want));
	want.freq = 22050;
	want.size = 512;
	want.samples = 32;
	SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &want, NULL, 0);
	track->audio_pos = track->buffer;
	track->audio_len = track->length;

	SDL_QueueAudio(deviceId, track->buffer, track->length);
	SDL_PauseAudioDevice(deviceId, 0);
	return 1;
}