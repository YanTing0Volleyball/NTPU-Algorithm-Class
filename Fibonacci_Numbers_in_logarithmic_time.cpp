#include <iostream>
#include <vector>

int matrixMultiplyTimes = 0;

std::vector<std::vector<int>> operator* (std::vector<std::vector<int>>& a, std::vector<std::vector<int>>& b) {
    std::vector<std::vector<int>> result(a);
    int sum;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            sum = 0;
            for (int d = 0; d < a[0].size(); d++) {
                sum += a[i][d] * b[d][j];
            }
            result[i][j] = sum;
        }
    }

    return result;
}

std::vector<std::vector<int>> power(std::vector<std::vector<int>>& matrix, int n) {
    if (n == 1) {
        return matrix;
    }

    std::vector<std::vector<int>> pMatrix;
    if (n % 2 == 0) {
        pMatrix = power(matrix, n / 2);
        matrixMultiplyTimes++;
        pMatrix = pMatrix * pMatrix;
        return pMatrix;
    }
    else {
        pMatrix = power(matrix, (n - 1) / 2);
        matrixMultiplyTimes += 2;
        pMatrix = pMatrix * pMatrix;
        pMatrix = pMatrix * matrix;
        return pMatrix;
    }
}


int main()
{
    int k, m, number;
    std::vector<int> aNumbers;
    std::vector<int> bNumbers;
    
    std::cin >> k;

    for (int i = 0; i < k; i++) {
        std::cin >> number;
        aNumbers.push_back(number);
    }

    for (int i = 0; i < k; i++) {
        std::cin >> number;
        bNumbers.push_back(number);
    }

    std::cin >> m;

    std::vector<std::vector<int>> lattenMatrix;
    std::vector<int> temp;
    lattenMatrix.push_back(bNumbers);
    for (int i = 1; i < k; i++) {
        temp.clear();
        for (int j = 0; j < i - 1; j++) temp.push_back(0);
        temp.push_back(1);
        for (int j = 0; j < k - i; j++) temp.push_back(0);
        lattenMatrix.push_back(temp);
    }

    lattenMatrix = power(lattenMatrix, m - k);

    int Fm = 0;
    for (int i = 0; i < k; i++) {
        Fm += aNumbers[k - 1 - i] * lattenMatrix[0][i];
    }

    std::cout << Fm << std::endl << matrixMultiplyTimes;

    return 0;
}
