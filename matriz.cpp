#include <iostream>
#include <vector>

void somarMatrizes(const std::vector<std::vector<int>>& A,
                   const std::vector<std::vector<int>>& B,
                   int m, int n) {
    std::vector<std::vector<int>> C(m, std::vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << C[i][j] << (j == n - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
}

int main() {
    int m, n;

    std::cin >> m >> n;

    std::vector<std::vector<int>> A(m, std::vector<int>(n));
    std::vector<std::vector<int>> B(m, std::vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> A[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> B[i][j];
        }
    }

    somarMatrizes(A, B, m, n);

    return 0;
}