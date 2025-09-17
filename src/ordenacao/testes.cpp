#include <iostream>
#include <array>
#include <functional>
#include <chrono>
#include <format>
#include <cassert>
#include <algorithm>

#include "bubble.hpp"
#include "insertion.hpp"
#include "selection.hpp"
#include "shell.hpp"

void print_sorting(const std::string&& sorting_name, std::function<void(std::vector<int>&)> sort_func, std::vector<int> target) {

    auto start_time = std::chrono::high_resolution_clock::now();

    sort_func(target);

    auto end_time = std::chrono::high_resolution_clock::now();

    std::cout << sorting_name << " sort = { ";

    for (int number : target) {

        std::cout << number << " ";
    }

    std::cout << "}\n";

    auto elapsed_time = end_time - start_time;
    std::cout << "Time = " << elapsed_time.count() << "ns" << std::endl << std::endl;

    //verifica se o algoritimo realmente oredenou o array
    std::vector<int> ideal_result = target;

    std::sort(ideal_result.begin(), ideal_result.end());

    assert(target == ideal_result);
}

int main(int argc, char** argv) {

    std::vector<int> numeros;

    if (argc <= 1) {

        numeros = { 33, 10, 100, 34, 6, 3, 2, 7, 9, 345 };

    } else {

        for (int i = 1; i < argc; ++i) {

            numeros.push_back(std::stoi(argv[i]));
        }

    }

    print_sorting("Bubble", Order::bubble_sort, numeros);
    print_sorting("Insertion",Order::insertion_sort, numeros);
    print_sorting("Selection", Order::selection_sort, numeros);
    print_sorting("Shell", Order::shell_sort, numeros);
}
