/**
 * @file benchmark.cpp
 * @author Alex M. Zhang
 * @brief Roughly estimates the speed of C-STL compared to regular STL
 * @date 2023-03-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#define NUM_VECTORS 1000
#define NUM_VECTOR_PUSHBACKS 100000

#define NUM_LISTS 100
#define NUM_LIST_PUSHBACKS 100000
#define NUM_MAPS 100
#define NUM_MAP_INSERTS 100000
#define NS_TO_S 1 / 1000000000.0

#include <chrono>
#include <iostream>
#include <list>
#include <map>
#include <random>
#include <vector>

#include "list.h"
#include "map.h"
#include "vector.h"

using hclock = std::chrono::high_resolution_clock;

int main() {
    hclock::time_point begin;
    auto rng = std::default_random_engine();

    vector *v = vector_construct();

    for (int i = 0; i < v->size; ++i) {
        printf("%ld ", v->data[i]);
    }

    // Test vector speed
    {
        std::cout << "Testing " << NUM_VECTORS << " vectors with "
                  << NUM_VECTOR_PUSHBACKS << " push back operations\n";
        begin = hclock::now();
        for (long a = 0; a < NUM_VECTORS; ++a) {
            std::vector<long> stl_vec;
            for (long i = 0; i < NUM_VECTOR_PUSHBACKS; ++i) {
                stl_vec.push_back(i);
            }
        }
        double stl_time = (hclock::now() - begin).count();
        std::cout << "STL Vector: " << stl_time * NS_TO_S << " seconds\n";

        begin = hclock::now();
        for (long a = 0; a < NUM_VECTORS; ++a) {
            vector *cstl_vec = vector_construct();
            for (long i = 0; i < NUM_VECTOR_PUSHBACKS; ++i) {
                tvar t = {.ld = i};
                vector_push_back(cstl_vec, t);
            }
            vector_destruct(cstl_vec);
        }
        double cstl_time = (hclock::now() - begin).count();
        std::cout << "C-STL Vector: " << cstl_time * NS_TO_S << " seconds\n";
        std::cout << "C-STL is " << stl_time / cstl_time << "x faster\n\n";
    }

    // Test list speed
    {
        std::cout << "Testing " << NUM_LISTS << " lists with "
                  << NUM_LIST_PUSHBACKS << " push back operations\n";
        begin = hclock::now();
        for (long a = 0; a < NUM_LISTS; ++a) {
            std::list<long> stl_list;
            for (long i = 0; i < NUM_LIST_PUSHBACKS; ++i) {
                stl_list.push_back(i);
            }
        }
        double stl_time = (hclock::now() - begin).count();
        std::cout << "STL List: " << stl_time * NS_TO_S << " seconds\n";

        begin = hclock::now();
        for (long a = 0; a < NUM_LISTS; ++a) {
            list *cstl_list = list_construct();
            for (long i = 0; i < NUM_LIST_PUSHBACKS; ++i) {
                tvar t = {.ld = i};
                list_push_back(cstl_list, t);
            }
            list_destruct(cstl_list);
        }
        double cstl_time = (hclock::now() - begin).count();
        std::cout << "C-STL List: " << cstl_time * NS_TO_S << " seconds\n";
        std::cout << "C-STL is " << stl_time / cstl_time << "x faster\n\n";
    }

    // Test map speed
    {
        std::cout << "Testing " << NUM_MAPS << " maps with " << NUM_MAP_INSERTS
                  << " insert operations\n";

        std::vector<long> rnums;
        for (long i = 0; i < NUM_MAP_INSERTS; ++i) {
            rnums.push_back(i);
        }
        std::shuffle(rnums.begin(), rnums.end(), rng);

        begin = hclock::now();
        for (long n = 0; n < NUM_MAPS; ++n) {
            std::map<long, long> stl_map;

            for (long i = 0; i < NUM_MAP_INSERTS; ++i) {
                long k = rnums[i];
                stl_map[k] = i;
            }
        }
        double stl_time = (hclock::now() - begin).count();
        std::cout << "STL Map: " << stl_time * NS_TO_S << " seconds\n";

        begin = hclock::now();
        for (long n = 0; n < NUM_MAPS; ++n) {
            map *cstl_map = map_construct();

            for (long i = 0; i < NUM_MAP_INSERTS; ++i) {
                tvar k = {.ld = rnums[i]};
                tvar v = {.ld = i};
                map_insert(cstl_map, map_node_construct(k, v));
            }

            map_destruct(cstl_map);
        }
        double cstl_time = (hclock::now() - begin).count();
        std::cout << "C-STL Map: " << cstl_time * NS_TO_S << " seconds\n";
        std::cout << "C-STL is " << stl_time / cstl_time << "x faster\n\n";
    }
}
