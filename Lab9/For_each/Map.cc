#include "Map.h"
#include <iostream>


template<typename K, typename V>
void Map<K,V>::Print() {
	for (int i = 0; i < count; ++i) {
		std::cout << v[i].key << ": " << v[i].value << std::endl;
	}
}


