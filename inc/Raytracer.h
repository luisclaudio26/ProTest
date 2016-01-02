#ifndef _RAYTRACER_H_
#define _RAYTRACER_H_

#include "ImplicitSurface.h"
#include <SDL/SDL.h>

class Raytracer
{
private:

	static Raytracer* raytracer_ptr;
	SDL_Surface* surface;

	//-----------------------------------------
	//---------- Internal functions -----------
	//-----------------------------------------
	void plotXY(int i, int j, Uint32 color);

	void drawSurface(ImplicitSurface *s, 
						vec_3d cam_pos, 
						vec_3d cam_direction, 
						vec_3d cam_up, 
						double focal_d, 
						int w, int h,
						int nX, int nY);

	//-------------------------
	//--------- CTOR ----------
	//-------------------------
	Raytracer();

public:
	//-------------------------
	//--------- DTOR ----------
	//-------------------------
	~Raytracer();

	static Raytracer* instance() {
		if(!Raytracer::raytracer_ptr)
			raytracer_ptr = new Raytracer();
		return Raytracer::raytracer_ptr;
	}


	void drawSurface(ImplicitSurface* s, int w, int h);	
};

#endif