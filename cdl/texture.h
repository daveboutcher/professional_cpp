#ifndef CDL_TEXTURE_H_
#define CDL_TEXTURE_H_

#include <SDL2/SDL.h>
#include "cdl.h"
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
    Texture(const Texture &other) = delete;

    ~Texture() {
        SDL_DestroyTexture(texture_);
    }

    cdl::rect size() const {
        rect ret{0, 0, 0, 0};
        SDL_QueryTexture(texture_, nullptr, nullptr, &ret.w, &ret.h);
        return ret;
    }

private:
    SDL_Texture *texture_;
};

}

#endif /* CDL_TEXTURE_H_ */

