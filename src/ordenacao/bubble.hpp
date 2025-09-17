#include <iostream>
#include <vector>
#include <functional>

namespace Order {

void bubble_sort(std::vector<int>& list) {

    for (int i = 0; i < list.size(); ++i) {

        for (int j = i + 1; j < list.size(); ++j) {

            if (list[i] > list[j]) {

                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;

            }

        }

    }

}

}
