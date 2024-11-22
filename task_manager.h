//
// Created by rrivas on 22/11/2024.
//

#ifndef PROG3_2024_2_HEAP_TASK_MANAGER_H
#define PROG3_2024_2_HEAP_TASK_MANAGER_H

#include "heap.h"
#include <vector>
#include <functional>

class Task {
   // attributes

public:
   // constructor
   // friend ostream
};

class TaskManager {
    utec::heap<Task, std::vector<Task>, std::function<bool(Task, Task)>> task_list;
    std::function<bool(Task, Task)> comparable;
public:
    // Constructor del task
    explicit TaskManager(std::function<bool(Task, Task)> comparable): comparable(std::move(comparable)) {}
};

#endif //PROG3_2024_2_HEAP_TASK_MANAGER_H
