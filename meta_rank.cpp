#include <cstddef>

using namespace std;

template <typename T>
struct rank {
    static constexpr size_t value = 0u;
};

template <typename T, size_t N>
struct rank<T[N]> {
    static constexpr size_t value = 1u + rank<T>::value;
};

int main() {
    using array_t = int[10][20][30];
    constexpr unsigned my_value = rank<array_t>::value;
    static_assert(my_value == 3u);
    constexpr unsigned my_value2 = rank<int>::value;
    static_assert(my_value2 == 0u);
    return 0;
}