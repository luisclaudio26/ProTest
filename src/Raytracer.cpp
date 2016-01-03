#include "../inc/Raytracer.h"

Raytracer* Raytracer::raytracer_ptr = 0;

Raytracer::Raytracer()
{
	// initialize SDL 
    SDL_Init(SDL_INIT_VIDEO); 

    // set the title bar 
    SDL_WM_SetCaption("SDL Test", "SDL Test"); 

    // create window 
    this->surface = SDL_SetVideoMode(800, 600, 32,
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
	this->drawSurface(s, o, o, o, 1.0, w, h, 800, 600);
}

void Raytracer::drawSurface(ImplicitSurface *s, 
	vec_3d cam_pos, 
	vec_3d cam_direction, 
	vec_3d cam_up, 
	double focal_d, 
	int w, int h,
	int nX, int nY)
{

	//clean screen
	SDL_FillRect(this->surface, 0, SDL_MapRGB(this->surface->format, 0, 0, 0));

	//Loop through pixels, draw
	for(int i = 0; i < nX; i++)
		for(int j = 0; j < nY; j++)
		{
			this->plotXY(i, j, 0x0000FF00);
		}

	//show screen
    SDL_Flip(this->surface);

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