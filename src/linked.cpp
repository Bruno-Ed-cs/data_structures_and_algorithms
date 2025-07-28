#include <exception>
#include <iostream>
#include "linked_l/ki.hpp"
#include <vector>
#include "linked_l/linked_list.hpp"

struct tt {
    int first;
    int second;
};

int main() { 

    std::cout << "hello vagabunda" << std::endl;
    ki();
    tt tee;

    std::vector<int>::iterator it;


    std::cout << tee.second << std::endl;

    ds::LinkedList<int> list;
    ds::LinkedList<double> trouble(22.2f);

    try {
        list[0];
    } catch (std::exception& e) {

        std::cout << e.what();
    }

    list.append(22);
    std::cout << "append 22" << '\n';

    list.append(2);
    std::cout << "append 2" << '\n';
    
    list.append(10);
    std::cout << "append 10" << '\n';

    std::cout << "Trouble first element: "<< trouble[0] << std::endl;
    
    return 0;

}
