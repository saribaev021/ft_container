//
// Created by Kanat Saribaew on 2/12/21.
//
#include "map.hpp"
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
//    int arr[10];
//    for (int i = 0; i != 10; ++i)
//        arr[i] = rand() % 100;
//    std::ofstream out("/Users/ndreadno/ft_container/Map/test.txt");
//    for (int i = 0; i != 10; ++i){
//        out << arr[i] << " ";
//    }
//    out.close();
//    for (int i = 0; i + 1 != 5; ++i) {
//        a.insert(std::pair<int, int>(arr[i], arr[i + 1]));
//    }
   a.insert(std::pair<int, int>(89, 13));
   a.insert(std::pair<int, int>(93, 47));
   a.insert(std::pair<int, int>(7, 29));

   a.insert(std::pair<int, int>(51, 13));
   a.insert(std::pair<int, int>(36, 3));
   a.insert(std::pair<int, int>(4, 44));
   a.insert(std::pair<int, int>(64, 26));
   a.insert(std::pair<int, int>(82, 41));
   a.insert(std::pair<int, int>(8, 72));
   a.insert(std::pair<int, int>(54, 71));
    ft::map<int, int>::iterator it = a.begin();
    ft::map<int, int>::iterator it1 = a.end();
//    std::pair<int, int> *p = ss();
//    std::cout <<p->first<<std::endl;
    for (; it != it1; ++it) {
        std::cout << "first " << it->first << " second " << it->second << std::endl;
    }
    return 0;
}
