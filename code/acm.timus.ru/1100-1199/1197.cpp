#include <iostream>
#include <cstddef>
#include <string>
#include <cmath>

std::size_t solve(const std::string& s)
{
    int col = s.at(0) - 'a' + 1;
    int row = s.at(1) - '0';

    int d_col = std::abs(9 - 2 * col) / 2;
    int d_row = std::abs(9 - 2 * row) / 2;

    int dist = d_col * d_col + d_row * d_row;

    if(dist <= 2)
    {
        return 8;
    }
    else if(dist <= 5)
    {
        return 6;
    }
    else if(dist <= 10)
    {
        return 4;
    }
    else if(dist <= 13)
    {
        return 3;
    }
    else
    {
        return 2;
    }
}


int main()
{
    std::size_t n;
    std::cin >> n;

    for(std::size_t i = 0; i < n; ++i)
    {
        std::string str;
        std::cin >> str;

        std::cout << solve(str) << std::endl;
    }

    return 0;
}