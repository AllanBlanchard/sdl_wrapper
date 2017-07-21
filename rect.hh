#include <SDL2/SDL_rect.h>

template<class T, bool control(T)>
class ControlledRef{
public:
  constexpr ControlledRef(T& t) : m_t{ t }{
    assert(control(t));
  };

  constexpr operator T() const{ return m_t; };

  constexpr ControlledRef& operator=(T& value){
    assert(control(value));
    m_t = value;
    return *this;
  }
private:
  T m_t;
};

bool positive(int i){ return i >= 0; }

namespace sdl{
  class Rect final{
    using PositiveIntRef = ControlledRef<int, positive>;
    SDL_Rect m;
    
  public:
    Rect(int w, int h) : m{ 0, 0, w, h } {}
    PositiveIntRef x(){ return {m.x}; }
    int const& x() const{ return m.x; }
    
    operator SDL_Rect() const noexcept{
      return m;
    }
  };
}
