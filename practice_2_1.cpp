/**
* Done by:
 * Student Name: Denis Tkachenko
 * Student Group: 121
 * Prac 2.1
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

void findMinimumValue(const vector<vector<int>>& A) {
    int minVal = A[0][0];
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < A[i].size(); ++j) {
            if (A[i][j] < minVal) {
                minVal = A[i][j];
            }
        }
    }
    cout << "Minimum value: " << minVal << endl;
}

void findMaximumAbsoluteValue(const vector<vector<int>>& A) {
    int maxAbsVal = numeric_limits<int>::min();
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < A[i].size(); ++j) {
            maxAbsVal = max(maxAbsVal, abs(A[i][j]));
        }
    }
    cout << "Maximum absolute value: " << maxAbsVal << endl;
}

void findIndicesOfMinimumValue(const vector<vector<int>>& A) {
    int minVal = A[0][0];
    vector<pair<int, int>> indices;
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < A[i].size(); ++j) {
            if (A[i][j] < minVal) {
                minVal = A[i][j];
                indices.clear();
                indices.emplace_back(i, j);
            } else if (A[i][j] == minVal) {
                indices.emplace_back(i, j);
            }
        }
    }
    cout << "Indices of minimum value: ";
    for (const auto& index : indices) {
        cout << "(" << index.first << ", " << index.second << ") ";
    }
    cout << endl;
}

void findMaximumNegativeValue(const vector<vector<int>>& A) {
    int maxNegVal = numeric_limits<int>::min();
    bool found = false;
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < A[i].size(); ++j) {
            if (A[i][j] < 0 && A[i][j] > maxNegVal) {
                maxNegVal = A[i][j];
                found = true;
            }
        }
    }
    if (found) {
        cout << "Maximum negative value: " << maxNegVal << endl;
    } else {
        cout << "No negative values found." << endl;
    }
}

void findMinimumPositiveValue(const vector<vector<int>>& A) {
    int minPosVal = numeric_limits<int>::max();
    bool found = false;
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < A[i].size(); ++j) {
            if (A[i][j] > 0 && A[i][j] < minPosVal) {
                minPosVal = A[i][j];
                found = true;
            }
        }
    }
    if (found) {
        cout << "Minimum positive value: " << minPosVal << endl;
    } else {
        cout << "No positive values found." << endl;
    }
}

void findIndexOfMinimumOnSecondaryDiagonal(const vector<vector<int>>& A) {
    int minVal = numeric_limits<int>::max();
    pair<int, int> index = {-1, -1};
    for (size_t i = 0; i < A.size(); ++i) {
        if (i < A[i].size()) {
            if (A[i][A.size() - 1 - i] < minVal) {
                minVal = A[i][A.size() - 1 - i];
                index = {i, A.size() - 1 - i};
            }
        }
    }
    if (index.first != -1) {
        cout << "Index of minimum value on secondary diagonal: (" << index.first << ", " << index.second << ")" << endl;
    } else {
        cout << "No elements found on secondary diagonal." << endl;
    }
}

void findLastIndexOfR(const vector<vector<int>>& A, int R) {
    pair<int, int> index = {-1, -1};
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < A[i].size(); ++j) {
            if (A[i][j] == R) {
                index = {i, j};
            }
        }
    }
    if (index.first != -1) {
        cout << "Last index of " << R << ": (" << index.first << ", " << index.second << ")" << endl;
    } else {
        cout << R << " not found in the matrix." << endl;
    }
}

int main() {
    vector<vector<int>> A = {{1, 2, 3}, {4, -5, 6}, {7, 8, -9}};
    findMinimumValue(A);
    findMaximumAbsoluteValue(A);
    findIndicesOfMinimumValue(A);
    findMaximumNegativeValue(A);
    findMinimumPositiveValue(A);
    findIndexOfMinimumOnSecondaryDiagonal(A);
    findLastIndexOfR(A, -5);
    return 0;
}
