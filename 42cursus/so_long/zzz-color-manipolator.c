#include "so_long.h"

int add_shade(int trgb, double intensity)
{
	unsigned int t;
	unsigned int r;
	unsigned int g;
	unsigned int b;

	if (intensity > 1)
		intensity = 1;
	if (intensity < 0)
		intensity = 0;
	t = get_t(trgb);
	r = get_r(trgb) * intensity;
	g = get_g(trgb) * intensity;
	b = get_b(trgb) * intensity;
	return (create_trgb(t, r, g, b));
}

int get_complementary(int trgb)
{
	unsigned int t;
	unsigned int r;
	unsigned int g;
	unsigned int b;

	t = get_t(trgb);
	r = 255 - get_r(trgb);
	g = 255 - get_g(trgb);
	b = 255 - get_b(trgb);
	return (create_trgb(t, r, g, b));
}