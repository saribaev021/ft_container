//
// Created by Kanat Saribaew on 2/6/21.
//

#include <list>
#include "../List/list.hpp"
#include <vector>
#include <map>
#include "../Vector/vector.hpp"
#include <iostream>
typedef  std::vector<int>::reverse_iterator R_it;
typedef  std::vector<int>::iterator intIt;
int main(){
    srand(time(nullptr));
    std::map<int, int>a;
//    std::map<int, int>::value_compare
////    std::list<int>::iterator it = a.begin();
//    std::map<int, int>::iterator::value_type v;
//    v = *a.begin();
//    std::pair<int, int>w;
//    w = *a.begin();
////    a[1000] = 3454;
////    for (int i = 0; i < 10; ++i) {
////        int ret = rand() % 687;
////        a[i] = ret;
////        std::cout << ret << " ";
////    }
////    std::cout << std::endl;
////    std::cout << a.begin()->first << " "<<a.begin()->second<<std::endl;
	std::vector<int>df;
	df.push_back(250);
	df.push_back(213);
	df.push_back(212);
	df.push_back(211);
	df.push_back(210);
	df.push_back(60);
	df.push_back(50);
	std::map<int, std::string>das;
	for (int i = 0; i != 6; ++i){
		das.insert(std::pair<int, std::string>(df[i],"sfds"));
	}
	std::map<int,std::string>::iterator it = das.upper_bound(50);
	std::cout << it->first<<std::endl;
	if (it == das.end())
		std::cout << "true"<<std::endl;
}