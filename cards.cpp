/***********************************************************************
 * Card Game Example - part of the Professional C++ tutorial
 ***********************************************************************
 * This work is licensed under a Creative Commons Attribution 4.0 
 * International License. Details at 
 * http://creativecommons.org/licenses/by/4.0/
 ***********************************************************************/
#include <iostream>
#include "cdl/cdl.h" // includes the "running()" method
#include "cdl/window.h"
#include "cdl/surface.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char *argv[])
{
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

	try {

		cdl::Window window = cdl::Window("Cards",
										 cdl::position{SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED},
										 cdl::size{480, 480});

		cdl::Renderer renderer = window.createRenderer();
		
		// Load the four images
		cdl::Surface club_surface = cdl::Surface("club.png");
		cdl::Texture club_texture = renderer.createTexture(club_surface);
		
		cdl::Surface diamond_surface = cdl::Surface("diamond.png");
		cdl::Texture diamond_texture = renderer.createTexture(diamond_surface);
		
		cdl::Surface heart_surface = cdl::Surface("heart.png");
		cdl::Texture heart_texture = renderer.createTexture(heart_surface);
		
		cdl::Surface spade_surface = cdl::Surface("spade.png");
		cdl::Texture spade_texture = renderer.createTexture(spade_surface);
		
		// This is the main SDL loop
		while(cdl::running()) {

			renderer.clear();

			// Get the window width
			int window_width = window.width();
			
			// We are going to display 4 images, with padding between them and
			// on the side...that works out to 5 blocks of padding
			int padding = ((window_width -
							(club_texture.size().width + diamond_texture.size().width +
							 heart_texture.size().width + spade_texture.size().width))
						   / 5);
			
			int currentX = padding;
			
			renderer.add(club_texture, cdl::position{currentX, 10});
			currentX += club_texture.size().width + padding;
			
			renderer.add(diamond_texture, cdl::position{currentX, 10});
			currentX += diamond_texture.size().width + padding;
			
			renderer.add(heart_texture, cdl::position{currentX, 10});
			currentX += heart_texture.size().width + padding;
			
			renderer.add(spade_texture, cdl::position{currentX, 10});
			currentX += spade_texture.size().width + padding;

			renderer.display();
		}
	} catch (const cdl::exception &e) {
		std::cerr << e.what() << std::endl;
	}

    SDL_Quit();
    return 0;
}
