#include <stdio.h>
#include <fcntl.h>
#include "serializer.h"
#include "graphics_structs.h"
#include "libgl.h"

int main(void)
{
	int r_fd;
	int w_fd;

	w_fd = open("testfile.map", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	r_fd = open("testfile.map", O_RDONLY);

	t_wall new_wall = (t_wall){(t_vec2){0, 1}, (t_vec2){1, 2}, NULL, 1337};
	t_wall wall_copy;

	ft_serialize_wall(w_fd, &new_wall);
	
	close(w_fd); // make sure the changes to the file are saved and not buffered
	
	ft_deserialize_wall(r_fd, &wall_copy);
	printf("p1 {%f, %f}\np2 {%f, %f}\ntexture %p\nprops %d\n", wall_copy.p1.x, wall_copy.p1.y, wall_copy.p2.x, wall_copy.p2.y, wall_copy.texture, wall_copy.props);
	return (0);
}
