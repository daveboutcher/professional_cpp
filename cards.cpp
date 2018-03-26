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
#include <SDL2/SDL_ttf.h>

int main(int argc, char *argv[])
{
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

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
			auto s = card_surf.size();
			std::cout << "Size " << s.width << " x " << s.height << SDL_GetPixelFormatName(card_surf.surface_->format->format) << std::endl;
			cdl::Texture card_text = renderer.createTexture(card_surf);
			cards.push_back(std::move(card_text));
		}

		auto cs = SDL_CreateRGBSurface(0, 128, 192, 32,
									   0x000000ff,
									   0x0000ff00,
									   0x00ff0000,
									   0xff000000);

		SDL_FillRect(cs, NULL, SDL_MapRGB(cs->format, 255, 255, 255));

		cdl::Surface club("club.png");
		SDL_Rect ps{0,   0, 32, 32};
		SDL_Rect pd{48, 80, 32, 32};
		SDL_BlitScaled(club.surface_, nullptr, cs, &pd);

		TTF_Font *font = TTF_OpenFont("FreeSans.ttf", 24);
		if (font == NULL) {
			std::cerr << "error: font not found" << std::endl;
			exit(EXIT_FAILURE);
		}

		SDL_Color textColor = {0, 0, 0, 0};

		cdl::Surface txt_surf(TTF_RenderText_Solid(font, "2", textColor));
		
		auto ts = txt_surf.size();

		SDL_Rect td{5, 5, ts.width, ts.height};
		SDL_BlitScaled(txt_surf.surface_, nullptr, cs, &td);
			
		// cdl::Surface txt_surf = cdl::Surface();
		cdl::Surface c_surf = cdl::Surface(cs);

		cdl::Texture text_text = renderer.createTexture(c_surf);
		
		// This is the main SDL loop
		while(cdl::running()) {

			renderer.clear();

			// Add the row of textures at Y position 10
			renderer.addRow(cards, 10);

			renderer.add(text_text, cdl::position{30, 10});

			renderer.display();
		}
	} catch (const cdl::exception &e) {
		std::cerr << e.what() << std::endl;
	}

    SDL_Quit();
    return 0;
}
