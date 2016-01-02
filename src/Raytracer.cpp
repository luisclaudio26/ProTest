#include "../inc/Raytracer.h"

Raytracer* Raytracer::raytracer_ptr = 0;

Raytracer::Raytracer()
{
	// initialize SDL 
    SDL_Init(SDL_INIT_VIDEO); 

    // set the title bar 
    SDL_WM_SetCaption("SDL Test", "SDL Test"); 

    // create window 
    this->surface = SDL_SetVideoMode(600, 800, 32,
                                       SDL_HWSURFACE|SDL_DOUBLEBUF);
}

Raytracer::~Raytracer()
{
	SDL_Quit();
	delete Raytracer::raytracer_ptr;
}

void Raytracer::plotXY(int i, int j, Uint32 color)
{
	Uint32* pixels = (Uint32*)this->surface->pixels;
	pixels[(j*this->surface->w)+i] = color;
}


void Raytracer::drawSurface(ImplicitSurface* s, int w, int h)
{
	vec_3d o = (vec_3d){0.0, 0.0, 0.0};
	this->drawSurface(s, o, o, o, 1.0, w, h, 600, 800);
}

void Raytracer::drawSurface(ImplicitSurface *s, 
	vec_3d cam_pos, 
	vec_3d cam_direction, 
	vec_3d cam_up, 
	double focal_d, 
	int w, int h,
	int nX, int nY)
{

	//Loop through pixels
	for(int i = 0; i < nX; i++)
		for(int j = 0; j < nY; j++)
		{
			this->plotXY(i, j, 0x0000FF00);
		}

	return;
}