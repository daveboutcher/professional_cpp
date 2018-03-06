#ifndef CDL_WINDOW_H_
#define CDL_WINDOW_H_

#include <SDL2/SDL.h>
#include <string>
#include "dimensions.h"
#include "exception.h"

namespace cdl {

class Window {
public:
	Window(std::string title, position p, size s) {
		m_window = SDL_CreateWindow(title.c_str(),
									p.x,
									p.y,
									s.width,
									s.height,
									0);

		if (!m_window) {
			throw new exception(SDL_GetError());
		}
	}

	~Window() {
		SDL_DestroyWindow(m_window);
	}
	
	//private:
	SDL_Window *m_window;
};

}

#endif /* CDL_WINDOW_H_ */

