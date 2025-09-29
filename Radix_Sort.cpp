#include <iostream>
#include <vector>
#include <math.h>

std::vector<int> countingSort(std::vector<int>& a_list, int n, int digit) {
    std::vector<int> b_list(n);
    std::vector<int> c_list(10);
    int digitCalculator = std::pow(10, digit);

    //Add Count To c_list
    for (int i = 0; i < n; i++) {
        c_list[a_list[i] / digitCalculator % 10]++;
    }

    //Accumulate c_list
    for (int i = 1; i < 10; i++) {
        c_list[i] += c_list[i - 1];
    }

    //Counting Sort To b_list
    for (int i = n - 1; i >= 0; i--) {
        c_list[a_list[i] / digitCalculator % 10]--;
        b_list[c_list[a_list[i] / digitCalculator % 10]] = a_list[i];
    }

    //Output
    a_list = b_list;
    return c_list;
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a_list(n);
    std::vector<std::vector<int>> c_lists(k);

    for (int i = 0; i < n; i++) {
        std::cin >> a_list[i];
    }

    //Counting Sort By Digits
    for (int i = 0; i < k; i++) {
        c_lists[i] = countingSort(a_list, n, i);
    }

    //Output
    std::cout << a_list[0];
    for (int i = 1; i < n; i++) {
        std::cout << " " << a_list[i];
    }
    
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += c_lists[i][0];
    }
    std::cout << std::endl << sum;
    
    for (int i = 1; i < 10; i++) {
        sum = 0;
        for (int j = 0; j < k; j++) {
            sum += c_lists[j][i];
        }
        std::cout << " " << sum;
    }

    return 0;
}
