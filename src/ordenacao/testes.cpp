#include <iostream>
#include <array>
#include <functional>
#include <chrono>
#include <format>

#include "bubble.hpp"

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


}

int main() {


    std::vector<int> numeros { 33, 10, 100, 34, 6, 3, 2, 7, 9, 345 };

    print_sorting("Bubble", Order::bubble_sort, numeros);
}
