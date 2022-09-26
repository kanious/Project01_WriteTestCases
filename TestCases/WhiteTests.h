#pragma once

int Square(int a)
{
	return a * a;
}

int RoundHalfUp(int digit, int number)
{
	int a, b, c;
	int cal = number;

	for (int i = 0; i < digit; ++i)
	{
		a = pow(10, i + 1);
		b = (number % a) / pow(10, i);
		c = b * pow(10, i);

		if (i == digit - 1 && b >= 5)
			c -= pow(10, i + 1);

		cal -= c;
	}

	return cal;
}

int RectangleArea(int x, int y)
{
	return x * y;
}

double HourToSec(int hour)
{
	return hour * 60 * 60;
}

int CountAliquot(int num)
{
	int count = 0;
	int max = sqrt(num);
	for (int i = 1; i <= max; ++i)
	{
		if (num % i == 0)
		{
			++count;
			if (num / i != i)//not square 4/2=2, 9/3=3
				++count;
		}
	}

	return count;
}