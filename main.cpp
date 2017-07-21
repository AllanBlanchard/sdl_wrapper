#include <iostream>

#include "context.hh"
#include "window.hh"
#include "renderer.hh"
#include "surface.hh"
#include "texture.hh"
#include "event.hh"

unsigned const width{ 1024 };
unsigned const height{ 768 };

int main(){
  using SDL::Context;
  using SDL::Window;

  Context sdl_context(Context::VIDEO);
  sdl_context.request(Context::AUDIO);
  if(sdl_context.initiated(Context::AUDIO))
    std::cout<<"SDL Audio Context correctly initiated"<<std::endl;

  Window window{ "A window", width, height, Window::RESIZABLE | Window::MAXIMIZED };
  SDL::Renderer renderer{ window, SDL::Renderer::ACCELERATED, -1 };
  SDL::Surface surf1{ SDL::loadBMP("truc.bmp") };
  SDL::Surface surf2{ surf1 };

  SDL::Texture tex1{ renderer, std::move(surf1) };
  SDL::Texture tex2{ renderer, std::move(surf2) };

  while(true){
    SDL::Event e{};
    if(e.poll())
      if(e.type() == SDL_QUIT)
	break;
    
    renderer.clear();
    renderer.copy(tex2);
    renderer.update();
  }
  
  sdl_context.revoke(Context::AUDIO);

  return 0;
}
