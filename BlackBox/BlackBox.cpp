#include "pch.h"
#include "BlackBox.h"

#include <cmath>
#include <iostream>
using namespace std;

float VectorMagnitude(float x, float y, float z)
{
	float value = sqrt((x * x) + (y * y) + (z * z));
	value = std::round(value * 1000) / 1000.0;
	return value;
}

int BiggestNum(int count, ...)
{
	va_list ap;
	va_start(ap, count);
	int biggest = INT_MIN;
	int current = 0;

	for (int i = 0; i < count; ++i)
	{
		current = va_arg(ap, int);
		if (biggest < current)
			biggest = current;
	}

	return biggest;
}

int FlipNumber(int number)
{
	int result = 0;
	int digit = 0;

	int a, b, c;
	int cal = number;
	while (cal > 0)
	{
		a = pow(10, digit + 1);
		b = number % a;
		c = (b / pow(10, digit)) * pow(10, digit);
		cal -= c;
		++digit;
	}

	for (int i = digit; i > 0; --i)
	{
		a = pow(10, (i));
		b = number % a;
		c = b / pow(10, i - 1);
		result += c * pow(10, digit - i);
	}
	return result;
}

int CountSpace(const char* word)
{
	int count = 0;
	int space = 0;

	while (word[count] != '\0')
	{
		if (word[count] == 0x20)
			++space;
		++count;
	}

	return space;
}

bool StringCompare(const char* a, const char* b)
{
	int countA = 0;
	for (countA = 0; '\0' != a[countA]; ++countA) {}
	int countB = 0;
	for (countB = 0; '\0' != a[countB]; ++countB) {}

	int length = countA <= countB ? countA : countB;
	for (int i = 0; i < length; ++i)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}