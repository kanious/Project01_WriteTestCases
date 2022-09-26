#pragma once

#ifdef BLACKBOX_EXPORTS
#define BLACKBOX_API __declspec(dllexport)
#else
#define BLACKBOX_API __declspec(dllimport)
#endif

extern "C"
{
	BLACKBOX_API float VectorMagnitude(float x, float y, float z);
	BLACKBOX_API int BiggestNum(int count, ...);
	BLACKBOX_API int FlipNumber(int number);
	BLACKBOX_API int CountSpace(const char* word);
	BLACKBOX_API bool StringCompare(const char* a, const char* b);
}