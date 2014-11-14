#include <iostream>
#include <cmath>
#include <algorithm>

int main()
{
    long long n, k;
    std::cin >> n >> k;

    long long a = std::ceil(std::log2(std::min(n, k)));
    long long b = n - std::pow(2, a);

    if(b > 0)
    {
        a += std::ceil(static_cast<double>(b) / k);
    }

    std::cout << a << std::endl;

    return 0;
}