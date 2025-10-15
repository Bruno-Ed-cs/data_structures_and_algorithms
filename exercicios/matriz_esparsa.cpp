#include <cassert>
#include <cstddef>
#include <ostream>
#include <vector>
#include <iostream>

// Opa opa! parece que temos um programa que cria uma matiz esparsa 
// quebrado aqui implorando para ser consertado e acho que cabe //
// a você caro aluno a conserta-lo

// O ??? indica onde o progragama está em falta de algum termo

struct ElementoM {

    // Minha nossa nossa nossa.
    // Temos aqui a estrutura do elemento da nossa matriz esparsa
    // claramente incompleta, lembre-se que uma matriz esparsa nada
    // mais é do que uma lista de listas encadeadas com os numeros 
    // relevantes da nossa matriz
    //

    size_t coluna;

    // Aqui temos o elemento vizinho do elemento atual, o que ele deveria ser?
    ??? vizinho;
    int valor;

};

struct MatrizE {

    // Aqui temos a matriz completa, mas parece que o programador foi preguiçoso em algumas
    // parte, vamos completar;

    size_t linhas;
    size_t colunas;

    // Nossa lista de listas parece carecer de um tipo, e se a gente pensar na matriz
    // como uma lista de ponteiros de elementos o que fariamos?
    std::vector<???> matriz;

    MatrizE(size_t num_linhas, size_t num_colunas) :
    linhas(num_linhas), colunas(num_colunas) {

        // Nada de errado aqui so iniciamos nossa lista com ponteiros nulos
        matriz.reserve(linhas);
        for (int i = 0; i < linhas; ++i)
            matriz.push_back(nullptr);
    };

    // aqui temos o método de pegar um elemento da matriz, mas a assinatura ta incompleta
    // seria bom as linhas e colunas serem algum tipo de número que nao pode ser menor que 0
    //
    // Extra: fazer a funçao nao permitir a entrada de linhas e colunas maiores do que a matriz
    int get(??? linha, ??? coluna) {

        ElementoM* temp = matriz[linha];

        if (temp == nullptr)
            return 0;

        while (temp->vizinho != nullptr && temp->coluna != coluna) {

            // estavamos prestes a caminhar uma das lista, mas equeci como,
            // qual seria o elemento que esta do lado do nosso atual?
            temp = temp->???;
        }

        if (temp->coluna != coluna)
            return 0;

        return temp->valor;

    };

    // aqui temos um método para mudar/adicionar um elemento na nossa matriz,
    // mas algo está faltando, vamos dar uma olhada
    void set(size_t linha, size_t coluna, int novo_num) {
        ElementoM* temp = matriz[linha];

        if (coluna == 0 || temp == nullptr) {
            matriz[linha] = new ElementoM{coluna, nullptr, novo_num};
            return;
        }

        // Para percorer a lista temos que nos cetificar de que nao estamos 
        // além do ultimo elemento da lista, como comparariamos o ultimo elemento 
        // a nada?
        while (temp != ??? && temp->coluna != coluna) {


            if (temp->vizinho->coluna > coluna)
                break;
            else 
                temp = temp->vizinho;

        }

        // Nada de errado aqui, so mudando o valor se ja tiver alguma coisa, caso contrario 
        // adicionamos um novo para a lista
        //
        if (temp != nullptr && temp->coluna == coluna) {
            temp->valor = novo_num;
            return;
        }

        temp->vizinho = new ElementoM{coluna, nullptr, novo_num};
        return;

        //Nota: esse metodo não é o mais seguro, so é o mais rapido de escrever

    };

    void print() {

        std::cout << "Matrix: \n";

        for (int i = 0; i < linhas; ++i) {

            for (int j = 0; j < colunas; ++j) {

                // Nessa funcao de print corremos a matriz como se fosse uma
                // feita com arrays normais, nossa imagine se tivessemos um 
                // metodo para acessar qualquer elemento da matriz
                std::cout << ??? << " ";
            }

            std::cout << "\n";

        }

        std::cout << std::endl;
        
    };

};

int main() {

    //iniciamos a matriz com o tamanho
    MatrizE matriz{5, 5};

    // colocamos os valores 3 e 10 nas respectivas posicoes
    matriz.set(0, 0, 3);
    matriz.set(3, 2, 10);

    assert(matriz.get(0, 0) == 3 && "oops o numero 3 nao ta na linha 0, coluna 0\n");
    assert(matriz.get(3, 2) == 10);

    // imprimimos a matriz
    matriz.print();

    // resultado esperado:
    //Matrix: 
    //3 0 0 0 0 
    //0 0 0 0 0 
    //0 0 0 0 0 
    //0 0 10 0 0 
    //0 0 0 0 0 

    return 0;

}
