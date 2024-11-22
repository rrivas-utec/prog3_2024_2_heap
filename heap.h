//
// Created by rrivas on 21/11/2024.
//

#ifndef PROG3_2024_2_HEAP_HEAP_H
#define PROG3_2024_2_HEAP_HEAP_H

#include <functional>
#include <vector>

namespace utec {
    template <
            typename T,
            typename TContainer = std::vector<T>,
            typename Comparable = std::less<T>>
    class heap {
        TContainer cnt;
        Comparable cmp;
        size_t get_left_child(size_t parent_index) { return parent_index * 2 + 1; }
        size_t get_right_child(size_t parent_index) { return parent_index  * 2 + 2; }
        size_t get_parent(size_t index) { return (index-1)/2; }

        bool has_children(size_t parent_index) {
            auto left_index = get_left_child(parent_index);
            return left_index < cnt.size();
        }

        bool has_right_child(size_t parent_index) {
            auto right_index = get_right_child(parent_index);
            return right_index < cnt.size();
        }
        size_t get_selected_child_index(size_t parent_index) {
            auto left_index = get_left_child(parent_index);
            if (has_right_child(parent_index)) {
                auto right_index = get_right_child(parent_index);
                if (cmp(cnt[left_index], cnt[right_index]))
                    return right_index;
                else
                    return left_index;
            }
            return left_index;
        }
        bool is_root(size_t index) { return index == 0; }

        void percolate_up(size_t index) {
            // Condiciones básicas
            if (is_root(index)) return;
            auto parent_index = get_parent(index);
            if (cmp(cnt[index], cnt[parent_index])) return;
            std::swap(cnt[index], cnt[parent_index]);
            // Condicion recursiva
            percolate_up(parent_index);
        }
        void percolate_down(size_t index) {
            // condiciones básicas
            if (!has_children(index)) return;
            auto selected_child_index = get_selected_child_index(index);
            if (cmp(cnt[selected_child_index], cnt[index])) return;
            std::swap(cnt[selected_child_index], cnt[index]);
            // condicion recursiva
            percolate_down(selected_child_index);
        }
        void heapify(size_t index) {
            auto current_index = get_parent(index);
            while (current_index >= 0) {
                percolate_down(current_index);
                if (current_index == 0) break;
                --current_index;
            }
        }
    public:
        heap() = default;
        explicit heap(const TContainer& cnt): cnt(cnt) {
            heapify(cnt.size() - 1);
        }
        explicit heap(const TContainer& cnt, Comparable cmp): cnt(cnt), cmp(cmp) {
            heapify(cnt.size() - 1);
        }

        using value_compare = Comparable;
        using value_type = T;
        using container_type = TContainer;

        T top() { return cnt.front(); }
        size_t size() { return cnt.size(); }

        template<typename ...Args>
        void emplace(Args... args) {
            cnt.emplace_back(args...);
            percolate_up(cnt.size() - 1);
        }

        void push(T value) {
            cnt.push_back(value);
            percolate_up(cnt.size() - 1);
        }
        void pop() {
            std::swap(cnt.front(), cnt.back());
            cnt.pop_back();
            percolate_down(0);
        }
        bool empty() { return cnt.size() == 0; }
    };
}

#endif //PROG3_2024_2_HEAP_HEAP_H
