#include <cstdlib>
#include <iostream>
#include "ppmReader.h"

bool readPPM(const std::string &fileName,
	std::vector<float> &R,
	std::vector<float> &G,
	std::vector<float> &B, std::size_t &w, std::size_t &h)
{
	R.clear();
	G.clear();
	B.clear();

	using namespace pnm::literals;
	pnm::image<pnm::rgb_pixel> ppm = pnm::read(fileName);
	if (ppm.height() == 0 || ppm.width() == 0)
	{
		std::cerr << "Error opening file " << fileName << std::endl;
		return false;
	}
	R.resize(ppm.width()*ppm.height());
	G.resize(ppm.width()*ppm.height());
	B.resize(ppm.width()*ppm.height());

#pragma omp parallel
	for (std::size_t y = 0; y < ppm.y_size(); ++y)
	{
		for (std::size_t x = 0; x < ppm.x_size(); ++x)
		{
			int i = ppm.width()*y + x;
			pnm::rgb_pixel &rgb = ppm[y][x];
			R[i] = (rgb.red);
			G[i] = (rgb.green);
			B[i] = (rgb.blue);
		}
	}
	w = ppm.width();
	h = ppm.height();
	return true;
}

bool writePPM(const std::string &fileName,
	const std::vector<float> &R,
	const std::vector<float> &G,
	const std::vector<float> &B, const std::size_t &w, const std::size_t &h)
{

	using namespace pnm::literals;
	pnm::image<pnm::rgb_pixel> ppm(w, h);
	
#pragma omp parallel
	for (std::size_t y = 0; y < h; ++y)
	{
		for (std::size_t x = 0; x < w; ++x)
		{
			int i = ppm.width()*y + x;
			pnm::rgb_pixel &rgb = ppm[y][x];
			rgb.red		= static_cast<uint8_t>(R[i]);
			rgb.green	= static_cast<uint8_t>(G[i]);
			rgb.blue	= static_cast<uint8_t>(B[i]);
		}
	}
	pnm::write(fileName, ppm,pnm::format::ascii);
	return true;
}