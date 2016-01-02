#ifndef _RAYTRACER_H_
#define _RAYTRACER_H_

#include "ImplicitSurface.h"
#include <SDL/SDL.h>

class Raytracer
{
private:
public:
	void drawSurface(ImplicitSurface* s);	
};

#endif