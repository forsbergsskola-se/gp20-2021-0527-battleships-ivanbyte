#include <iostream>

using namespace std;

void FibonacciSeries(int number);
int FibonacciRecursion(int number);
void FibonacciIteration(int number);

int main()
{
	cout << "The Fibonacci Series\n" << endl;
	cout << "Enter the amount of numbers in the Fibonacci series you want to view: ";
	int input;
	cin >> input;
	FibonacciSeries(input);
}

void FibonacciSeries(int number)
{
	cout << "\nFibonacci Series computed with recursion: ";
	int i{};
	while(i < number)
	{
		cout << " " << FibonacciRecursion(i);
		i++;
	}

	cout << "\nFibonacci Series computed with Iteration: ";
	FibonacciIteration(number);
}

int FibonacciRecursion(int number)
{
	if (number == 1 || number == 0)
	{
		return number;
	}
	else
	{
		return(FibonacciRecursion(number - 1) + FibonacciRecursion(number - 2));
	}
}

void FibonacciIteration(int number)
{
	int x = 0, y = 1, z = 0;

	for (int i = 0; i < number; i++)
	{
		cout << x << " ";
		z = x + y;
		x = y;
		y = z;
	}
}
