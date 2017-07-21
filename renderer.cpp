#include "texture.hh"
#include "renderer.hh"
#include "window.hh"
#include "sdlexcept.hh"

namespace SDL{
  
  Renderer::Renderer(Window& window, FLAG const flags, int device)
    : _sdl_renderer{ SDL_CreateRenderer(window._sdl_win, device, flags) }
  {
    if(_sdl_renderer == nullptr)
      throw Exception{};
  }

  Renderer::~Renderer() noexcept{
    SDL_DestroyRenderer(_sdl_renderer);
  }

  void Renderer::clear(){
    if(SDL_RenderClear(_sdl_renderer) != 0)
      throw Exception{};
  }
  
  void Renderer::copy(Texture const& t){
    SDL_Texture* pt{ t._sdl_texture };
    if(SDL_RenderCopy(_sdl_renderer, pt, nullptr, nullptr) != 0)
      throw Exception{};
  }
  
  void Renderer::update() noexcept{
    SDL_RenderPresent(_sdl_renderer);
  }
}
