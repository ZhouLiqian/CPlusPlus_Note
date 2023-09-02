#include <iostream>
#include <vector>

int main() {
    std::vector<int> dynamicArray; // 使用 std::vector 存储动态数组

    int input;
    while (std::cin >> input) {
        dynamicArray.push_back(input); // 将输入添加到动态数组中
    }

    // 现在 dynamicArray 包含了所有用户输入的整数

    // 可以遍历 dynamicArray 并处理数据
    for (int number : dynamicArray) {
        std::cout << number << " ";
    }

    return 0;
}
