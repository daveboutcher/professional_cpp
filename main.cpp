#include <iostream>
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>

int main(int argc, char **argv) {
    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_Surface *surface = IMG_Load("heart.bmp");
    
    if (!surface) {
        std::cout << "failed to read heart.bmp: " << SDL_GetError() << std::endl;
        return 0;
    }
    
    SDL_PixelFormat *format = surface->format;
    
    std::cout << "h:" << surface->h << " w:" << surface->w << " pitch:" << surface->pitch << " format: " << SDL_GetPixelFormatName(format->format) << " BitsPerPixel:" << (int)format->BitsPerPixel << " BytesPerPixel:" << (int)format->BytesPerPixel << " Rmask " << std::hex << format->Rmask << " Gmask " << format->Gmask << " Bmask " << format->Bmask << " Amask " << format->Amask << std::endl;

    SDL_LockSurface(surface);

    using x = uint32_t[surface->h][surface->w];
    x d;
    auto dp = &d;

    auto data = static_cast<decltype(dp)>(surface->pixels);

    for (size_t i=0; i<surface->h; i++) {
        for (size_t j=0; j< surface->w; j++) 
            std::cout << std::hex << ((*data)[i][j] & 0x00ffffffff) << " ";
        std::cout << std::endl;
    }
  
    SDL_UnlockSurface(surface);
    
    SDL_FreeSurface(surface);

    SDL_Quit();
    return 0;
}


