// timer.cpp
#include "time.h"

std::chrono::time_point<std::chrono::high_resolution_clock> start_time;

void initialize_timer() {
    start_time = std::chrono::high_resolution_clock::now();
}

bool is_timeout() {
    auto current_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = current_time - start_time;
    return elapsed.count() > 9.5;
}

