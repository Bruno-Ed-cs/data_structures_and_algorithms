#include <cassert>
#include <cstddef>
#include <vector>
#include <iostream>

struct ElementoM {

    size_t coluna;
    ElementoM* vizinho;
    int valor;

};

struct MatrizE {

    size_t linhas;
    size_t colunas;

    std::vector<ElementoM*> matriz;

    MatrizE(size_t num_linhas, size_t num_colunas) :
    linhas(num_linhas), colunas(num_colunas) {

        matriz.reserve(linhas);
        for (int i = 0; i < linhas; ++i)
            matriz.push_back(nullptr);
    };

    int get(size_t linha, size_t coluna) {

        ElementoM* temp = matriz[linha];

        if (temp == nullptr)
            return 0;

        while (temp->vizinho != nullptr && temp->coluna != coluna) {

            temp = temp->vizinho;
        }

        if (temp->coluna != coluna)
            return 0;

        return temp->valor;

    };

    void set(size_t linha, size_t coluna, int novo_num) {
        ElementoM* temp = matriz[linha];

        if (coluna == 0 || temp == nullptr) {
            matriz[linha] = new ElementoM{coluna, nullptr, novo_num};
            return;
        }

        while (temp != nullptr && temp->coluna != coluna) {

            if (temp->vizinho->coluna > coluna)
                break;
            else 
                temp = temp->vizinho;

        }

        if (temp != nullptr && coluna == coluna) {
            temp->valor = novo_num;
            return;
        }

        temp->vizinho = new ElementoM{coluna, nullptr, novo_num};
        return;

    };

    void print() {
        for (size_t i = 0; i < linhas; ++i) {
            ElementoM* atual = matriz[i];

            // If the row is empty, print all zeros
            if (atual == nullptr) {
                for (size_t j = 0; j < colunas; ++j) {
                    std::cout << "0 ";
                }
                std::cout << "\n";
                continue;
            }

            // Traverse through columns and print values
            size_t coluna_atual = 0;
            while (atual != nullptr) {
                // Print zeros for columns before the current element
                while (coluna_atual < atual->coluna) {
                    std::cout << "0 ";
                    coluna_atual++;
                }

                // Print the actual value
                std::cout << atual->valor << " ";
                coluna_atual++;

                // Move to next element in the row
                atual = atual->vizinho;
            }

            // Print zeros for remaining columns in the row
            while (coluna_atual < colunas) {
                std::cout << "0 ";
                coluna_atual++;
            }

            std::cout << "\n";
        }
    };

};

int main() {

    MatrizE matriz{5, 5};

    matriz.set(0, 0, 3);
    matriz.set(3, 2, 10);

    assert(matriz.get(0, 0) == 3 && "oops o numero 3 nao ta na linha 0, coluna 0\n");
    assert(matriz.get(3, 2) == 10);

    matriz.print();

    return 0;

}
