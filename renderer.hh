#ifndef _SDLPP_RENDERER
#define _SDLPP_RENDERER

#include <SDL2/SDL_render.h>

struct SDL_Renderer;

namespace SDL{
  using FLAG = unsigned;
  class Window;
  class Texture;

  class Renderer{
  public:
    static FLAG const SOFTWARE = SDL_RENDERER_SOFTWARE;
    static FLAG const ACCELERATED = SDL_RENDERER_ACCELERATED;
    static FLAG const PRESENTVSYNC = SDL_RENDERER_PRESENTVSYNC;
    static FLAG const TARGETTEXTURE = SDL_RENDERER_TARGETTEXTURE;
    
  public:
    Renderer(Window& window, FLAG const flags, int device);
    ~Renderer() noexcept;

    void clear();
    void copy(Texture const& t);
    void update() noexcept;
    
  private:
    Renderer(Renderer const&) = delete;
    Renderer& operator=(Renderer const&) = delete;

    SDL_Renderer* _sdl_renderer;

    friend class Texture;
  };
}

#endif
