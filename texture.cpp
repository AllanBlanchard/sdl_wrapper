#include "renderer.hh"
#include "texture.hh"
#include "surface.hh"
#include "sdlexcept.hh"

#include <SDL2/SDL_render.h>

namespace SDL{
  Texture::Texture(Renderer& r, Surface const& s) :
    _sdl_texture{ SDL_CreateTextureFromSurface(r._sdl_renderer, s._sdl_surface) }
  {
    if(_sdl_texture == nullptr)
      throw Exception{};
  }
  
  Texture::~Texture() noexcept{
    SDL_DestroyTexture(_sdl_texture);
  }
}
