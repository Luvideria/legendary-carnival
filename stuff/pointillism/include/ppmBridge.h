#pragma once
#ifndef PPM_BRIDGE_H
#define PPM_BRIDGE_H
#include <iostream>
#include <vector>
#include "ppmReader.h"
#include "doctest.h"

bool readPPM(const std::string &fileName,
	std::vector<float> &R,
	std::vector<float> &G,
	std::vector<float> &B, std::size_t &w, std::size_t &h);

bool writePPM(const std::string &fileName,
	const std::vector<float> &R,
	const std::vector<float> &G,
	const std::vector<float> &B, const std::size_t &w, const std::size_t &h);
/*
TEST_SUITE("image"){
TEST_CASE("ReadWrite mirror")
{
	std::string fileName = "C:\\Users\\kilhe\\Documents\\PhD\\Projects\\legendary-carnival\\stuff\\pointillism\\data\\starry.ppm";
	using namespace pnm::literals;
	pnm::image<pnm::rgb_pixel> ppm = pnm::read(fileName);

	pnm::write("starry_self.ppm", ppm,pnm::format::ascii);
}
*/
/*
TEST_CASE("Bridge open") {
	//TODO: use a small sample image
	std::string fileName = "C:\\Users\\kilhe\\Documents\\PhD\\Projects\\legendary-carnival\\stuff\\pointillism\\data\\starry.ppm";
	using namespace pnm::literals;
	pnm::image<pnm::rgb_pixel> ppm = pnm::read(fileName);

	std::cout << "width  = " << ppm.width() << std::endl;
	std::cout << "height = " << ppm.height() << std::endl;
	CHECK(ppm.width() == 2560);
	CHECK(ppm.height() == 1600);

	std::vector<float> R, G, B;
	std::size_t w, h;
	REQUIRE(readPPM(fileName, R, G, B,w,h) == true);

	REQUIRE(R.size() > 100);
	REQUIRE(G.size() > 100);
	REQUIRE(B.size() > 100);
	REQUIRE(ppm.width() > 10);
	REQUIRE(ppm.height() > 10);

#pragma omp parallel
	for (std::size_t y = 0; y < 10; ++y)
	{
		for (std::size_t x = 0; x < 10; ++x)
		{
			int id = ppm.width()*y + x;
			pnm::rgb_pixel &rgb = ppm[y][x];
			CHECK(rgb.red == std::floor(R.at(id)));
			CHECK(rgb.green == std::floor(G.at(id)));
			CHECK(rgb.blue == std::floor(B.at(id)));
		}
	}
}

TEST_CASE("Bridge write") {
	//TODO: use a small sample image
	std::vector<float> R, G, B;

	
	SUBCASE("simple PPM") {
		std::cout << "simple PPM test"<<std::endl;
		size_t size = 100;
		std::string fileName = "grey.ppm";

		for (unsigned int x = 0; x < size; x++)
			for (unsigned int y = 0; y < size; y++)
			{
				R.push_back(static_cast<float>(y*size + x));
				G.push_back(static_cast<float>(y*size + x));
				B.push_back(static_cast<float>(y*size + x));
			}
		CHECK(true == writePPM(fileName, R, G, B, size, size));
	}
	SUBCASE("READ WRITE")
	{
		std::cout << "Read write test" << std::endl;
		using namespace pnm::literals;
		std::size_t w, h;
		CHECK(true == readPPM("C:\\Users\\kilhe\\Documents\\PhD\\Projects\\legendary-carnival\\stuff\\pointillism\\data\\starry.ppm", R, G, B, w, h));
		CHECK(true == writePPM("starry.ppm", R, G, B, w, h));
	}
}
}
*/
#endif //PPM_BRIDGE_H