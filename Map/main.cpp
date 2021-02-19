//
// Created by Kanat Saribaew on 2/12/21.
//
#include "map.hpp"
#include <map>
#include <vector>
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
//	map<int, int>s;
    ft::map<int, int>d;
//    d.erase()
	srand(time(nullptr));
    ft::map<int, int>a;
//    std::map<int, int>b;
//    int arr[50];
//    for (int i = 0; i != 50; ++i)
//        arr[i] = rand() % 100;
//    std::ofstream out("/Users/ndreadno/ft_container/Map/test.txt");
//    for (int i = 0; i + 1 != 50; ++i){
//    	b.insert(std::pair<int, int>(arr[i], arr[i + 1]));
//    }
//    for (int i = 0; i + 1 != 50; ++i){
//        out << "a.insert(std::pair<int, int>("<<arr[i]<< ", "<<arr[i + 1]<< "));"<<std::endl;
//    }
//    out.close();
////    std::map<int, int>::iterator imap = b.begin();
//
//    for (int i = 0; i + 1 != 50; ++i) {
//        a.insert(std::pair<int, int>(arr[i], arr[i + 1]));
////    }
	a.insert(std::pair<int, int>(90, 92));
	a.insert(std::pair<int, int>(902, 92));
	a.insert(std::pair<int, int>(902, 92));
	a.insert(std::pair<int, int>(902, 92));
	a.insert(std::pair<int, int>(9202, 92));
	a.insert(std::pair<int, int>(9203, 92));
	a.insert(std::pair<int, int>(9204, 92));
	a.insert(std::pair<int, int>(90, 92));
	a.insert(std::pair<int, int>(64, 16));
	a.insert(std::pair<int, int>(7, 71));
	a.insert(std::pair<int, int>(29, 84));
	a.insert(std::pair<int, int>(55, 30));
	a.insert(std::pair<int, int>(30, 22));
	a.insert(std::pair<int, int>(22, 63));
	a.insert(std::pair<int, int>(63, 53));
	a.insert(std::pair<int, int>(91, 92));
	a.insert(std::pair<int, int>(92, 12));
	a.insert(std::pair<int, int>(12, 28));
	a.insert(std::pair<int, int>(85, 95));
	a.insert(std::pair<int, int>(95, 14));
	a.insert(std::pair<int, int>(14, 53));
	a.insert(std::pair<int, int>(53, 10));
	a.insert(std::pair<int, int>(10, 72));
	a.insert(std::pair<int, int>(65, 62));
	a.insert(std::pair<int, int>(62, 96));
	a.insert(std::pair<int, int>(40, 76));
	a.insert(std::pair<int, int>(76, 28));
	a.insert(std::pair<int, int>(28, 59));
	a.insert(std::pair<int, int>(59, 89));
	a.insert(std::pair<int, int>(89, 78));
	a.insert(std::pair<int, int>(78, 88));
	a.insert(std::pair<int, int>(88, 4));
	a.insert(std::pair<int, int>(4, 82));
	a.insert(std::pair<int, int>(82, 72));
	a.insert(std::pair<int, int>(72, 84));
	a.insert(std::pair<int, int>(84, 16));
	a.insert(std::pair<int, int>(16, 25));
	a.insert(std::pair<int, int>(25, 42));
	a.insert(std::pair<int, int>(42, 0));
	a.insert(std::pair<int, int>(0, 52));
	a.insert(std::pair<int, int>(52, 15));
	a.insert(std::pair<int, int>(15, 71));
	a.insert(std::pair<int, int>(71, 96));
	a.insert(std::pair<int, int>(96, 97));
	a.insert(std::pair<int, int>(97, 12));

	a.insert(std::pair<int, int>(12, 21));
	a.insert(std::pair<int, int>(21, 81));
	a.insert(std::pair<int, int>(81, 54));
	a.insert(std::pair<int, int>(54, 74));
	a.insert(std::pair<int, int>(74, 55));
	a.insert(std::pair<int, int>(55, 63));
	a.insert(std::pair<int, int>(63, 51));
	a.insert(std::pair<int, int>(51, 51));
	a.insert(std::pair<int, int>(76, 10));
	a.insert(std::pair<int, int>(10, 55));
	a.insert(std::pair<int, int>(66, 99));
	a.insert(std::pair<int, int>(99, 33));
	a.insert(std::pair<int, int>(33, 12));
	a.insert(std::pair<int, int>(5, 48));
	a.insert(std::pair<int, int>(48, 26));
	a.insert(std::pair<int, int>(26, 5));
	a.insert(std::pair<int, int>(93, 85));
	a.insert(std::pair<int, int>(85, 54));
	a.insert(std::pair<int, int>(6, 35));
	a.insert(std::pair<int, int>(35, 19));
	a.insert(std::pair<int, int>(19, 8));
	a.insert(std::pair<int, int>(8, 14));
	a.insert(std::pair<int, int>(14, 76));
	a.insert(std::pair<int, int>(43, 41));
	a.insert(std::pair<int, int>(41, 83));
	a.insert(std::pair<int, int>(83, 30));
	a.insert(std::pair<int, int>(30, 96));
	a.insert(std::pair<int, int>(96, 37));
	a.insert(std::pair<int, int>(37, 54));
	a.insert(std::pair<int, int>(11, 85));
	a.insert(std::pair<int, int>(69, 10));
	a.insert(std::pair<int, int>(22, 86));
	a.insert(std::pair<int, int>(86, 51));
	a.insert(std::pair<int, int>(32, 45));
	a.insert(std::pair<int, int>(45, 42));
	a.insert(std::pair<int, int>(42, 61));
	a.insert(std::pair<int, int>(61, 80));
	a.insert(std::pair<int, int>(80, 66));






	d.insert(std::pair<int, int>(902, 92));
	d.insert(std::pair<int, int>(90, 92));
	d.insert(std::pair<int, int>(902, 92));
	d.insert(std::pair<int, int>(902, 92));
	d.insert(std::pair<int, int>(9202, 92));
	d.insert(std::pair<int, int>(9203, 92));
	d.insert(std::pair<int, int>(9204, 92));
	d.insert(std::pair<int, int>(90, 92));
	d.insert(std::pair<int, int>(64, 16));
	d.insert(std::pair<int, int>(7, 71));
	d.insert(std::pair<int, int>(29, 84));
	d.insert(std::pair<int, int>(55, 30));
	d.insert(std::pair<int, int>(30, 22));
	d.insert(std::pair<int, int>(22, 63));
	d.insert(std::pair<int, int>(63, 53));
	d.insert(std::pair<int, int>(91, 92));
	d.insert(std::pair<int, int>(92, 12));
	d.insert(std::pair<int, int>(12, 28));
	d.insert(std::pair<int, int>(85, 95));
	d.insert(std::pair<int, int>(95, 14));
	d.insert(std::pair<int, int>(14, 53));
	d.insert(std::pair<int, int>(53, 10));
	d.insert(std::pair<int, int>(10, 72));
	d.insert(std::pair<int, int>(65, 62));
	d.insert(std::pair<int, int>(62, 96));
	d.insert(std::pair<int, int>(40, 76));
	d.insert(std::pair<int, int>(76, 28));
	d.insert(std::pair<int, int>(28, 59));
	d.insert(std::pair<int, int>(59, 89));
	d.insert(std::pair<int, int>(89, 78));
	d.insert(std::pair<int, int>(78, 88));
	d.insert(std::pair<int, int>(88, 4));
	d.insert(std::pair<int, int>(4, 82));
	d.insert(std::pair<int, int>(82, 72));
	d.insert(std::pair<int, int>(72, 84));
	d.insert(std::pair<int, int>(84, 16));
	d.insert(std::pair<int, int>(16, 25));
	d.insert(std::pair<int, int>(25, 42));
	d.insert(std::pair<int, int>(42, 0));
	d.insert(std::pair<int, int>(0, 52));
	d.insert(std::pair<int, int>(52, 15));
	d.insert(std::pair<int, int>(15, 71));
	d.insert(std::pair<int, int>(71, 96));
	d.insert(std::pair<int, int>(96, 97));
	d.insert(std::pair<int, int>(97, 12));

	ft::map<int, int>::iterator it = a.end();
	for (; it != a.end(); ++it){
		std::cout << it->first << " "<<it->second<<std::endl;
	}
	std::cout <<"a " <<a.size()<<std::endl;
	std::cout << "d "<<d.size()<<std::endl;
//	a.show();
	std::cout << a.lower_bound(100000)->first<<std::endl;
	std::cout << d.lower_bound(100000)->first<<std::endl;
	if ( a.upper_bound(100000) == a.end())
		std::cout << "true"<<std::endl;
	if ( d.upper_bound(100000) == d.end())
		std::cout << "true"<<std::endl;
	std::cout << a[100000]<<std::endl;
	std::cout << d[100000]<<std::endl;
	std::cout <<"a " <<a.size()<<std::endl;
	std::cout << "d "<<d.size()<<std::endl;
	d.swap(a);
	std::cout <<"a " <<a.size()<<std::endl;
	std::cout << "d "<<d.size()<<std::endl;
    return 0;
}
