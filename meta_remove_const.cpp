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
struct remove_const {
    using type = T;
};

template <typename T>
struct remove_const<T const> {
    using type = T;
};

int main() {
    remove_const<int>::type my_num(0);
    my_num++;
    static_assert(is_same<decltype(my_num), int>::value);
    remove_const<const int>::type my_num2(5);
    my_num2++;
    static_assert(is_same<decltype(my_num2), int>::value);
    return 0;
}