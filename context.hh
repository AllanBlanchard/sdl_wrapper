#ifndef _SDLPP_CONTEXT
#define _SDLPP_CONTEXT

#include <SDL2/SDL.h>

namespace SDL{
  using FLAG = unsigned;

  class Context final{
  public:
    static FLAG const TIMER = SDL_INIT_TIMER;
    static FLAG const AUDIO = SDL_INIT_AUDIO;
    static FLAG const VIDEO = SDL_INIT_VIDEO;
    static FLAG const JOYSTICK = SDL_INIT_JOYSTICK;
    static FLAG const HAPTIC = SDL_INIT_HAPTIC;
    static FLAG const GAMECONTROLLER = SDL_INIT_GAMECONTROLLER;
    static FLAG const EVENTS = SDL_INIT_EVENTS;
    static FLAG const EVERYTHING = SDL_INIT_EVERYTHING;

    Context(FLAG const f = 0);
    void request(FLAG const f);
    void revoke(FLAG const f) noexcept;
    FLAG initiated(FLAG const f = 0) const noexcept;
    ~Context() noexcept;
    
  private:
    Context(Context const&);
    Context& operator=(Context const&);
  };
}

#endif
