#include <utility>
#include <vector>

namespace Order {

void merge(std::vector<int>& list, int begin, int middle, int end) {

    //vetor auxiliar para colocar o setor ordenado
    std::vector<int> aux;
    aux.reserve(end - begin);

    // index da primeira partição
    int index_first = begin;

    //index da segunda partição
    int index_second = middle +1;

    //colocamos na lista ate alguem chegar no final da sua partição
    while (index_first <= middle && index_second <= end) {

        if (list[index_first] < list[index_second]) {

            aux.push_back(list[index_first]);
            index_first++;

        } else {

            aux.push_back(list[index_second]);
            index_second++;
        }

    }

    // os dois loops sao para colocar o resto da partição que sobrou
    while (index_first <= middle) {

        aux.push_back(list[index_first]);
        ++index_first;
    }

    while (index_second <= end) {

        aux.push_back(list[index_second]);
        ++index_second;
    }

    //colocamos o vetor ordenado na lista original
    int index = begin; 
    for (int num : aux) {

        list[index] = num;
        index++;

    }

};

void divide(std::vector<int>& list, int begin, int end) {

    // formula para encontrar o meio do setor atual
    int middle = (end - begin) / 2 + begin;

    // caso a divisao seja de apenas um elemento nos paramos a recursao;
    if (end - begin > 0) {

        divide(list, begin, middle);
        divide(list, middle +1, end);

        //depois de dividir a lista nos fundimos as duas
        merge(list, begin, middle, end);
    }

    return;

};

void merge_sort(std::vector<int>& list) {

    //Caso inicial da divisao com o vetor inteiro
    divide(list, 0, list.size() -1);
};

}
