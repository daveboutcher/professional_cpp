#ifndef CDL_RENDERER_H_
#define CDL_RENDERER_H_

#include <SDL2/SDL.h>
#include "texture.h"
#include "dimensions.h"
#include "exception.h"

namespace cdl {

class Window;
class Renderer {
private:
	friend class Window;
	
	Renderer(SDL_Window *sdl_window) {
		renderer_ = SDL_CreateRenderer(sdl_window,
										-1,
										SDL_RENDERER_ACCELERATED);

		if (!renderer_) {
			throw new exception(SDL_GetError());
		}
	}

public:
	Renderer(const Window &other) = delete;

	~Renderer() {
		SDL_DestroyRenderer(renderer_);
	}

	Texture createTexture(const Surface &surface) {
		return Texture(renderer_, surface);
	}

	void add(const Texture &texture, const position &pos) {
		cdl::size s = texture.size();
		SDL_Rect rect{pos.x, pos.y, s.width, s.height};
		SDL_RenderCopy(renderer_, texture.texture_, nullptr, &rect);
	}

	void clear() {
		SDL_RenderClear(renderer_);
	}

	void display() {
		SDL_RenderPresent(renderer_);
	}

	cdl::size size() {
		SDL_Rect rect;
		SDL_RenderGetViewport(renderer_, &rect);
		return cdl::size{rect.w, rect.h};
	}

	// Add a row of textures at the given Y offset
	void addRow(const std::vector<cdl::Texture> & textures, int y_pos) {
		// get the size 
		cdl::size render_size = size();

		int total_width = 0;
		for (const auto &t: textures) {
			total_width += t.size().width;
		}

		int padding = (render_size.width - total_width) / (textures.size() + 1);
		
		int currentX = padding;
		for (const auto &t: textures) {
			add(t, position{currentX, y_pos});
			currentX += t.size().width + padding;
		}
	}
	
private:
	SDL_Renderer *renderer_;
};

}

#endif /* CDL_RENDERER_H_ */

