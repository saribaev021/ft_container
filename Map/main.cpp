//
// Created by Kanat Saribaew on 2/12/21.
//
#include "map.hpp"
#include <map>
#include <fstream>
typedef std::pair<int, int> value_type;
typedef value_type *pointer;
//pointer ss(){
//    std::pair<int, int>p;
//    p.second = 1;
//    p.first = 10;
//    return &p;
//}

int main(){
    srand(time(nullptr));
    ft::map<int, int>a;
    std::map<int, int>b;
    int arr[50];
    for (int i = 0; i != 50; ++i)
        arr[i] = rand() % 100;
    std::ofstream out("/Users/ndreadno/ft_container/Map/test.txt");
    for (int i = 0; i + 1 != 50; ++i){
    	b.insert(std::pair<int, int>(arr[i], arr[i + 1]));
    }
    for (int i = 0; i + 1 != 50; ++i){
        out << "a.insert(std::pair<int, int>("<<arr[i]<< ", "<<arr[i + 1]<< "));"<<std::endl;
    }
    out.close();
    std::map<int, int>::iterator imap = b.begin();

    for (int i = 0; i + 1 != 50; ++i) {
        a.insert(std::pair<int, int>(arr[i], arr[i + 1]));
    }
//	a.insert(std::pair<int, int>(90, 92));
//	a.insert(std::pair<int, int>(902, 92));
//	a.insert(std::pair<int, int>(902, 92));
//	a.insert(std::pair<int, int>(902, 92));
//	a.insert(std::pair<int, int>(9202, 92));
//	a.insert(std::pair<int, int>(9203, 92));
//	a.insert(std::pair<int, int>(9204, 92));

//	a.insert(std::pair<int, int>(90, 92));
//	a.insert(std::pair<int, int>(64, 16));
//	a.insert(std::pair<int, int>(7, 71));
//	a.insert(std::pair<int, int>(29, 84));
//	a.insert(std::pair<int, int>(55, 30));
//	a.insert(std::pair<int, int>(30, 22));
//	a.insert(std::pair<int, int>(22, 63));
//	a.insert(std::pair<int, int>(63, 53));
//	a.insert(std::pair<int, int>(91, 92));
//	a.insert(std::pair<int, int>(92, 12));
//	a.insert(std::pair<int, int>(12, 28));
//	a.insert(std::pair<int, int>(85, 95));
//	a.insert(std::pair<int, int>(95, 14));
//	a.insert(std::pair<int, int>(14, 53));
//	a.insert(std::pair<int, int>(53, 10));
//	a.insert(std::pair<int, int>(10, 72));
//	a.insert(std::pair<int, int>(65, 62));
//	a.insert(std::pair<int, int>(62, 96));
//	a.insert(std::pair<int, int>(40, 76));
//	a.insert(std::pair<int, int>(76, 28));
//	a.insert(std::pair<int, int>(28, 59));
//	a.insert(std::pair<int, int>(59, 89));
//	a.insert(std::pair<int, int>(89, 78));
//	a.insert(std::pair<int, int>(78, 88));
//	a.insert(std::pair<int, int>(88, 4));
//	a.insert(std::pair<int, int>(4, 82));
//	a.insert(std::pair<int, int>(82, 72));
//	a.insert(std::pair<int, int>(72, 84));
//	a.insert(std::pair<int, int>(84, 16));
//	a.insert(std::pair<int, int>(16, 25));
//	a.insert(std::pair<int, int>(25, 42));
//	a.insert(std::pair<int, int>(42, 0));
//	a.insert(std::pair<int, int>(0, 52));
//	a.insert(std::pair<int, int>(52, 15));
//	a.insert(std::pair<int, int>(15, 71));
//	a.insert(std::pair<int, int>(71, 96));
//	a.insert(std::pair<int, int>(96, 97));
//	a.insert(std::pair<int, int>(97, 12));
    ft::map<int, int>::iterator it = a.begin();
    ft::map<int, int>::iterator it1 = a.end();
//    std::pair<int, int> *p = ss();
//    std::cout <<p->first<<std::endl;
//	--it;
//	--it1;
//    for (; it != it1; --it1) {
//        std::cout << "first " << it1->first << " second " << it1->second << std::endl;
//    }
	int i = 1;
    for (; it != it1 || imap != b.end(); ++it, ++imap) {
        std::cout << "first " << it->first <<RESET<< " second " << it->second <<RESET<< "  first "<< imap->first << " second " <<imap->second << std::endl;
        i++;
    }
    std::cout <<i;
//	for (; it != it1; ++it) {
//		out << "a.insert(std::pair<int, int>(" <<a[1 ]<< ", "<<arr[i + 1]<< "));"<<std::endl;
//	}
    return 0;
}
