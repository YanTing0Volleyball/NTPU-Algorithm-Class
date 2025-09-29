#include <iostream>

int main()
{
    int p, m, a, b, k;
    std::cin >> p >> m >> a >> b >> k;
    std::cout << (a * k + b) % p % m;

    return 0;
}
