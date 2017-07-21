#include "window.hh"
#include "sdlexcept.hh"

#include <cassert>
#include <limits>

namespace SDL{

  Window::Window(std::string const& s, unsigned w, unsigned h, FLAG const f) :
    _sdl_win{ SDL_CreateWindow(s.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, f) }
  {
    assert(w <= std::numeric_limits<int>::max() && 
	   h <= std::numeric_limits<int>::max() && 
	   "SDL 2 does not authorize too large window");

    if(_sdl_win == nullptr) throw Exception{};
  }

  Window::~Window() noexcept{
    SDL_DestroyWindow(_sdl_win);
  }


}
