#include <iostream>
#include <vector>
#include <cctype>
#include <cmath>
#include <algorithm>

int main()
{
    std::size_t n, m;
    std::cin >> n >> m;

    ++n;
    ++m;

    std::size_t k;
    std::cin >> k;

    std::vector<std::vector<bool>> has_short_path(n, std::vector<bool>(m, false));

    for(std::size_t i = 0; i < k; ++i)
    {
        std::size_t x, y;
        std::cin >> x >> y;

        has_short_path.at(x).at(y) = true;
    }

    std::vector<std::vector<double>> paths(n, std::vector<double>(m, 0));

    for(std::size_t i = 0; i < n; ++i)
    {
        paths.at(i).at(0) = i * 100;
    }

    for(std::size_t i = 0; i < m; ++i)
    {
        paths.at(0).at(i) = i * 100;
    }

    for(std::size_t i = 1; i < n; ++i)
    {
        for(std::size_t j = 1; j < m; ++j)
        {
            auto distance = std::min(paths.at(i - 1).at(j) + 100, paths.at(i).at(j - 1) + 100);

            if(has_short_path.at(i).at(j))
            {
                distance = std::min(distance, paths.at(i - 1).at(j - 1) + std::sqrt(2) * 100);
            }

            paths.at(i).at(j) = distance;
        }
    }

    std::cout << std::round(*paths.rbegin()->rbegin()) << std::endl;

    return 0;
}
