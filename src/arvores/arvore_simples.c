#include "arvore_simples.h"

int main() {

    int numbers[] = {10, 33, 148, 99, 23, 2, 1049, 233};

    Node* tree = generate_tree(numbers, sizeof(numbers)/sizeof(int));

    printf("Ordem: ");
    print_order(tree);
    printf("\n");

    printf("Pos ordem: ");
    print_postorder(tree);
    printf("\n");

    printf("Pre ordem: ");
    print_preorder(tree);
    printf("\n");

    print_tree(tree);

    return 0;

}
