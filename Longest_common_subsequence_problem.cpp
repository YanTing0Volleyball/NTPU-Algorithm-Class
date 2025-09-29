#include <iostream>
#include <vector>

int max(int a, int b) {
    if (a >= b) return a;
    else return b;
}

struct node {
    node(int l, char d) {
        maxLength = l;
        direction = d;
    }
    node() {
        maxLength = 0;
        direction = 'u';
    }

    int maxLength;
    char direction;
};

int main()
{
    std::string nope;
    std::cin >> nope;

    int m, n;
    std::cin >> m >> n;
    std::vector<char> x(m);
    std::vector<char> y(n);
    for (int i = 0; i < m; i++) {
        std::cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> y[i];
    }

    std::vector<std::vector<node>> lcsmp(m+1, std::vector<node>(n + 1, node()));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) lcsmp[i][j] = node(lcsmp[i - 1][j - 1].maxLength + 1, 's');
            else if (lcsmp[i][j - 1].maxLength > lcsmp[i - 1][j].maxLength) lcsmp[i][j] = node(lcsmp[i][j - 1].maxLength, 'l');
            else lcsmp[i][j] = node(lcsmp[i - 1][j].maxLength, 'u');
        }
    }

    int longestLength = lcsmp[m][n].maxLength;

    std::cout << longestLength << std::endl;

    std::vector<char> lcs;
    
    int i = m, j = n;
    while (i > 0 && j > 0) {
        switch (lcsmp[i][j].direction) {
        case 'u':
            i--;
            break;
        case 'l':
            j--;
            break;
        case 's':
            lcs.push_back(x[i - 1]);
            i--;
            j--;
            break;
        }
    }

    std::cout << lcs[longestLength - 1];
    for (int i = longestLength - 2; i >= 0; i--) {
        std::cout << " " << lcs[i];
    }

    return 0;
}
