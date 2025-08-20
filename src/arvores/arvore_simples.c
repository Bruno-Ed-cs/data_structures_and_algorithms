#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    int value;
    struct Node* left;
    struct Node* right;

} Node;

void insert_binary(Node* node, int input) {

    if (node->value > input) {

        if (node->left == NULL) {
            
            Node* new_node = malloc(sizeof(Node));
        
            new_node->value = input;
            new_node->left = NULL;
            new_node->right = NULL;

            node->left = new_node;

        } else {

            insert_binary(node->left, input);
        }

    } else {

        if (node->right == NULL) {
            
            Node* new_node = malloc(sizeof(Node));
        
            new_node->value = input;
            new_node->left = NULL;
            new_node->right = NULL;

            node->right = new_node;

        } else {

            insert_binary(node->right, input);
        }
    }

};

void print_order(Node* node) {

    if (!node) return;

    print_order(node->left);

    printf("%d ", node->value);

    print_order(node->right);

};

void print_preorder(Node* node) {

    if (!node) return;

    printf("%d ", node->value);

    print_order(node->left);

    print_order(node->right);

};

void print_postorder(Node* node) {

    if (!node) return;

    print_order(node->left);

    print_order(node->right);

    printf("%d ", node->value);

};

Node* generate_tree(int* numbers, size_t size) {

    Node* root = malloc(sizeof(Node));
    root->value = numbers[0];
    root->left = NULL;
    root->right = NULL;

    for (int i = 1; i < size; ++i) {

        insert_binary(root, numbers[i]);

    }

    return root;
}

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

    return 0;

}
