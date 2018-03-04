/***********************************************************************
 * Card Game Example - part of the Professional C++ tutorial
 ***********************************************************************
 * This work is licensed under a Creative Commons Attribution 4.0 
 * International License. Details at 
 * http://creativecommons.org/licenses/by/4.0/
 ***********************************************************************/
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char *argv[])
{
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    int window_width = 480;
    int window_height = 480;

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Cards",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          window_width,
                                          window_height,
                                          SDL_WINDOW_SHOWN);
    
    // Create a renderer for the window
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
                                                SDL_RENDERER_ACCELERATED);
    
    // Load the four images
    SDL_Surface* club_surface = IMG_Load("club.png");
    SDL_Texture* club_texture = SDL_CreateTextureFromSurface(renderer,
                                                             club_surface);
    
    SDL_Surface* diamond_surface = IMG_Load("diamond.png");
    SDL_Texture* diamond_texture = SDL_CreateTextureFromSurface(renderer,
                                                                diamond_surface);
    
    SDL_Surface* heart_surface = IMG_Load("heart.png");
    SDL_Texture* heart_texture = SDL_CreateTextureFromSurface(renderer,
                                                              heart_surface);
    
    SDL_Surface* spade_surface = IMG_Load("spade.png");
    SDL_Texture* spade_texture = SDL_CreateTextureFromSurface(renderer,
                                                              spade_surface);

    // Assume all the images are the same width
    int card_width = club_surface->w;

    // We are going to display 4 images, with padding between them and
    // on the side...that works out to 5 blocks of padding
    int padding = (window_width - (card_width * 4)) / 5;

    // Figure out everyone's positions
    SDL_Rect club_pos =    {padding * 1 + card_width * 0, padding,
                            club_surface->w, club_surface->h};
    SDL_Rect diamond_pos = {padding * 2 + card_width * 1, padding,
                            diamond_surface->w, diamond_surface->h};
    SDL_Rect heart_pos =   {padding * 3 + card_width * 2, padding,
                            heart_surface->w, heart_surface->h};
    SDL_Rect spade_pos =   {padding * 4 + card_width * 3, padding,
                            spade_surface->w, spade_surface->h};

    // This is the main SDL loop
    while(true) {
        // Loop till we get told to quit
        SDL_Event event;
        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT) {
            break;
        }

        // Clear the renderer
        SDL_RenderClear(renderer);

        // Copy in our images
        SDL_RenderCopy(renderer, club_texture, nullptr, &club_pos);
        SDL_RenderCopy(renderer, diamond_texture, nullptr, &diamond_pos);
        SDL_RenderCopy(renderer, heart_texture, nullptr, &heart_pos);
        SDL_RenderCopy(renderer, spade_texture, nullptr, &spade_pos);

        // Yay...display the images
        SDL_RenderPresent(renderer);
    }

    // Clean up everything
    SDL_DestroyTexture(club_texture);
    SDL_FreeSurface(club_surface);
    
    SDL_DestroyTexture(diamond_texture);
    SDL_FreeSurface(diamond_surface);
    
    SDL_DestroyTexture(heart_texture);
    SDL_FreeSurface(heart_surface);
    
    SDL_DestroyTexture(spade_texture);
    SDL_FreeSurface(spade_surface);
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
