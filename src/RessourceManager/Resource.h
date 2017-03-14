#ifndef Resource_H
#define Resource_H

#include <string>

template<class T>
struct Resource
{
	T data;
	std::string path;
};

#endif
