#include <iostream>
#include "vector.hpp"
#include "sort.hpp"
#include "pair.hpp"
#include <fstream>
#include <cstdlib>
#include <string>

int main(){

	NVector::TVector<NMytypes::TPair<int, char[65]>> elems;
	NMytypes::TPair<int, char[65]> elem;
	int key;
	char value[65];	


	//tmp
	int counter = 0;
	while (std::cin >> key >> value) {
		elem.set_pair(key,value);
		elems.push_back(elem);
		counter++;
	}
	
	//std::cout << std::endl;

	NSort::counting_sort(elems);

	for (size_t i = 0; i < elems.size(); ++i) {
		elems[i].print_pair();
	}

	std::cin >> value;
	return 0;
}