#include <utility>
#include <vector>

namespace Order {

//formulas para tratar o array como arvore
int get_parent(int index) { return (index - 1) / 2; };
int get_left(int index) { return 2 * index + 1; };
int get_right(int index) { return 2 * index + 2; };

//função para fazer um no atender a condição do max heap
void heapify (std::vector<int>& list, int root, int limit) {

    int left_index = get_left(root);
    int right_index = get_right(root);
    int biggest = root;


    if (left_index < limit && list[left_index] > list[biggest]) {
        biggest = left_index;
    }

    if (right_index < limit && list[right_index] > list[biggest]) {
        biggest = right_index;
    }


    //se o no não atende a condição entao aplicamos o balanceamento no maior elemento para fazer ele ir em direção a raiz
    if (biggest != root) {

        std::swap(list[root], list[biggest]);
        heapify(list, biggest, limit);

    }

}

void heap_sort(std::vector<int>& list) {

    int size = list.size();

    //para tornar o array em um heap, voce inicia o heapify do ultimo pai
    for (int i = get_parent(size); i >= 0; --i) {

        heapify(list, i, size);

    }

    // aqui fazemos de fato a ordenação pegando a raiz do heap
    for (int i = size -1; i > 0; --i) {

        std::swap(list[i], list[0]);

        heapify(list, 0, i);

    }

}

}
