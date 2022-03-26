#include <iostream>

template <typename T>
long double sum_values(T value) {
    return static_cast<long double>(value);
}


template <typename T, typename... Args>
long double sum_values(T value, Args...args) {
    return static_cast<long double>(value) + sum_values(args...);
}

int main()
{
    long double n;
    n = sum_values(5, 19, 20, 21, 15.5, 100.1243, 5000);

    std::cout << "n:" << n << "\nanother sum: " << sum_values('a',0.85,15);
}
