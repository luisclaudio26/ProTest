#include "../inc/Raytracer.h"
#include <iostream>
using std::cout;

//-------------------------------------------------------------------------
//--------------------- INTERNAL TO RAYTRACER.CPP -------------------------
//-------------------------------------------------------------------------
static void waitForKey()
{
 	//wait for quit event
    SDL_Event event; 
    bool quit = false; 
 
    while (!quit) 
        if (SDL_PollEvent(&event))  
            switch (event.type) 
            { 
                /* close button clicked */ 
                case SDL_QUIT: 
                    quit = true; 
                    break; 

                /* handle the keyboard */ 
                case SDL_KEYDOWN: 
                    switch (event.key.keysym.sym) 
                    { 
                        case SDLK_ESCAPE:
                            quit = true; 
                            break;
                    } 
                    break; 
            }
  	return;
}

//----------------------------------------------------------------
//--------------------- FROM RAYTRACER.H -------------------------
//----------------------------------------------------------------
Raytracer* Raytracer::raytracer_ptr = 0;

Raytracer::Raytracer()
{
	// initialize SDL 
    SDL_Init(SDL_INIT_VIDEO); 

    // set the title bar 
    SDL_WM_SetCaption("SDL Test", "SDL Test"); 
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

void Raytracer::drawSurface(ImplicitSurface* s, int nX, int nY)
{
    // create window 
    this->surface = SDL_SetVideoMode(nX, nY, 32,
                                       SDL_HWSURFACE|SDL_DOUBLEBUF);

	vec_3d pos = (vec_3d){0.0, 0.0, -4.0};
	vec_3d point_to = (vec_3d){0.0, 0.0, 0.0};
	vec_3d cam_up = (vec_3d){0.0, 1.0, 0.0};
	vec_3d cam_dir = pos - point_to;

	vec_3d cam_frame[3];
	cam_frame[2] = cam_dir.unit();
	cam_frame[0] = cam_up.cross( cam_frame[2] ).unit();
	cam_frame[1] = cam_frame[2].cross( cam_frame[0] );

	this->drawSurface(s, pos, cam_frame, 1.0, 2.0, 2.0, nX, nY);
}

void Raytracer::drawSurface(ImplicitSurface *s, 
	vec_3d cam_pos, 
	vec_3d cam_frame[3], 
	double focal_d, 
	int w, int h,
	int nX, int nY)
{

	//clean screen
	SDL_FillRect(this->surface, 0, SDL_MapRGB(this->surface->format, 0, 0, 0));

	cout<<"Casting rays...\n";

	//Loop through pixels, draw
	for(int i = 0; i < nX; i++)
		for(int j = 0; j < nY; j++)
		{
			vec_3d pixel_pos_cam_frame;
			vec_3d origin, direction;

			//pixel position, in camera frame
			pixel_pos_cam_frame.x = w*(i+0.5)/nX - w/2;
			pixel_pos_cam_frame.y = h*(j+0.5)/nY - h/2;
			pixel_pos_cam_frame.z = -focal_d;

			origin = cam_pos;
			direction = (vec_3d){0.0, 0.0, 0.0};
			direction = direction + cam_frame[2] * pixel_pos_cam_frame.z;
			direction = direction + cam_frame[1] * pixel_pos_cam_frame.y;
			direction = direction + cam_frame[0] * pixel_pos_cam_frame.x;

			direction = direction.unit();

			//cast ray
			Uint32 p = throw_ray(origin, direction, s);

			this->plotXY(i, j, p);
		}

	cout<<"done!\n";

	//show screen
	SDL_Flip(this->surface);
    
    waitForKey();
 
	return;
}

Uint32 Raytracer::throw_ray(vec_3d origin, vec_3d direction, ImplicitSurface* s)
{
	double cutoff = 15.0, step = 0.1;

	//First approach: numerical/iterative
	//Go along the ray and check whether we intersected the surface
	vec_3d probe = origin;

	for(int t = 0; t < (int)(cutoff/step); t++)
	{
		if( s->in(probe) <= 0 )
			return 0x00FF0000;
		probe += direction*step;
	}

	return 0x00000F00;
}