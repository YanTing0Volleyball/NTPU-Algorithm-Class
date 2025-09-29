#include <iostream>
#include <vector>
#include <cfloat>


int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<float>> c(n + 1, std::vector<float>(n + 1, FLT_MAX));

    for (int i = 1; i <= n; i++) {
        c[i][i] = 0;
    }

    for (int k = 0; k < m; k++) {
        int i, j;
        float w;
        std::cin >> i >> j >> w;
        c[i][j] = w;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (c[i][j] > c[i][k] + c[k][j]) {
                    c[i][j] = c[i][k] + c[k][j];
                }
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < n; j++) {
            if (c[i][j] == FLT_MAX) {
                std::cout << "N ";
            }
            else {
                std::cout << c[i][j] << " ";
            }
        }
        if (c[i][n] == FLT_MAX) {
            std::cout << "N" << std::endl;
        }
        else {
            std::cout << c[i][n] << std::endl;
        }
    }

    return 0;
}
