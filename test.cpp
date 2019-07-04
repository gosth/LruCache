#include <memory>
#include "lrucache.hpp"
#include <iostream>
int main() {
	std::shared_ptr<cache::lru_cache<int, char> > cache(new cache::lru_cache<int, char>(5));
	cache->put(1, 'a');
	cache->put(2, 'b');
	cache->put(3, 'c');
	cache->put(4, 'd');
	std::cout << "when put four times, the lru size=" << cache->size() << std::endl;
	cache->put(5, 'e');
	std::cout << "before put 6, whether 1 is exists:" << cache->exists(1) << std::endl;	
	cache->put(6, 'f');
	std::cout << "after put 6, whether 1 is exists:" << cache->exists(1) << std::endl;	
	std::cout << "whether 2 is exists:" << cache->exists(2) << std::endl;	
	std::cout << "whether 3 is exists:" << cache->exists(3) << std::endl;	
	std::cout << "whether 4 is exists:" << cache->exists(4) << std::endl;	
	std::cout << "whether 5 is exists:" << cache->exists(5) << std::endl;	
	std::cout << "whether 6 is exists:" << cache->exists(6) << std::endl;	
	const char result = cache->get(5);
	std::cout << "get the val when the key=5, the val=" << result << std::endl;
	return 0;
}
