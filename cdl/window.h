#ifndef CDL_WINDOW_H_
#define CDL_WINDOW_H_

#include <SDL2/SDL.h>
#include <string>
#include "cdl.h"
#include "renderer.h"
#include "exception.h"

namespace cdl {

class Window {
public:
    Window(std::string title, rect r) {
        window_ = SDL_CreateWindow(title.c_str(),
                                   r.x,
                                   r.y,
                                   r.w,
                                   r.h,
                                   SDL_WINDOW_RESIZABLE);
        
        if (!window_) {
            throw new exception(SDL_GetError());
        }
    }
    
    Window(const Window &other) = delete;
    
    ~Window() {
        SDL_DestroyWindow(window_);
    }
    
    Renderer createRenderer() {
        return Renderer(window_);
    }
    
private:
    SDL_Window *window_;
};

}

#endif /* CDL_WINDOW_H_ */
