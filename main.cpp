#include <iostream>
#include <vector>
#include <algorithm>

int HCF(int &a, int &b)
{
	int di, dv;

	dv = (a > b) ? a : b;
	di = (a > b) ? b : a;

	int r = 1;
	while (r > 0)
	{
		r = dv % di;

		if (r != 0)
		{
			dv = di;
			di = r;
		}
		else
		{
			break;
		}

	}
	return di;
}

int recursive(std::vector<int> vec)
{
	int* hcfs = new int[vec.size() - 1];
	std::sort(vec.begin(), vec.end());
	if (vec.size() - 1 == 1) { hcfs[0] = HCF(vec.at(0), vec.at(1));}
	else 
	{
		hcfs[0] = HCF(vec.at(0), vec.at(1));
		for (int h = 1; h < vec.size() - 1; h++)
		{
			hcfs[h] = HCF(hcfs[h - 1], vec.at(h));
		}
	}
	return hcfs[vec.size() - 2];
}

int main(int argc, char** argv)
{
	if (argc == 0)
	{
		std::cout << "you have to give me numbers BRUH" << std::endl;
	}
	else 
	{	int size = argc - 1;
		std::vector<int> nums(size);

		for (int i = 0; i < nums.size(); i++)
		{
			nums.at(i) = atoi(argv[i + 1]);
		}
		std::cout << recursive(nums) << std::endl;
	}
	std::cin.get();
}