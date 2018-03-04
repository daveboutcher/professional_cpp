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

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Cards",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          480, // Width
                                          480, // Height
                                          SDL_WINDOW_RESIZABLE);
    
    // Create a renderer for the window
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
                                                SDL_RENDERER_ACCELERATED);
    
    // Load the four images
    SDL_Surface* club_surface = IMG_Load("club.png");
    SDL_Texture* club_texture = SDL_CreateTextureFromSurface(renderer,
                                                             club_surface);

    int club_width, club_height;
    SDL_QueryTexture(club_texture, nullptr, nullptr, &club_width, &club_height);
    
    SDL_Surface* diamond_surface = IMG_Load("diamond.png");
    SDL_Texture* diamond_texture = SDL_CreateTextureFromSurface(renderer,
                                                                diamond_surface);
    
    int diamond_width, diamond_height;
    SDL_QueryTexture(diamond_texture, nullptr, nullptr, &diamond_width, &diamond_height);
    
    SDL_Surface* heart_surface = IMG_Load("heart.png");
    SDL_Texture* heart_texture = SDL_CreateTextureFromSurface(renderer,
                                                              heart_surface);
    
    int heart_width, heart_height;
    SDL_QueryTexture(heart_texture, nullptr, nullptr, &heart_width, &heart_height);
    
    SDL_Surface* spade_surface = IMG_Load("spade.png");
    SDL_Texture* spade_texture = SDL_CreateTextureFromSurface(renderer,
                                                              spade_surface);

    int spade_width, spade_height;
    SDL_QueryTexture(spade_texture, nullptr, nullptr, &spade_width, &spade_height);
    
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

        // Get the size of the current renderer
        SDL_Rect rect;
        SDL_RenderGetViewport(renderer, &rect);

        // We are going to display 4 images, with padding between them and
        // on the side...that works out to 5 blocks of padding
        int padding = ((rect.w -
                        (club_width + diamond_width +
                         heart_width + spade_width))
                       / 5);
                
        // Figure out everyone's positions
        SDL_Rect club_pos = {padding, 10,
                             club_surface->w, club_surface->h};
        SDL_Rect diamond_pos = {padding + club_pos.x + club_pos.w, 10,
                                diamond_width, diamond_height};
        SDL_Rect heart_pos = {padding + diamond_pos.x + diamond_pos.w, 10,
                              heart_width, heart_height};
        SDL_Rect spade_pos = {padding + heart_pos.x + heart_pos.w, 10,
                              spade_width, spade_height};
                
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
