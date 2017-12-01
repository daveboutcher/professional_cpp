#include <iostream>
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>

int main(int argc, char **argv) {
	SDL_Surface *surface1 = IMG_Load("heart.bmp");

	if (!surface1) {
		std::cout << "failed to read heart.bmp: " << SDL_GetError() << std::endl;
		return 0;
	}

	SDL_Surface* fmtsurf = SDL_CreateRGBSurfaceWithFormat(0, surface1->w, surface1->h, 32, SDL_PIXELFORMAT_RGB888);
    if (fmtsurf == NULL) {
        SDL_Log("SDL_CreateRGBSurfaceWithFormat() failed: %s", SDL_GetError());
        exit(1);
    }

	SDL_Surface *surface = SDL_ConvertSurface(surface1, fmtsurf->format, 0);

	SDL_PixelFormat *format = surface->format;

	std::cout << "h:" << surface->h << " w:" << surface->w << " pitch:" << surface->pitch << " format: " << SDL_GetPixelFormatName(format->format) << " BitsPerPixel:" << (int)format->BitsPerPixel << " BytesPerPixel:" << (int)format->BytesPerPixel << " Rmask " << format->Rmask << std::endl;

	SDL_FreeSurface(surface);
    return 0;
}


