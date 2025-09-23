#pragma once

#include <graphviz/gvcext.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphviz/cgraph.h>
#include <graphviz/gvc.h>
#include <string.h>

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

    if (node == NULL) return;

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

void tree_to_graph(Agraph_t* graph, Node* node) {

    char buff[10];
    sprintf(buff, "%d", node->value);
    Agnode_t* parent = agnode(graph, buff, 1);

    if (node->left != NULL) {

        sprintf(buff, "%d", node->left->value);
        Agnode_t* child_left = agnode(graph, buff, 1);

        Agedge_t* edge = agedge(graph, parent, child_left, NULL, 1);

        tree_to_graph(graph, node->left);

    }
    
    if (node->right != NULL) {

        sprintf(buff, "%d", node->right->value);
        Agnode_t* child_right = agnode(graph, buff, 1);

        Agedge_t* edge = agedge(graph, parent, child_right, NULL, 1);

        tree_to_graph(graph, node->right);

    }


}

void print_tree(Node* tree) {

    Agraph_t* graph = agopen("Arvore", Agdirected, NULL);

    tree_to_graph(graph, tree);

    GVC_t* context = gvContext();

    // Layout the graph
    if (gvLayout(context, graph, "dot") != 0) {
        fprintf(stderr, "Error: Failed to layout graph\n");
        return ;
    }
    
    // Render to PNG file
    if (gvRenderFilename(context, graph, "png", "arvore_simples.png") != 0) {
        fprintf(stderr, "Error: Failed to render graph to file\n");
        return ;
    }
    
    // Free layout data
    gvFreeLayout(context, graph);
    
    // Close the graph
    agclose(graph);
    
    // Free the context
    gvFreeContext(context);
    

}


