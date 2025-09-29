#include <iostream>
#include <vector>

int compareTimes = 0, divideTimes = 0;

void swap(float& a, float& b) {
    float temp = a;
    a = b;
    b = temp;
    return;
}

void quickSort(std::vector<float>& numbers, int left, int right) {
    if (left < right) {
        float pivotNumber = numbers[left];
        int i = left, j = left + 1;
        while (j <= right) {
            compareTimes++;
            if (numbers[j] < pivotNumber) {
                i++;
                swap(numbers[i], numbers[j]);
            }
            j++;
        }

        swap(numbers[left], numbers[i]);

        divideTimes++;
        quickSort(numbers, left, i - 1);
        quickSort(numbers, i + 1, right);
    }
    else return;
}

int main()
{
    int n, number;
    std::vector<float> numbers;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> number;
        numbers.push_back(number);
    }

    quickSort(numbers, 0, n - 1);

    std::cout << numbers[0];
    for (int i = 1; i < n; i++) {
        std::cout << " " << numbers[i];
    }

    std::cout << std::endl  << divideTimes << std::endl << compareTimes;

    return 0;
}
