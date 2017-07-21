#ifndef _SDLPP_WINDOW
#define _SDLPP_WINDOW

#include <string>
#include <SDL2/SDL_video.h>

struct SDL_Window;

namespace SDL{
  using FLAG = unsigned;

  class Window{
  public :
    static FLAG const FULLSCREEN         = SDL_WINDOW_FULLSCREEN;
    static FLAG const FULLSCREEN_DESKTOP = SDL_WINDOW_FULLSCREEN_DESKTOP;
    static FLAG const OPENGL             = SDL_WINDOW_OPENGL;
    static FLAG const HIDDEN             = SDL_WINDOW_HIDDEN;
    static FLAG const BORDERLESS         = SDL_WINDOW_BORDERLESS;
    static FLAG const RESIZABLE          = SDL_WINDOW_RESIZABLE;
    static FLAG const MINIMIZED          = SDL_WINDOW_MINIMIZED;
    static FLAG const MAXIMIZED          = SDL_WINDOW_MAXIMIZED;
    static FLAG const INPUT_GRABBED      = SDL_WINDOW_INPUT_GRABBED;
    static FLAG const HIGHDPI            = SDL_WINDOW_ALLOW_HIGHDPI;
    
  public :
    Window(std::string const&, unsigned, unsigned, FLAG const);
    ~Window() noexcept;
    
  private:
    Window(Window const&)            = delete;
    Window& operator=(Window const&) = delete;

    SDL_Window* _sdl_win;

    friend class Renderer;
  };


}

#endif
