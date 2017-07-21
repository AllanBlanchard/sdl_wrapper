#ifndef _SDLPP_EXCEPT
#define _SDLPP_EXCEPT

#include <SDL2/SDL_error.h>
#include <stdexcept>
#include <string>

namespace SDL{
  class Exception : public std::runtime_error{
  public:
    explicit Exception () : std::runtime_error{ SDL_GetError() }{}
    
    virtual ~Exception(){}
  };
}

#endif
