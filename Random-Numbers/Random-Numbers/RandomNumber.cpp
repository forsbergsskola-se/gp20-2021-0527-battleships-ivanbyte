#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL)); // Set Seed

	int numbers[20]{};

	for (int i = 0; i < 10000; i++)
	{
		numbers[(rand() % 20)]++;
	}

	for (int i = 0; i < 20; i++)
	{
		float percent =  numbers[i] * 100 / 10000;
		cout << "Number " << i + 1 << ": " << numbers[i] << "(" << percent << "%" << ")" << endl;
	}

	return 0;
}