#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
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
bool Test03();
bool Test04();

int main(int argc, char *argv[])
{
    return Test04();
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

bool Test03() {
	bool res = false;
	Init init;
	Window win("Optimize and strech an image", 800, 600);
	if(init.Error()) {
		cout << "Error: " << init.ErrorMsg() << endl;
		res = true;
	}
	else {
		if(win.Error()) {
			cout << "Error: " << win.ErrorMsg() << endl;
			res = true;
		}
		else {
			Surface surf;
			surf.LoadBMP("media/ola.bmp");
			surf.Optimize(win.GetSurface()->format);
			SDL_Rect dst;
			dst.x = 0; dst.y = 0; dst.w = 800; dst.h = 600;
			surf.BlitScaledFull(win.GetSurface(), &dst);
			if(surf.Error()) {
				cout << "Error: " << surf.ErrorMsg() << endl;
				res = true;
			}
		}
	}
	win.Update();
	if(win.Error()) {
		cout << "Error " << win.ErrorMsg() << endl;
		res = true;
	}
	SDL_Event e;
	bool quit = false;
	while(!quit && !res) {
		while(SDL_PollEvent(&e)) {
			if(e.type == SDL_QUIT) quit = true;
		}
	}
	return res;
}

bool Test04() {
	int res = false;
	Init init;
	init.InitImage(IMG_INIT_PNG);
	Window win("Testing PNG loading", SCR_WIDTH, SCR_HEIGHT);
	Surface surf;
	if(init.Error()) {
		cout << init.ErrorMsg() << endl;
		res = true;
	}
	else if (win.Error()) {
		cout << win.ErrorMsg() << endl;
		res = true;
	}
	else {
		surf.LoadImage("media/loaded.png");
		surf.Optimize(win.GetSurface()->format);
		if(surf.Error()) {
			cout << surf.ErrorMsg();
			res = true;
		}
	}
	SDL_Event e;
	bool quit = false;
	while(!quit && !res) {
		while(SDL_PollEvent(&e)){
			if(e.type == SDL_QUIT) quit = true;
		}
		surf.BlitFull(win.GetSurface());
		win.Update();
	}
	return res;
}
