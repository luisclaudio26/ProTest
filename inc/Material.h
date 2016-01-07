#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#define TRUNCATE(v) if(v > 1.0) v = 1.0;

struct Color {
	double r, g, b;

	struct Color operator+(struct Color lhs) {
		struct Color out;
		out.r = r + lhs.r; TRUNCATE(out.r);
		out.g = g + lhs.g; TRUNCATE(out.g);
		out.b = b + lhs.b; TRUNCATE(out.b);
		return out;
	}

	struct Color operator*(double lhs) {
		
		struct Color out;
		out.r = r * lhs; TRUNCATE(out.r);
		out.g = g * lhs; TRUNCATE(out.g);
		out.b = b * lhs; TRUNCATE(out.b);
		return out;
	}
};

typedef struct
{
	Color spec_color;
	double spec_factor, spec_power;

	Color diff_color;
	double diff_factor;

	Color amb_color;
	double amb_factor;
} Material;

#endif