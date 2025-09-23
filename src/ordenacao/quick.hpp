#include <utility>
#include <vector>

namespace Order {

// função para pegar o pivô por meio da mediana do primeiro, ultimo e do elemento do meio
int pivot(std::vector<int>& list, int first, int last) {

    int middle = ((last - first) / 2) + first;

    if (list[first] > list[middle]) {

        std::swap(list[first], list[middle]);

    }

    if (list[middle] > list[last]) {

        std::swap(list[middle], list[last]);

    }

    if (list[first] > list[last]) {

        std::swap(list[last], list[first]);

    }

    return middle;

}

void sort(std::vector<int>& list, int begin, int end) {

    //condição de retorno, ou seja se a patição é de 1 elemento
    if (begin >= end) {

        return;
    }

    int pivot_i = pivot(list, begin, end);

    // isolamento do pivo no final da lista
    std::swap(list[pivot_i], list[end]);

    int i = begin;
    int j = end -1;

    // corremos o i e o j ate eles se cruzarem
    while (i <= j) {

        while (i <= j && list[i] <= list[end]) {
            ++i;
        }

        while (i <= j && list[j] >= list[end]) {
            --j;
        }

        if (i < j) {

            std::swap(list[i], list[j]);
        }

    }

    //depois de ordenar as partiçoes nos trocamos o pivo com o elemento i
    std::swap(list[i], list[end]);
    
    //particionamos as partições recursivamente
    sort(list, begin, i - 1);
    sort(list, i + 1, end);


}

void quick_sort(std::vector<int>& list) {

    //caso inicial da função recursiva
    sort(list, 0, list.size() - 1);

}

}
