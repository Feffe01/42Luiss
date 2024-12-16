int create_trgb(unsigned int t, unsigned int r, unsigned int g, unsigned int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

unsigned int get_t(int trgb)
{
	return (trgb >> 24 & 0xff);
}

unsigned int get_r(int trgb)
{
	return (trgb >> 16 & 0xff);
}

unsigned int get_g(int trgb)
{
	return (trgb >> 8 & 0xff);
}

unsigned int get_b(int trgb)
{
	return (trgb >> 0 & 0xff);
}
