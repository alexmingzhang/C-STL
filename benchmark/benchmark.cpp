#define NUMTESTS 1000000

#include <chrono>
#include <iostream>
#include <list>
#include <map>
#include <random>
#include <vector>

#include "list.h"
#include "map.h"
#include "vector.h"

int main() {
    std::chrono::high_resolution_clock::time_point begin;
    auto rng = std::default_random_engine();

    // Test vector speed
    {
        std::vector<int> stl_vec;
        vector *cstl_vec = vector_construct();

        begin = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < NUMTESTS; ++i) {
            stl_vec.push_back(i);
        }

        double stl_time =
            static_cast<double>(
                std::chrono::duration_cast<std::chrono::nanoseconds>(
                    std::chrono::high_resolution_clock::now() - begin)
                    .count()) /
            1000000000.0;

        begin = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < NUMTESTS; ++i) {
            tvar t;
            t.i = i;
            vector_push_back(cstl_vec, t);
        }

        double cstl_time =
            static_cast<double>(
                std::chrono::duration_cast<std::chrono::nanoseconds>(
                    std::chrono::high_resolution_clock::now() - begin)
                    .count()) /
            1000000000.0;

        std::cout << "Testing vector " << NUMTESTS << " push back operations\n";
        std::cout << "STL Vector: " << stl_time << " seconds\n";
        std::cout << "C-STL Vector: " << cstl_time << " seconds\n";
        std::cout << "C-STL is " << stl_time / cstl_time << "x faster\n\n";
    }

    {
        std::list<int> stl_list;
        list *cstl_list = list_construct();

        begin = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < NUMTESTS; ++i) {
            stl_list.push_back(i);
        }

        double stl_time =
            static_cast<double>(
                std::chrono::duration_cast<std::chrono::nanoseconds>(
                    std::chrono::high_resolution_clock::now() - begin)
                    .count()) /
            1000000000.0;

        begin = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < NUMTESTS; ++i) {
            tvar t;
            t.d = i;
            list_push_back(cstl_list, t);
        }

        double cstl_time =
            static_cast<double>(
                std::chrono::duration_cast<std::chrono::nanoseconds>(
                    std::chrono::high_resolution_clock::now() - begin)
                    .count()) /
            1000000000.0;

        std::cout << "Testing list " << NUMTESTS << " push back operations\n";
        std::cout << "STL List: " << stl_time << " seconds\n";
        std::cout << "C-STL List: " << cstl_time << " seconds\n";
        std::cout << "C-STL is " << stl_time / cstl_time << "x faster\n\n";
    }

    // Test map speed
    {
        std::map<int, int> stl_map;
        map *cstl_map = map_construct();
        std::vector<int> random_numbers;

        for (int i = 0; i < NUMTESTS; ++i) {
            random_numbers.push_back(i);
        }

        std::shuffle(random_numbers.begin(), random_numbers.end(), rng);

        // Inserts
        begin = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < NUMTESTS; ++i) {
            int n = random_numbers[i];
            stl_map[n] = i;
        }

        double stl_time =
            static_cast<double>(
                std::chrono::duration_cast<std::chrono::nanoseconds>(
                    std::chrono::high_resolution_clock::now() - begin)
                    .count()) /
            1000000000.0;

        begin = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < NUMTESTS; ++i) {
            tvar k;
            k.d = random_numbers[i];
            tvar v;
            v.d = i;
            map_insert(cstl_map, map_node_construct(k, v));
        }

        double cstl_time =
            static_cast<double>(
                std::chrono::duration_cast<std::chrono::nanoseconds>(
                    std::chrono::high_resolution_clock::now() - begin)
                    .count()) /
            1000000000.0;

        std::cout << "Testing map " << NUMTESTS << " insert operations\n";
        std::cout << "STL Map: " << stl_time << " seconds\n";
        std::cout << "C-STL Map: " << cstl_time << " seconds\n";
        std::cout << "C-STL is " << stl_time / cstl_time << "x faster\n\n";

        // Finding nodes
        begin = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < NUMTESTS; ++i) {
            int n = random_numbers[i];
            stl_map[n];
        }

        stl_time = static_cast<double>(
                       std::chrono::duration_cast<std::chrono::nanoseconds>(
                           std::chrono::high_resolution_clock::now() - begin)
                           .count()) /
                   1000000000.0;

        begin = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < NUMTESTS; ++i) {
            tvar k;
            k.i = random_numbers[i];
            map_node *n = map_find(cstl_map, k);
            // std::cout << k.d << " " << n->val.i << "\n";
        }

        cstl_time = static_cast<double>(
                        std::chrono::duration_cast<std::chrono::nanoseconds>(
                            std::chrono::high_resolution_clock::now() - begin)
                            .count()) /
                    1000000000.0;

        std::cout << "Testing map " << NUMTESTS << " find operations\n";
        std::cout << "STL Map: " << stl_time << " seconds\n";
        std::cout << "C-STL Map: " << cstl_time << " seconds\n";
        std::cout << "C-STL is " << stl_time / cstl_time << "x faster\n\n";
    }
}
