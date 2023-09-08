#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cin >> str;

    std::string target = "hello";
    int targetIndex = 0;  // Índice da próxima letra a encontrar

    for (char c : str) {
        if (c == target[targetIndex]) {
            targetIndex++;
        }
        if (targetIndex == target.size()) {
            std::cout << "YES" << std::endl;
            return 0;
        }
    }

    std::cout << "NO" << std::endl;
    return 0;
}
