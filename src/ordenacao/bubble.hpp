#include <vector>

namespace Order {

void bubble_sort(std::vector<int>& list) {

    // os tamanhos estao subitraidos de 1, pois sempre visitamos o proximo elemento que estamos analizando junto do elemento atual
    for (int i = 0; i < list.size() - 1 ; ++i) {

        //o tamanho ta por - i, pois o final da lista ja vai ser ordenado com o passar das iterações
        for (int j = 0; j < list.size() - i - 1 ; ++j) {

            if (list[j] > list[j + 1]) {

                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;

            }

        }

    }

}

}
