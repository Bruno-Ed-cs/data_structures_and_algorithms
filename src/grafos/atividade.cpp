#include "print_matrix.hpp"
#include <vector>

int main() {

    std::vector<std::vector<int>> mat = {
        {0, 0, 1},
        {0, 1, 1},
        {1, 1, 0}
    };

    Graph::print_matrix_graph(mat);

    return 0;

}
