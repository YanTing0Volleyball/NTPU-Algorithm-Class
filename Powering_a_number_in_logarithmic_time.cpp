#include <iostream>

int multiplyTimes = 0;

int power(int a, int n) {
    if (n == 1) return a;
    if (n == 0) return 1;

    if (n % 2 == 0) {
        multiplyTimes++;
        int p = power(a, n / 2);
        return p * p;
    }
    else {
        multiplyTimes += 2;
        int p = power(a, n / 2);
        return p * p * a;
    }
}

int main()
{
    int a, n;
    std::cin >> a >> n;

    int p = power(a, n);
    std::cout << p << std::endl << multiplyTimes;

    return 0;
}
