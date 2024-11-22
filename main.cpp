#include <iostream>
#include "heap.h"
#include <queue>
#include <stack>

template<typename Type, typename ...OtherTypes>
struct is_same_to_any {
    constexpr static bool value = (std::is_same_v<Type, OtherTypes> || ...);
};
template<typename Type, typename ...OtherTypes>
constexpr bool is_same_to_any_v = is_same_to_any<Type, OtherTypes...>::value;

template<typename Type, typename ...OtherTypes>
struct is_same_to_all {
    constexpr static bool value = (std::is_same_v<Type, OtherTypes> && ...);
};
template<typename Type, typename ...OtherTypes>
constexpr bool is_same_to_all_v = is_same_to_all<Type, OtherTypes...>::value;

template <typename AdapterType,
        typename T = typename AdapterType::value_type,
        typename ContainerT = typename AdapterType::container_type>
void print_adapter(AdapterType adapter) {
    while (!adapter.empty()) {
        if constexpr (is_same_to_any_v<AdapterType, std::queue<T, ContainerT>> == true) {
            std::cout << adapter.front() << " ";
        }
        else if constexpr (is_same_to_any_v<
                AdapterType,
                std::stack<T, ContainerT>,
                std::priority_queue<T, ContainerT, typename AdapterType::value_compare>,
                utec::heap<T, ContainerT, typename AdapterType::value_compare>
                > == true){
            std::cout << adapter.top() << " ";
        }
        adapter.pop();
    }
    std::cout << std::endl;
}


void ejemplo_1() {
    std::vector v = {12, 1, 7, 15, 2, 20};
    utec::heap<int> h1(v);
    print_adapter(h1);
    std::cout << std::endl;



}

int main() {
    ejemplo_1();
    return 0;
}
