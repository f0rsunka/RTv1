
#include "rtv1.h"

void	event_camera(t_rtv *r)
{
	if (r->sdl.event.key.keysym.sym == SDLK_PAGEUP)
	{
		printf("1\n");
		r->camera.angle.y += 5.0f;
		r->camera.was_pressed = 1;
	}
	else if (r->sdl.event.key.keysym.sym == SDLK_PAGEDOWN)
	{
		printf("2\n");
		r->camera.angle.y -= 5.0f;
		r->camera.was_pressed = 1;
	}
	else if (r->sdl.event.key.keysym.sym == SDLK_LEFT)
	{
		printf("3\n");
		r->camera.angle.x -= 5.0f;
		r->camera.was_pressed = 1;
	}
	else if (r->sdl.event.key.keysym.sym == SDLK_RIGHT)
	{
		printf("4\n");
		r->camera.angle.x += 5.0f;
		r->camera.was_pressed = 1;
	}
	else if (r->sdl.event.key.keysym.sym == SDLK_w)
	{
		printf("5\n");
		r->camera.angle.z += 5.0f;
		r->camera.was_pressed = 1;
	}
	else if (r->sdl.event.key.keysym.sym == SDLK_s)
	{
		printf("6\n");
		r->camera.angle.z -= 5.0f;
		r->camera.was_pressed = 1;
	}
	else if (r->camera.was_pressed == 1)
	{
		// printf("cringe\n");
		rotate(&r->camera);
		render(r);
		r->camera.was_pressed = 0;
	}
}

void	rotate_x(t_camera *c)
{
	c->dir.x = c->dir.x;
	c->dir.y = cos(c->angle.x * DEG2RAD) * c->dir.y + (-sin(c->angle.x * DEG2RAD)) * c->dir.y;
	c->dir.z = sin(c->dir.x * DEG2RAD) * c->dir.z + cos(c->angle.x * DEG2RAD) * c->dir.z;
}

void	rotate_y(t_camera *c)
{
	c->dir.x = c->dir.x * cos(c->angle.y * DEG2RAD) + c->dir.x * sin(c->angle.y * DEG2RAD);
	c->dir.y = c->dir.y;
	c->dir.z = c->dir.z * (-sin(c->angle.y * DEG2RAD)) + c->dir.z * cos(c->angle.y * DEG2RAD);
}

void	rotate_z(t_camera *c)
{
	c->dir.x = cos(c->angle.z * DEG2RAD) * c->dir.x + (-sin(c->angle.z * DEG2RAD)) * c->dir.x;
	c->dir.y = sin(c->angle.z * DEG2RAD) * c->dir.y + c->dir.y * cos(c->angle.z * DEG2RAD);
	c->dir.z = c->dir.z;
}

void	rotate(t_camera *c)
{
	rotate_x(c);
	rotate_y(c);
	rotate_z(c);
}
