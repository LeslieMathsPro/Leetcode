#include <iostream>

int main() {
    double d;
    while (std::cin >> d) {
        std::cout << static_cast<int>(d + 0.5) << std::endl;
    }
    return 0;
}