#ifndef _SDLPP_EVENT
#define _SDLPP_EVENT

#include <SDL2/SDL_events.h>

namespace SDL{
  class Event{
  public:
    Event() : _sdl_event{} {}
    bool poll(){ return static_cast<bool>(SDL_PollEvent(&_sdl_event)); }
    unsigned type() const{ return _sdl_event.type; }

  private:
    SDL_Event _sdl_event;
  };
}

#endif
