/**
* Done by:
 * Student Name: Denis Tkachenko
 * Student Group: 121
 * Prac 2.2
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class MatrixTransformer {
public:
    void replaceElementsWithAverage(std::vector<int>& B, const std::vector<int>& A) {
        double avgA = static_cast<double>(std::accumulate(A.begin(), A.end(), 0)) / A.size();
        for (int& b : B) {
            if (std::find(A.begin(), A.end(), b) != A.end()) {
                b = avgA;
            }
        }
    }

    void replaceMinInRow(std::vector<std::vector<int>>& A) {
        for (auto& row : A) {
            int sumRow = std::accumulate(row.begin(), row.end(), 0);
            int minVal = *std::min_element(row.begin(), row.end());
            for (int& val : row) {
                if (val == minVal) {
                    val = sumRow;
                }
            }
        }
    }

    void replaceElementsWithProduct(std::vector<int>& A, const std::vector<int>& B) {
        int productB = std::accumulate(B.begin(), B.end(), 1, std::multiplies<int>());
        for (int& a : A) {
            if (std::find(B.begin(), B.end(), a) != B.end()) {
                a = productB;
            }
        }
    }

    void replaceMaxInColumn(std::vector<std::vector<int>>& A) {
        int m = A.size();
        for (int col = 0; col < m; ++col) {
            int product = 1;
            int maxVal = A[0][col];
            for (int row = 0; row < m; ++row) {
                product *= A[row][col];
                maxVal = std::max(maxVal, A[row][col]);
            }
            for (int row = 0; row < m; ++row) {
                if (A[row][col] == maxVal) {
                    A[row][col] = product;
                }
            }
        }
    }

    void replaceNegativeWithMaxB(std::vector<int>& A, const std::vector<int>& B) {
        int maxB = *std::max_element(B.begin(), B.end());
        for (int& a : A) {
            if (a < 0) {
                a = maxB;
            }
        }
    }

    void replaceNegativeWithPositiveSum(std::vector<std::vector<int>>& A) {
        for (auto& row : A) {
            int sumPositive = 0;
            for (int val : row) {
                if (val > 0) sumPositive += val;
            }
            for (int& val : row) {
                if (val < 0) {
                    val = sumPositive;
                }
            }
        }
    }

    void replacePositiveWithMinA(std::vector<int>& B, const std::vector<int>& A) {
        int minA = *std::min_element(A.begin(), A.end());
        for (int& b : B) {
            if (b > 0) {
                b = minA;
            }
        }
    }
};

int main() {
    MatrixTransformer transformer;

    std::vector<int> A1 = {2, 4, 6};
    std::vector<int> B1 = {5, 2, 3, 4, 8};
    transformer.replaceElementsWithAverage(B1, A1);
    for (int b : B1) std::cout << b << " ";
    std::cout << "\n";

    std::vector<std::vector<int>> A2 = {{1, 2, 3}, {4, 1, 6}, {7, 8, 1}};
    transformer.replaceMinInRow(A2);
    for (const auto& row : A2) {
        for (int val : row) std::cout << val << " ";
        std::cout << "\n";
    }

    std::vector<int> A3 = {1, 5, 2, 3};
    std::vector<int> B3 = {2, 3};
    transformer.replaceElementsWithProduct(A3, B3);
    for (int a : A3) std::cout << a << " ";
    std::cout << "\n";

    std::vector<std::vector<int>> A4 = {{1, 2}, {3, 4}};
    transformer.replaceMaxInColumn(A4);
    for (const auto& row : A4) {
        for (int val : row) std::cout << val << " ";
        std::cout << "\n";
    }

    std::vector<int> A5 = {-1, 5, -3, 2};
    std::vector<int> B5 = {7, 3, 4};
    transformer.replaceNegativeWithMaxB(A5, B5);
    for (int a : A5) std::cout << a << " ";
    std::cout << "\n";

    std::vector<std::vector<int>> A6 = {{-1, 2, -3}, {4, -5, 6}};
    transformer.replaceNegativeWithPositiveSum(A6);
    for (const auto& row : A6) {
        for (int val : row) std::cout << val << " ";
        std::cout << "\n";
    }

    std::vector<int> A7 = {3, -2, 1};
    std::vector<int> B7 = {5, -3, 6};
    transformer.replacePositiveWithMinA(B7, A7);
    for (int b : B7) std::cout << b << " ";
    std::cout << "\n";

    return 0;
}
