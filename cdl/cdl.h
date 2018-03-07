#ifndef CDL_CDL_H_
#define CDL_CDL_H_

#include <SDL2/SDL.h>

namespace cdl {

using rect = SDL_Rect;
using point = SDL_Point;

inline bool running() {
    // Loop till we get told to quit
    SDL_Event event;
    SDL_PollEvent(&event);
    if(event.type == SDL_QUIT) {
        return false;
    } else {
        return true;
    }
}

}
#endif /* CDL_CDL_H_ */

