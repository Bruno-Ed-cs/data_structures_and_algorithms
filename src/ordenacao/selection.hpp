#include <vector>
#include <utility>

namespace Order {

void selection_sort(std::vector<int>& list) {

    for (int i = 0; i < list.size(); ++i) {


        //procuramos o menor elemento a partir do i, pois o inicio ja esta sendo ordenado
        int smallest = i;
        for (int j = i + 1; j < list.size(); ++j) {

            if (list[smallest] > list[j]) {

                smallest = j;

            }

        }

        //colocamos o menor elemento no inicio da iteração, ou seja o i
        int temp = list[i];
        list[i] = list[smallest];
        list[smallest] = temp;

        //pra quem usa c++ no header utility tem uma função de trocar variaveis
        //std::swap(list[smallest], list[i]);


    }

}

}
