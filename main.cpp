#include <iostream>
#include <SDL.h>
#include <Init.h>
#include <Window.h>

using namespace std;
using namespace lp;

// Test Functions
bool Test01();

int main(int argc, char *argv[])
{
    return Test01();
}


bool Test01() {
    bool res = false;
	Init init;
	Window win("Test number 1...", 800, 600);
	if(init.Error() || win.Error()) res = true;
	SDL_Event e; bool quit = false; while( quit == false && res == 0 ){
		while( SDL_PollEvent( &e ) ){
			if( e.type == SDL_QUIT ) quit = true;
		}
	}
	return res;
}
