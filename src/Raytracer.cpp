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

void Raytracer::drawSurface(ImplicitSurface* s, int w, int h)
{
	return;
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
			double u, v;
			//pixel_position_cam_frame( );

			//Uint32 p = throw_ray();


		}

	return;
}