#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>


std::vector<float>& cumsum(const std::vector<float> &v, const size_t size)
{
	size_t s = size;
	if (size == -1)
		s = v.size();

	std::vector<float> *r = new std::vector<float>;
	r->resize(s);
	//std::inclusive_scan(v.begin(), v.begin()+s, r->begin());
	return *r;
}

std::vector<float>& cumsumNorm(const std::vector<float> &v, const size_t size)
{
	std::vector<float> &r = cumsum(v,size);
	float e = r.back();
	std::transform(r.begin(), r.end(), r.begin(), [e](float f) -> float { return f / e; });
	return r;
}


size_t interpInverse(const std::vector<float> &cumsum, const float r)
{//this works only for our case !
	if (r < cumsum[0])
		return 0;
	if (r >= 1)
		return cumsum.size()-1;

	float min = 99999.f;// minimum values (f-a)
	size_t id = 0;  // index of minimum value
	int i = 0;//counter

	std::for_each(cumsum.begin(), cumsum.end(), [&min, r, &id,&i](float f) -> void { 
		//std::cout << std::fabs(f - r) << " id " << id <<std::endl;
		if (std::fabs(f - r) < min)
		{
			min = std::fabs(f - r); id = i;
		}i++;
	});
	
	return id;
}