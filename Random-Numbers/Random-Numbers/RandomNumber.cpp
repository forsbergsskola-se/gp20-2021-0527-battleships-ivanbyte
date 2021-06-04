#include "RandomNumber.h"
#include <iostream>
#include <ctime>

using namespace std;

int* GetRandomNumbers()
{
    int numbers[1000];

    srand((unsigned)time(NULL)); //Set Seed

    for (int i = 0; i < 1000; i++)
    {
        int number = (rand() % 20) + 1;
        numbers[i] = number;
    }

    return numbers;
}

int* CountNumberCount(int* numberArray)
{

}

int main()
{
    int* numbers = CountNumberCount(GetRandomNumbers());

    for (int i = 0; i < 20; i++)
    {
        cout << numbers << endl;
    }
}
