#include <vector>

namespace Order {

void gaping_sort(std::vector<int>& list, int gap, int start) {

    for (int i = start + gap; i < list.size(); i += gap) {

        //fazemos os insertions sort levando em conta a distancia
        int j = i;
        while (j > 0 && list[i - gap] > list[i]) {

            int temp = list[i];
            list[i] = list[i - gap];
            list[i - gap] = temp;

            j -= gap;
        }


    }

}

void shell_sort(std::vector<int>& list) {

    //determinamos quantas sublistas teremos, a formula pode variar, entao vamos com a mais basica
    int sublist_count = list.size()/2;

    while (sublist_count > 0) {


        for (int i = 0; i < sublist_count; ++i) {

            //fazemos os insertion sort com as sublistas
            gaping_sort(list, sublist_count, i);

        }

        //diminuimos a quantia de sublistas
        sublist_count = sublist_count / 2;

    }


}

}
