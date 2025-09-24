#include <print>
#include <vector>
#include "buscas.hpp"
#include "search.h"

int main() {

    std::vector<int> arr{ 21, 32, 33, 34, 38, 43, 44, 52, 53, 54, 55, 56, 63, 66, 77 };

    std::println("Linear Search = {}", Search::linear(arr, 1));
    std::println("Binary Search = {}", Search::binary(arr, 1));
    std::println("Interpolation Search = {}", Search::interpolation(arr, 1));
}
