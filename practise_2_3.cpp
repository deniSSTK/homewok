/**
* Done by:
 * Student Name: Denis Tkachenko
 * Student Group: 121
 * Prac 2.3
 */

#include <iostream>
#include <vector>
#include <algorithm>

class SequenceSorter {
public:
    void filterEvenAndSort(std::vector<int>& A) {
        std::vector<int> B;
        for (int value : A) {
            if (value % 2 == 0) {
                B.push_back(value);
            }
        }
        bubbleSort(B);
        for (int b : B) std::cout << b << " ";
        std::cout << "\n";
    }

    void filterNegativeAndSortDesc(std::vector<int>& A) {
        std::vector<int> B;
        for (int value : A) {
            if (value < 0) {
                B.push_back(value);
            }
        }
        selectionSortDesc(B);
        for (int b : B) std::cout << b << " ";
        std::cout << "\n";
    }

    void sortEachSequence(std::vector<std::vector<int>>& A) {
        for (auto& row : A) {
            bubbleSort(row);
        }
        for (const auto& row : A) {
            for (int val : row) std::cout << val << " ";
            std::cout << "\n";
        }
    }

    void maxElementsAndSortDesc(std::vector<std::vector<int>>& A) {
        std::vector<int> B;
        for (const auto& row : A) {
            B.push_back(*std::max_element(row.begin(), row.end()));
        }
        selectionSortDesc(B);
        for (int b : B) std::cout << b << " ";
        std::cout << "\n";
    }

    void sortMainDiagonal(std::vector<std::vector<int>>& A) {
        int m = A.size();
        std::vector<int> diag;
        for (int i = 0; i < m; ++i) {
            diag.push_back(A[i][i]);
        }
        selectionSort(diag);
        for (int i = 0; i < m; ++i) {
            A[i][i] = diag[i];
        }
        for (const auto& row : A) {
            for (int val : row) std::cout << val << " ";
            std::cout << "\n";
        }
    }

    void sortColumnsDesc(std::vector<std::vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        for (int col = 0; col < n; ++col) {
            std::vector<int> column;
            for (int row = 0; row < m; ++row) {
                column.push_back(A[row][col]);
            }
            bubbleSortDesc(column);
            for (int row = 0; row < m; ++row) {
                A[row][col] = column[row];
            }
        }
        for (const auto& row : A) {
            for (int val : row) std::cout << val << " ";
            std::cout << "\n";
        }
    }

    void minElementsSumAndSort(std::vector<std::vector<int>>& A) {
        std::vector<int> B;
        int n = A[0].size();
        for (int col = 0; col < n; ++col) {
            int minElement = A[0][col];
            for (const auto& row : A) {
                minElement = std::min(minElement, row[col]);
            }
            B.push_back(minElement);
        }
        selectionSort(B);
        for (int b : B) std::cout << b << " ";
        std::cout << "\n";
    }

private:
    void bubbleSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    void bubbleSortDesc(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] < arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    void selectionSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            int minIdx = i;
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            std::swap(arr[i], arr[minIdx]);
        }
    }

    void selectionSortDesc(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            int maxIdx = i;
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] > arr[maxIdx]) {
                    maxIdx = j;
                }
            }
            std::swap(arr[i], arr[maxIdx]);
        }
    }
};

int main() {
    SequenceSorter sorter;
    std::vector<int> A1 = {1, 4, 0, -2, 5, 9, -9, 10, -12, 3};
    sorter.filterEvenAndSort(A1);

    std::vector<int> A2 = {1, 4, 0, -2, 5, 9, -9, 10, -12, 3};
    sorter.filterNegativeAndSortDesc(A2);

    std::vector<std::vector<int>> A3 = {{1, 4, -2}, {0, -9, 10}, {3, 5, -12}};
    sorter.sortEachSequence(A3);

    std::vector<std::vector<int>> A4 = {{1, 4, -2}, {0, -9, 10}, {3, 5, -12}};
    sorter.maxElementsAndSortDesc(A4);

    std::vector<std::vector<int>> A5 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    sorter.sortMainDiagonal(A5);

    std::vector<std::vector<int>> A6 = {{3, 4, 5}, {1, 0, -1}, {6, -2, 9}};
    sorter.sortColumnsDesc(A6);

    std::vector<std::vector<int>> A7 = {{3, -1, 5}, {7, 0, -2}, {-6, 1, 9}};
    sorter.minElementsSumAndSort(A7);

    return 0;
}
