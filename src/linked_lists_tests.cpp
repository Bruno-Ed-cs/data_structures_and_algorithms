#include <cassert>
#include <exception>
#include <iostream>
#include "linked_l/ki.hpp"
#include <iterator>
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

    assert(list.pop() == 10);
    assert(list.len() == 2);
    list.insert(1, 108);
    assert(list[1] = 108);

    for (size_t i = 0; i < list.len(); ++i) {

        std::cout << "list index [" << i << "]  = " << list[i] << '\n';
    }
    std::cout << std::endl;

    list.remove(1);

    assert(list[1] != 108);
    for (size_t i = 0; i < list.len(); ++i) {

        std::cout << "list index [" << i << "]  = " << list[i] << '\n';
    }
    std::cout << std::endl;

    list.remove(0);

    for (size_t i = 0; i < list.len(); ++i) {

        std::cout << "list index [" << i << "]  = " << list[i] << '\n';
    }

    std::cout << std::endl;

    trouble.append(1.1);
    trouble.append(2.2);
    trouble.append(3.3);

    for (auto node : trouble) {

        std::cout << "iterator value= " << node << std::endl;
    }

    return 0;

}
