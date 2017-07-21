#ifndef _SDLPP_TEXTURE
#define _SDLPP_TEXTURE

struct SDL_Texture;

namespace SDL{
  class Surface;
  class Renderer;

  class Texture{
    friend class Renderer;

  public:
    Texture(Renderer& r, Surface const& s);
    ~Texture() noexcept;

  private:
    Texture(Texture const&) = delete;
    Texture& operator=(Texture const&) = delete;

    SDL_Texture* _sdl_texture;
  };
}

#endif
