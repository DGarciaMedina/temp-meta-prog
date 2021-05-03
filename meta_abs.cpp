#include <limits>

using namespace std;

template <int N>
struct abs {
    static_assert( N != numeric_limits<int>::min() );
    static constexpr int value = (N < 0 ? -N : N);
};

int main() {
    constexpr int n = -33;
    constexpr int my_value = abs<n>::value;
    static_assert(my_value == 33);
    return 0;
}