#include <iostream>
#include <vector>

int main()
{
    int n , k;
    std::cin >> n >> k;
    std::vector<int> a_list(n);
    std::vector<int>b_list(n);
    std::vector<int>c_list(k + 1);
    
    for (int i = 0; i < n; i++) {
        std::cin >> a_list[i];
    }

    //Add Cout To c_list
    for (int i = 0; i < n; i++) {
        c_list[a_list[i]]++;
    }

    //Accumulate c_list
    for (int i = 1; i <= k; i++) {
        c_list[i] += c_list[i - 1];
    }
    
    //Sort To b_list
    for (int i = n - 1; i >= 0; i--) {
        c_list[a_list[i]]--;
        b_list[c_list[a_list[i]]] = a_list[i];
    }

    //Output
    std::cout << b_list[0];
    for (int i = 1; i < n; i++) {
        std::cout << " " << b_list[i];
    }
    std::cout << std::endl << c_list[0];
    for (int i = 1; i <= k; i++) {
        std::cout << " " << c_list[i];
    }

    return 0;
}

