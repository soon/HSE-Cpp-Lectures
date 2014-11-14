#include <iostream>
#include <string>

std::string palindrome_first(const std::string& str)
{
    int left = 0;
    int max_len = 0;

    for(int i = 0; i < str.length(); ++i)
    {
        int len = 1;

        while(i - len >= 0 && i + len < str.length() && str.at(i - len) == str.at(i + len))
        {
            ++len;
        }

        --len;

        if(len > max_len)
        {
            left = i - len;
            max_len = len;
        }
    }

    return str.substr(left, max_len * 2 + 1);
}

std::string palindrome_second(const std::string& str)
{
    int left = 0;
    int max_len = 0;

    for(int i = 0; i < str.length(); ++i)
    {
        int len = 1;

        while(i - len >= 0 && i + len - 1 < str.length() && str.at(i - len) == str.at(i + len - 1))
        {
            ++len;
        }

        --len;

        if(len > max_len)
        {
            left = i - len;
            max_len = len;
        }
    }

    return str.substr(left, max_len * 2);
}

int main()
{
    std::string str;
    std::cin >> str;

    std::string first = palindrome_first(str);
    std::string second = palindrome_second(str);

    if(first.length() > second.length())
    {
        std::cout << first << std::endl;
    }
    else
    {
        std::cout << second << std::endl;
    }

    return 0;
}