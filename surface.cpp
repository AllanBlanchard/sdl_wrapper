#include "surface.hh"
#include "sdlexcept.hh"

#include <cassert>
#include <utility>
#include <limits>
#include <SDL2/SDL_surface.h>

namespace SDL{
  Surface::Surface(unsigned w, unsigned h) :
    _sdl_surface{ SDL_CreateRGBSurface(0, static_cast<int>(w), static_cast<int>(h), 32, 0, 0, 0, 0) }
  {
    assert(w < std::numeric_limits<int>::max() &&
	   h < std::numeric_limits<int>::max() &&
	   "SDL can't create a Surface with size > INT_MAX");

    if(_sdl_surface == nullptr)
      throw Exception{};
  }

  Surface::Surface(Surface const& s) : 
    Surface{ s.width(), s.height() }
  {
    blit(s);
  }
  
  Surface& Surface::operator=(Surface s){
    this->swap(s);
    return *this;
  }
  
  Surface::Surface(Surface&& s) noexcept : 
    _sdl_surface(std::move(s._sdl_surface))
  {}
  
  Surface& Surface::operator=(Surface&& s) noexcept{
    assert(this != &s && "auto-move-assignment semantically unsound");

    SDL_FreeSurface(_sdl_surface);
    _sdl_surface = std::move(s._sdl_surface);
    return *this;
  }
  
  Surface::~Surface(){
    SDL_FreeSurface(_sdl_surface);
  }

  void Surface::swap(Surface& s) noexcept{
    std::swap(s._sdl_surface, _sdl_surface);
  }
  
  unsigned Surface::width() const noexcept{
    return static_cast<unsigned>(_sdl_surface->w);
  }

  unsigned Surface::height() const noexcept{
    return static_cast<unsigned>(_sdl_surface->h);
  }

  void Surface::blit(Surface const & s){
    if(SDL_BlitSurface(s._sdl_surface, nullptr, _sdl_surface, nullptr))
      throw Exception{};
  }

  void Surface::lock(){
    if(SDL_LockSurface(_sdl_surface))
      throw Exception{};
  }

  void Surface::unlock() noexcept{
    SDL_UnlockSurface(_sdl_surface);
  }

  bool Surface::must_lock() const noexcept{
    return SDL_MUSTLOCK(_sdl_surface);
  }


  Surface loadBMP(std::string const& file){
    SDL_Surface* s{ SDL_LoadBMP(file.c_str()) };
    if(s == nullptr)
      throw Exception{};

    return Surface{ s };
  }
}
