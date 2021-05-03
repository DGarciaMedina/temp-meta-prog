using namespace std;


template<class T, class U>
struct is_same {
    static constexpr bool value = false;
};
 
template<class T>
struct is_same<T, T> {
    static constexpr bool value = true;
};

template <typename T>
struct remove_volatile {
    using type = T;
};

template <typename T>
struct remove_volatile<T const> {
    using type = T;
};

int main() {
    remove_volatile<int>::type my_num(0);
    my_num++;
    static_assert(is_same<decltype(my_num), int>::value);
    remove_volatile<const int>::type my_num2(5);
    my_num2++;
    static_assert(is_same<decltype(my_num2), int>::value);
    return 0;
}