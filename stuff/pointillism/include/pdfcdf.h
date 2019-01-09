#pragma once
#ifndef PDFCDF_H
#define PDFCDF_H
#include <vector>
#include "doctest.h"

//! \brief computes the cumulative sum of the array
std::vector<float>& cumsum(const std::vector<float> &v, const std::size_t size = -1);

//! \brief computes the cumulative sum of the array normalized between 0 and 1
std::vector<float>& cumsumNorm(const std::vector<float> &v, const std::size_t size = -1);

//! \brief computes the corresponding sample to the random number given 
size_t interpInverse(const std::vector<float> &cumsum, const float r);

TEST_SUITE("pdfcdf") {
	TEST_CASE("Cumulative sum")
	{
		const std::vector<float> v = { 7,5,4,6,2,1 };

		SUBCASE("simple cumsum")
		{
			const std::vector<float> &r = cumsum(v);

			CHECK(r.size() == 6);
			CHECK(r[0] == 7);
			CHECK(r[1] == 12);
			CHECK(r[2] == 16);
			CHECK(r[3] == 22);
			CHECK(r[4] == 24);
			CHECK(r[5] == 25);
		}
		SUBCASE("cumsum norm")
		{
			const std::vector<float> &r = cumsumNorm(v);

			CHECK(r.size() == 6);
			CHECK(r[0] == 7.f / 25.f);
			CHECK(r[1] == 12 / 25.f);
			CHECK(r[2] == 16.f / 25.f);
			CHECK(r[3] == 22.f / 25.f);
			CHECK(r[4] == 24.f / 25.f);
			CHECK(r[5] == 1.f);
		}
	}

	TEST_CASE("interpolation inverse cumsum")
	{
		const std::vector<float> &r = { 0.28f,0.48f,0.64f,0.88f,0.96f,1.f };
		CHECK(interpInverse(r, 0.78f) == 3);
	}
}
#endif