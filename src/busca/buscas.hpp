#pragma once

#include <vector>

namespace Search {

bool linear(std::vector<int>& list, int target) {

    for (int i = 0; i < list.size(); ++i) {

        if (list[i] == target) {
            return true;
        }

    }

    return false;

}

bool binary(std::vector<int>& list, int target) {

    // definimos o inicio e o fim da primeira partição
    int begin = 0;
    int end = list.size() -1;

    // paramos qando a partição é menor ou igual a 1
    while (begin <= end) {

        //calculo para pegar o ponto do meio na partição
        int index = ((end - begin) / 2) + begin;

        if (list[index] == target) {

            return true;

            //se nao encontramos o elemento fazemos a partição binaria
        } else if (target < list[index]) {

            //vamos para a esquerda
            end  = index - 1;

        } else {

            //vamos para a direita
            begin = index + 1;

        }


    }

    return false;

}

bool interpolation(std::vector<int>& list, int target) {

    int begin = 0;
    int end = list.size() -1;

    while (begin <= end) {

        //literalmente a mesma coisa da binaria, mas com a formula para achar o pivô dos elementos com variancia pequena
        int index = begin + (((target - list[begin]) * (begin * end)) / (list[end] - list[begin]));

        if (list[index] == target) {

            return true;

        } else if (target < list[index]) {

            end  = index - 1;

        } else {

            begin = index + 1;

        }


    }

    return false;


}

}
