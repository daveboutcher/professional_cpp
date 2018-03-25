/***********************************************************************
 * Card Game Example - part of the Professional C++ tutorial
 ***********************************************************************
 * This work is licensed under a Creative Commons Attribution 4.0 
 * International License. Details at 
 * http://creativecommons.org/licenses/by/4.0/
 ***********************************************************************/
#include <vector>
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

		std::vector<cdl::Texture> cards;

		for (const auto &filename: std::initializer_list<const char *>{"club.png",
  				                                                       "diamond.png",
					                                                   "heart.png",
					                                                   "spade.png"}) {
			cdl::Surface card_surf = cdl::Surface(filename);
			cdl::Texture card_text = renderer.createTexture(card_surf);
			cards.push_back(std::move(card_text));
		}
		
		// This is the main SDL loop
		while(cdl::running()) {

			renderer.clear();

			// Add the row of textures at Y position 10
			renderer.addRow(cards, 10);

			renderer.display();
		}
	} catch (const cdl::exception &e) {
		std::cerr << e.what() << std::endl;
	}

    SDL_Quit();
    return 0;
}
