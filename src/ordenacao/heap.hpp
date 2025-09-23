#include <utility>
#include <vector>

namespace Order {

int get_parent(int index) { return (index - 1) / 2; };
int get_left(int index) { return 2 * index + 1; };
int get_right(int index) { return 2 * index + 2; };

void heapify (std::vector<int>& list, int root, int limit) {

    int left = get_left(root);
    int right = get_right(root);
    int biggest = root;


    if (left < limit && list[left] > list[biggest]) {
        biggest = left;
    }

    if (right < limit && list[right] > list[biggest]) {
        biggest = right;
    }


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

    for (int i = size -1; i > 0; --i) {

        std::swap(list[i], list[0]);

        heapify(list, 0, i);

    }

}

}
