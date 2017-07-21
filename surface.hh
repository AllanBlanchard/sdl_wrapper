#ifndef _SDLPP_SURFACE
#define _SDLPP_SURFACE

#include <string>
#include "color.hh"

struct SDL_Surface;

namespace SDL{
  class Surface{
    friend Surface loadBMP(std::string const& file);

  public:
    Surface(unsigned w, unsigned h);
    
    Surface(Surface const& s);
    Surface& operator=(Surface s);

    Surface(Surface&& s) noexcept;
    Surface& operator=(Surface&& s) noexcept;

    ~Surface() noexcept;
    
    void swap(Surface& s) noexcept;

    unsigned width() const noexcept;
    unsigned height() const noexcept;

    void lock();
    void unlock() noexcept;
    bool must_lock() const noexcept;

    void blit(Surface const& s);

  private:
    Surface(SDL_Surface* ptr) : _sdl_surface(ptr){}

    SDL_Surface* _sdl_surface;

    friend class Texture;
  };

  Surface loadBMP(std::string const& file);
}

#endif
