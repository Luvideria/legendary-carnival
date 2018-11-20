#include <iostream>
#include <vector>
int main(int argc,char** argv)
{
	std::vector<float> R, G, B;
	size_t w, h;
	//readPPM("C:\\Users\\kilhe\\Documents\\PhD\\Projects\\legendary-carnival\\stuff\\pointillism\\data\\starry.ppm", R, G, B, w, h);

	//each line is a cdf
	std::vector<std::vector<float>> cdfsR;
	std::vector<std::vector<float>> cdfsG;
	std::vector<std::vector<float>> cdfsB;

	for (size_t i = 0;  i < h; i++)
	{
		//cdfsR.push_back(cumsum(R.))
		return 0;
	}

	return 0;
}
