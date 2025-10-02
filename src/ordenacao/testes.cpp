#include <iostream>
#include <functional>
#include <random>
#include <chrono>
#include <cassert>
#include <print>
#include <algorithm>

#include "merge.hpp"
#include "bubble.hpp"
#include "insertion.hpp"
#include "selection.hpp"
#include "shell.hpp"
#include "heap.hpp"
#include "quick.hpp"

//Como usar os testes:
//se o binario for executado sem argumentos ele usa um vetor predefinido
//
//é possivel passar seu propio vetor de numeros, basta passar n números como argumentos do programa
//ex: ordenadores 2 55 99 107 3 5 33 56
//
//caso queira usar numeros randomicos basta passar o primeiro argumento como random e depois passar o tamanho do vetor
//ex: ordenadores random 1000
//
//para um vetor com 1000 numeros aleatorios

//tempos de execução com 100000 elementos aleatorios
//Shell sort = { }
//Time = 74 milliseconds
//
//Heap sort = { }
//Time = 47 milliseconds
//
//Merge sort = { }
//Time = 54 milliseconds
//
//Quick sort = { }
//Time = 29 milliseconds
//
//Insertion sort = { }
//Time = 47246 milliseconds
//
//Selection sort = { }
//Time = 40350 milliseconds
//
//Bubble sort = { }
//Time = 89939 milliseconds

void print_sorting(const std::string&& sorting_name, std::function<void(std::vector<int>&)> sort_func, std::vector<int> target) {

    auto start_time = std::chrono::high_resolution_clock::now();

    sort_func(target);

    auto end_time = std::chrono::high_resolution_clock::now();

    std::cout << sorting_name << " sort = { ";

    if (target.size() < 500) {

        for (int number : target) {

            std::cout << number << " ";
        }

        std::cout << "}\n";

        auto elapsed_time = end_time - start_time;

        std::cout << "Time = " << elapsed_time.count() << " nanoseconds" << std::endl << std::endl;

    } else {
    
        std::cout << "}\n";

        auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

        std::cout << "Time = " << elapsed_time.count() << " milliseconds" << std::endl << std::endl;

    }

    //verifica se o algoritimo realmente oredenou o array
    std::vector<int> ideal_result = target;

    std::sort(ideal_result.begin(), ideal_result.end());

    assert(target == ideal_result);
}

int main(int argc, char** argv) {

    std::vector<int> numeros;

    if (argc <= 1) {

        numeros = { 33, 10, 100, 34, 6, 3, 2, 7, 9, 345 };

    } else if (std::string(argv[1]) == "random") {


        int len = std::stoi(argv[2]);
        numeros.reserve(len);

        std::random_device rand;
        std::mt19937 gen(rand());

        std::uniform_int_distribution<int> int_range(0, 10000);

        for (int i = 0; i < len; ++i) {

            numeros.push_back(int_range(gen));
        }


    } else {

        for (int i = 1; i < argc; ++i) {

            numeros.push_back(std::stoi(argv[i]));
        }

    }

    print_sorting("Shell", Order::shell_sort, numeros);
    print_sorting("Heap", Order::heap_sort, numeros);
    print_sorting("Merge", Order::merge_sort, numeros);
    print_sorting("Quick", Order::quick_sort, numeros);
    print_sorting("Insertion",Order::insertion_sort, numeros);
    print_sorting("Selection", Order::selection_sort, numeros);
    print_sorting("Bubble", Order::bubble_sort, numeros);


    std::println("alguma string e o template: {}", numeros);
}
