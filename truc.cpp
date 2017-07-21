#include "rect.hh"

void foo(SDL_Rect&){}

int main(){
  sdl::Rect r{ 34, 52 };
  foo(r);
}
