#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <Init.h>
#include <Soundfx.h>
#include <Music.h>
#include <Font.h>
#include <Renderer.h>
#include <Window.h>
#include <Surface.h>
#include <Texture.h>


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
bool Test05();
bool Test06();
bool Test07();
bool Test08();

int main(int argc, char *argv[])
{
    return Test08();
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

bool Test05() {
	bool res = false;
	Init init;
	init.InitImage(IMG_INIT_PNG);
	Window win("Testing Textures and rendering", 800, 600);
	Renderer ren;
	ren.Create(win);
	ren.SetDrawColor(0x00, 0x00, 0x00);
	Texture txtr;

	if(init.Error()) {
		cout << "Init: " << init.ErrorMsg() << endl;
		res = true;
	}
	else if (win.Error()) {
		cout << "Window: " << win.ErrorMsg() << endl;
		res = true;
	}
	else if (ren.Error()) {
		cout << "Renderer: " << ren.ErrorMsg() << endl;
		res = true;
	}
	else {
		txtr.FromFileColorKey("media/caravela.png", ren);
		txtr.SetAlpha(50);
		if(txtr.Error()) {
			cout << "Texture: " << txtr.ErrorMsg() << endl;
			res = true;
		}
	}
	SDL_Event e;
	bool quit = false;
	while(!quit && !res) {
		while(SDL_PollEvent(&e)){
			if(e.type == SDL_QUIT) quit = true;
		}
		ren.Clear();
		ren.CopyEx(txtr.GetTexture(),NULL, NULL, 90.0);
		if(ren.Error()) {
			std::cout << "Copy: " << ren.ErrorMsg() << endl;
			res = true;
		}
		else {
			ren.Present();
		}
	}
	return res;
}

bool Test06() {
	bool res = false;
	Init init;
	Window win("Drawing", SCR_WIDTH, SCR_HEIGHT);
	Renderer ren;
	ren.Create(win);

	SDL_Event e;
	bool quit = false;
	while(!quit && !res) {
		while(SDL_PollEvent(&e)){
			if(e.type == SDL_QUIT) quit = true;
		}
		SDL_Rect vpsize;
		vpsize.x = 0; vpsize.y=0; vpsize.w=100; vpsize.h=100;
		SDL_Rect vp;
		vp.x = SCR_WIDTH - 110;
		vp.y = SCR_HEIGHT - 110;
		vp.w = 100;
		vp.h = 100;
		ren.SetDrawColor(0xFF, 0xFF, 0xFF);
		ren.Clear();
		ren.SetDrawColor(0x00, 0x00, 0x00);
		ren.DrawPoint(SCR_WIDTH / 2, SCR_HEIGHT / 2);
		ren.DrawLine(0, 40, SCR_WIDTH, 40);
		SDL_Rect rect;
		rect.x = 50;
		rect.y = 50;
		rect.w = 20;
		rect.h = 20;
		ren.DrawRect(rect);
		SDL_Rect rect2;
		rect2.x = 20;
		rect2.y = 20;
		rect2.w = 20;
		rect2.h = 20;
		ren.SetViewport(vp);
		ren.SetDrawColor(0x00, 0x00, 0x00);
		ren.FillRect(vpsize);
		ren.SetDrawColor(0xFF, 0xFF, 0xFF);
		ren.FillRect(rect2);
		ren.ResetViewport();
		ren.Present();
	}
	return res;

}

bool Test07() {
	bool res = false;
	Init init;
	init.InitFont();
	Window win("Testing Fonts", SCR_WIDTH, SCR_HEIGHT);
	Renderer ren;
	ren.Create(win);
	Font font;
	font.Create("media/CupiddeLocke.ttf", 48);
	SDL_Color color = { 255, 255, 0 };
	Texture txtr;
	int number = 0;
	string str;
	SDL_Event e;
	bool quit = false;
	while(!quit && !res) {
		while(SDL_PollEvent(&e)){
			if(e.type == SDL_QUIT) quit = true;
			else {
				if(e.type == SDL_KEYDOWN) {
					switch(e.key.keysym.sym) {
						case SDLK_UP:
							number++;
							break;
						case SDLK_DOWN:
							number--;
							break;
						default:
							break;
					}
				}
			}
		}
		str = to_string(number);
		txtr.FromSolidFont(font, str.c_str(), color, ren);
		ren.Clear();
		SDL_Rect rect;
		rect.x = SCR_WIDTH / 2 - txtr.GetWidth() / 2;
		rect.y = SCR_HEIGHT / 2 - txtr.GetHeight() / 2;
		rect.w = txtr.GetWidth();
		rect.h = txtr.GetHeight();
		ren.CopyEx(txtr.GetTexture(),NULL, &rect, 0.0);
		if(ren.Error()) {
			std::cout << "Copy: " << ren.ErrorMsg() << endl;
			res = true;
		}
		else {
			ren.Present();
		}
	}
	return res;

}

bool Test08() {
	bool res = false;
	Init init;
	init.InitMixer();
	Window win("Testing Sounds", SCR_WIDTH, SCR_HEIGHT);
	Soundfx hi, med, low;
	Music music;
	hi.LoadWAV("media/high.wav");
	med.LoadWAV("media/medium.wav");
	low.LoadWAV("media/low.wav");
	music.LoadMusic("media/beat.wav");
	SDL_Event e;
	bool quit = false;
	while(!quit && !res) {
		while(SDL_PollEvent(&e)) {
			if(e.type == SDL_QUIT) quit = true;
			else {
				if(e.type == SDL_KEYDOWN) {
					switch(e.key.keysym.sym) {
						case SDLK_a:
							hi.Play();
							break;
						case SDLK_s:
							med.Play();
							break;
						case SDLK_d:
							low.Play();
							break;
						case SDLK_p:
							music.Play();
							break;
						case SDLK_o:
							music.Pause();
							break;
						case SDLK_i:
							music.Resume();
							break;
						case SDLK_u:
							music.Stop();
							break;
						default:
							break;
					}
				}
			}
		}
	}
	return res;
}
