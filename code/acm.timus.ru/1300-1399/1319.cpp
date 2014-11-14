#include <iostream>
#include <cstddef>
#include <cmath>

std::size_t generate_first_number(std::size_t n)
{
    // Lazy caterer's sequence
    return (std::pow(n - 1, 2) + n + 1) / 2;
}

void print_answer(std::size_t n)
{
    std::size_t first = generate_first_number(n);

    for(std::size_t i = 0; i < n; ++i)
    {
        std::size_t prev = first;

        for(std::size_t d = n - i; d < n; ++d)
        {
            std::cout << prev << ' ';
            prev -= d;
//            std::cout << d << ' ';
        }

        for(std::size_t d = n - 1; d > i; --d)
        {
            std::cout << prev << ' ';
            prev -= d;
//            std::cout << d << ' ';
        }

        std::cout << prev << std::endl;
        first += n - i;
    }
}

int main()
{
    std::size_t n;
    std::cin >> n;

    print_answer(n);

    return 0;
}