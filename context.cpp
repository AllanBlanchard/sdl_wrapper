#include "context.hh"
#include "sdlexcept.hh"

#include <SDL2/SDL.h>

namespace SDL{
  Context::Context(FLAG const f){
    if(SDL_Init(f) != 0)
      throw Exception{};
  }
  
  void Context::request(FLAG const f){
    if(SDL_InitSubSystem(f) != 0)
      throw Exception{};
  }
   
  void Context::revoke(FLAG const f) noexcept{
    SDL_QuitSubSystem(f);
  }

  FLAG Context::initiated(FLAG const f) const noexcept{
    return static_cast<FLAG>(SDL_WasInit(f));
  }
   
  Context::~Context() noexcept{
    SDL_Quit();
  }
}
