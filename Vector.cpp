//Generate a Vector with numOfNums numbers in the range from min to max
#include <vector>
#include <ctime>

std::vector<int> GenerateRandVec(int numOfNums,	int min, int max) {
	std::vector<int> vecValues;
	srand(time(NULL));
	int i = 0, randVal = 0;
	while (i < numOfNums) {
		randVal = min + std::rand() % ((max + 1) - min);
		vecValues.push_back(randVal);
		i++;
	}
	return vecValues;
}
