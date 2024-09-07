#pragma once
#include <iostream>
#ifdef MATHPOWERLIBRARYDYNAMIC_EXPORTS
#define MATHPOWERLIBRARY_API __declspec(dllexport)
#else
#define MATHPOWERLIBRARY_API __declspec(dllimport)
#endif
namespace DynamicMathPower
{
	class Leaver
	{
	public:
		MATHPOWERLIBRARY_API void leave(std::string s);
	};
}