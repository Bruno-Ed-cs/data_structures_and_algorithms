#pragma once

#include <graphviz/cgraph.h>
#include <graphviz/gvc.h>
#include <graphviz/gvcext.h>
#include <span>
#include <string>
#include <vector>

namespace Graph {

void print_matrix_graph(std::vector<std::vector<int>> matrix) {

    char* nome = std::string("Grafo nao direcionado").data();
    Agraph_t* graph = agopen(nome, Agundirected, NULL);

    std::vector<Agnode_t*> nodes;
    std::vector<Agedge_t*> edges;

    for (int i = 0; i < matrix.size(); ++i) {

        Agnode_t* node = agnode(graph, std::to_string(i + 1).data(), 1);
        nodes.push_back(node);
    }

    for (int i = 0; i < matrix.size(); ++i) {

        for(int j = 0; j <= i && j < matrix[i].size(); ++j) {

            if (matrix[i][j] == 1) {

                Agedge_t* edge = agedge(graph, nodes[i], nodes[j], NULL, 1);
                edges.push_back(edge);
            }

        }

    }


    GVC_t* context = gvContext();

    // Layout the graph
    if (gvLayout(context, graph, "dot") != 0) {
        fprintf(stderr, "Error: Failed to layout graph\n");
        return ;
    }
    
    // Render to PNG file
    if (gvRenderFilename(context, graph, "png", "grafo_nao_direcionado.png") != 0) {
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


}
