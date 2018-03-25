#ifndef CDL_TEXTURE_H_
#define CDL_TEXTURE_H_

#include <SDL2/SDL.h>
#include "surface.h"
#include "exception.h"

namespace cdl {

class Renderer;
class Texture {
private:
    friend Renderer;
    Texture(SDL_Renderer *sdl_renderer, const Surface &surface) {
        texture_ = SDL_CreateTextureFromSurface(sdl_renderer,
                                                surface.surface_);
        if (!texture_) {
            throw new exception(SDL_GetError());
        }
    }

public:
    ~Texture() {
        SDL_DestroyTexture(texture_);
    }

	Texture(const Texture &other) = delete;
	Texture & operator= (const Texture & other) = delete;

	// Move Constructor
	Texture (Texture&& other) {
		texture_ = other.texture_;
		other.texture_ = nullptr;
	}
	
	// Move assignment operator
	Texture& operator= (Texture&& other) {
		texture_ = other.texture_;
		other.texture_ = nullptr;
		return *this;
	}

	cdl::size size() const {
        cdl::size ret;
        SDL_QueryTexture(texture_, NULL, NULL, &ret.width, &ret.height);
        return ret;
    }

private:
    SDL_Texture *texture_;
};

}

#endif /* CDL_TEXTURE_H_ */

