#ifndef CDL_SURFACE_H_
#define CDL_SURFACE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "dimensions.h"
#include "exception.h"

namespace cdl {

class Texture;

class Surface {
public:
	Surface(std::string file_name) {
		surface_ = IMG_Load(file_name.c_str());
		
		if (!surface_) {
			throw exception(SDL_GetError());
		}
	}

	Surface(const Surface &other) = delete;

	~Surface() {
		SDL_FreeSurface(surface_);
	}

	cdl::size size() const {
		return cdl::size{surface_->w, surface_->h};
	}

private:
	friend class Texture;
	SDL_Surface *surface_;
};

}

#endif /* CDL_SURFACE_H_ */

