#ifndef CDL_FONT_H_
#define CDL_FONT_H_

#include <SDL2/SDL_ttf.h>
#include <string>
#include "surface.h"
#include "color.h"
#include "exception.h"

namespace cdl {

class Font {
public:
    Font(std::string filename, size_t size) {
        font_ = TTF_OpenFont("FreeSans.ttf", 24);
        
        if (!font_) {
            throw new exception(SDL_GetError());
        }
    }
    
    Font(const Font &other) = delete;
    
    Font(const Font &other) = delete;
    Font & operator= (const Font & other) = delete;
    
    // Move Constructor
    Font (Font&& other) {
        font_ = other.font_;
        other.font_ = nullptr;
    }
    
    // Move assignment operator
    Font& operator= (Font&& other) {
        font_ = other.font_;
        other.font_ = nullptr;
        return *this;
    }

    Surface render_solid(std::string, color) {
        return Surface(TTF_RenderText_Solid(font_,
                                            color.c_str(),
                                            SDL_Color{color.red,
                                                      color.green,
                                                      color.blue,
                                                      color.alpha}));
    }
    
    ~Font() {
        TTF_CloseFont(font_);
    }
    
private:
    TTF_Font *font_;
};

}

#endif /* CDL_WINDOW_H_ */
