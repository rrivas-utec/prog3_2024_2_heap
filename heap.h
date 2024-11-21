//
// Created by rrivas on 21/11/2024.
//

#ifndef PROG3_2024_2_HEAP_HEAP_H
#define PROG3_2024_2_HEAP_HEAP_H

#include <functional>
#include <vector>

namespace utec {
    template <typename T, template<typename...> typename TContainer = std::vector, typename Comparable = std::less<T>>
    class heap {
        TContainer<T> cnt;
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
        bool get_selected_child_index(size_t parent_index) {
            auto left_index = get_left_child(parent_index);
            if (has_right_child(parent_index)) {
                auto right_index = get_right_child(parent_index);
                if (cmp(cnt[right_index], cnt[left_index]))
//                if (std::less<T>(cnt[right_index], cnt[left_index]))
//                if (cnt[right_index] < cnt[left_index])
                    return left_index;
                else
                    return right_index;
//                if (comparable(cnt[right_index], cnt[left_index]))
//                    return right_index < cnt.size();
            }
        }
    };
}

#endif //PROG3_2024_2_HEAP_HEAP_H
