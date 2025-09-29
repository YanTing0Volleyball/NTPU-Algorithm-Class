#include <iostream>
#include <vector>

int compareTimes = 0;

void swap(float& a, float& b) {
    float temp = a;
    a = b;
    b = temp;
    return;
}

int main()
{
    int n;
    float number;
    std::vector<float> numbers;
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        std::cin >> number;
        numbers.push_back(number);
    }

    for (int i = 1; i < n; i++) {
        for (int j = i; j >= 1; j--) {
            compareTimes++;
            if (numbers[j] < numbers[j - 1]) {
                swap(numbers[j], numbers[j - 1]);
            }
            else break;
        }
    }

    std::cout << numbers[0];
    for (int i = 1; i < n; i++) {
        std::cout << " " << numbers[i];
    }
    std::cout << std::endl << compareTimes;
}

