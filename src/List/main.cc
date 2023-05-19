#include <iostream>

int main() {
    std::string str{"Hello world\n"};

    for (std::string::iterator it = str.begin(); it != str.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    return 0;
}