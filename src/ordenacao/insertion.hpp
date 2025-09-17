#include <vector>

namespace Order {

void insertion_sort(std::vector<int>& list) {

    //o i = 1 pois o insertion sort compara o final da lista e se for um unico elemento ele esta ordenado por padrão
    for (int i = 1; i < list.size(); ++i) {


        //loop para inserir o ultimo de maneira ordenada
        int j = i;
        while ( j > 0 && list[j] < list[j - 1] ) { 

            int temp = list[j];
            list[j] = list[j - 1];
            list[j - 1] = temp;

            --j;

        }

    }

}

}
