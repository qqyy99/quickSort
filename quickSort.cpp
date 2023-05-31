
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void quickSort(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end) {
    if (begin == end || begin + 1 == end) {
        return;  // 容器为空或只有一个元素时，无需排序
    }

    auto middle = *(begin + std::distance(begin, end) / 2);  // 将中间位置的元素作为基准元素
    auto left = begin;
    auto right = end - 1;

    while (left < right) {
        while ( *left < middle) {
            left++;  // 从左边找到第一个大于等于基准元素的元素
        }

        while ( *right > middle) {
            right--;  // 从右边找到第一个小于等于基准元素的元素
        }

        if (left < right) {
            std::iter_swap(left, right);  // 交换找到的两个元素
            left++;
            right--;
        }
    }

    quickSort<T>(begin, left);    // 对左半部分递归排序
    quickSort<T>(left, end);  // 对右半部分递归排序
}

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    quickSort<int>(v.begin(), v.end());
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}


