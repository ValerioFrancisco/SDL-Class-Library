#include <iostream>
#include <SDL.h>
#include <Init.h>
#include <Window.h>
#include <Surface.h>

using namespace std;
using namespace lp;

// constants
const int SCR_WIDTH = 640,
	  	  SCR_HEIGHT = 480;

// Test Functions
bool Test01();
bool Test02();

int main(int argc, char *argv[])
{
    return Test02();
}


bool Test01() {
    bool res = false;
	Init init;
	Window win("Test number 1...", SCR_WIDTH, SCR_HEIGHT);
	if(init.Error() || win.Error()) res = true;
	SDL_Event e; bool quit = false; while( quit == false && res == 0 ){
		while( SDL_PollEvent( &e ) ){
			if( e.type == SDL_QUIT ) quit = true;
		}
	}
	return res;
}

bool Test02() {
	bool res = false;
	Init init;
	Window win("Loading Bitmap test", SCR_WIDTH, SCR_HEIGHT);
	Surface surf;
	surf.LoadBMP("media/ola.bmp");
	if(init.Error() || win.Error() || surf.Error()) {
		res = true;
		cout << "Error: " << SDL_GetError() << endl;
	} else {
		SDL_Surface *test = win.GetSurface();
		surf.BlitFull(test);
		if(surf.Error()) {
			cout << "Error Blitting: " << SDL_GetError() << endl;
			res = true;
		} else win.Update();
	}
	SDL_Event e; bool quit = false; while( quit == false && res == 0 ){
		while( SDL_PollEvent( &e ) ){
			if( e.type == SDL_QUIT ) quit = true;
		}
	}
	return res;
}
