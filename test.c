#include <stdio.h>
#include <SDL.h>

int		main(void)
{
	int err = SDL_Init(SDL_INIT_EVERYTHING);
	printf("SDL_Init: [%s]\n", err ? "FAILED" : "SUCCESS");
	return (0);
}