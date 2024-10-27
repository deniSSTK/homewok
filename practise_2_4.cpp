/**
* Done by:
 * Student Name: Denis Tkachenko
 * Student Group: 121
 * Prac 2.4
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

class MatrixAggregator {
public:
    static int productOfSequenceSums(const vector<vector<int>>& matrix) {
        int product = 1;
        for (const auto& row : matrix) {
            int sum = 0;
            for (int elem : row) {
                sum += elem;
            }
            product *= sum;
        }
        return product;
    }

    static int productOfNegativeElements(const vector<vector<int>>& matrix) {
        int product = 1;
        bool found = false;
        for (const auto& row : matrix) {
            for (int elem : row) {
                if (elem < 0) {
                    product *= elem;
                    found = true;
                }
            }
        }
        return found ? product : 0;
    }

    static int productOfMainDiagonal(const vector<vector<int>>& matrix) {
        int product = 1;
        for (size_t i = 0; i < matrix.size() && i < matrix[i].size(); ++i) {
            product *= matrix[i][i];
        }
        return product;
    }

    static double averageOfElementsLessThanOrEqualToP(const vector<vector<int>>& matrix, int P) {
        int sum = 0, count = 0;
        for (const auto& row : matrix) {
            for (int elem : row) {
                if (elem <= P) {
                    sum += elem;
                    ++count;
                }
            }
        }
        return count == 0 ? 0 : static_cast<double>(sum) / count;
    }

    static int differenceOfSumAboveAndBelowP(const vector<vector<int>>& matrix, int P) {
        int sumAboveP = 0, sumBelowP = 0;
        for (const auto& row : matrix) {
            for (int elem : row) {
                if (elem > P) {
                    sumAboveP += elem;
                } else if (elem < P) {
                    sumBelowP += elem;
                }
            }
        }
        return sumAboveP - sumBelowP;
    }

    static int sumOfSecondaryDiagonal(const vector<vector<int>>& matrix) {
        int sum = 0;
        for (size_t i = 0; i < matrix.size() && i < matrix[i].size(); ++i) {
            sum += matrix[i][matrix[i].size() - i - 1];
        }
        return sum;
    }

    static int sumOfMinimumsInColumns(const vector<vector<int>>& matrix) {
        int totalSum = 0;
        for (size_t j = 0; j < matrix[0].size(); ++j) {
            int minVal = numeric_limits<int>::max();
            for (size_t i = 0; i < matrix.size(); ++i) {
                if (matrix[i][j] < minVal) {
                    minVal = matrix[i][j];
                }
            }
            totalSum += minVal;
        }
        return totalSum;
    }
};

int main() {
    vector<vector<int>> matrix = {
            {1, -2, 3},
            {-4, 5, -6},
            {7, -8, 9}
    };
    int P = 4;

    cout << "Product of sequence sums: " << MatrixAggregator::productOfSequenceSums(matrix) << endl;
    cout << "Product of negative elements: " << MatrixAggregator::productOfNegativeElements(matrix) << endl;
    cout << "Product of main diagonal: " << MatrixAggregator::productOfMainDiagonal(matrix) << endl;
    cout << "Average of elements <= P: " << MatrixAggregator::averageOfElementsLessThanOrEqualToP(matrix, P) << endl;
    cout << "Difference of sum above and below P: " << MatrixAggregator::differenceOfSumAboveAndBelowP(matrix, P) << endl;
    cout << "Sum of secondary diagonal: " << MatrixAggregator::sumOfSecondaryDiagonal(matrix) << endl;
    cout << "Sum of minimums in columns: " << MatrixAggregator::sumOfMinimumsInColumns(matrix) << endl;

    return 0;
}
