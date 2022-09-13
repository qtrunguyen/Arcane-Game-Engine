#pragma once

#define USE_STL_VECTOR 1
#define USE_STL_QUEUE 1

#if USE_STL_VECTOR
#include <vector>
namespace arcane::utl {
	template<typename T>
	using vector = std::vector<T>;
}
#endif

#if USE_STL_QUEUE
#include <deque>
namespace arcane::utl {
	template<typename T>
	using deque = std::deque<T>;
}
#endif

namespace arcane::utl {
	//TODO: implement our own container

}