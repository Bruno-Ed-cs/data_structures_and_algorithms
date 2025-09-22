#include <cstdlib>
#include <iostream>
#include <array>
#include <functional>
#include <random>
#include <chrono>
#include <format>
#include <cassert>
#include <algorithm>

#include "bubble.hpp"
#include "insertion.hpp"
#include "selection.hpp"
#include "shell.hpp"

//tempos de execução
// time ./ordenadores random 100000
// Bubble sort = { }
// Time = 81345 milliseconds
// 
// Insertion sort = { }
// Time = 47172 milliseconds
// 
// Selection sort = { }
// Time = 41885 milliseconds
// 
// Shell sort = { }
// Time = 73 milliseconds
// 
// 
// real	2m50.504s
// user	2m50.456s
// sys	0m0.005s


void print_sorting(const std::string&& sorting_name, std::function<void(std::vector<int>&)> sort_func, std::vector<int> target) {

    auto start_time = std::chrono::high_resolution_clock::now();

    sort_func(target);

    auto end_time = std::chrono::high_resolution_clock::now();

    std::cout << sorting_name << " sort = { ";

    if (target.size() < 50) {

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

    print_sorting("Bubble", Order::bubble_sort, numeros);
    print_sorting("Insertion",Order::insertion_sort, numeros);
    print_sorting("Selection", Order::selection_sort, numeros);
    print_sorting("Shell", Order::shell_sort, numeros);
}
