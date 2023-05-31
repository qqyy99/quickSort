
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void quickSort(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end) {
    if (begin == end || std::next(begin) == end)
        return;  // 容器为空或只有一个元素，无需排序

    auto pivot = *std::next(begin, std::distance(begin, end) / 2);
    auto left = begin;
    auto right = std::prev(end);

    while (left <= right) {
        while (*left < pivot)
            ++left;
        while (*right > pivot)
            --right;

        if (left <= right) {
            std::iter_swap(left, right);
            ++left;
            --right;
        }
    }

    quickSort(begin, std::make_move_iterator(right));
    quickSort(std::make_move_iterator(left), end);
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


