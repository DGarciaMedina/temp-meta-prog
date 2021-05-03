using namespace std;

template <unsigned N, unsigned M>
struct gcd {
    static constexpr unsigned value = gcd<M, N % M>::value;
};

template <unsigned N>
struct gcd<N,0> {
    static_assert( N != 0 );
    static constexpr unsigned value = N;
};

int main() {
    constexpr unsigned n = 8;
    constexpr unsigned m = 12;
    constexpr unsigned my_value = gcd<n, m>::value;
    static_assert(my_value == 4);
    return 0;
}