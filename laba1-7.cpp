/**
* Done by:
 * Student Name: Denis Tkachenko
 * Student Group: 121
 * Lab 1.7
 */

#include <iostream>

static int nA = 0;
static int nB = 0;

void block1() {
    static int nL = 0;
    int nS = 0;
    for (int i = 0; i < 5; i++) {
        static int iA = 0;
        int iB = 0;
        iA++;
        iB++;
        nL++;
        nS++;
        std::cout << "block1: iA = " << iA << ", iB = " << iB << ", nL = " << nL << ", nS = " << nS << std::endl;
    }
}

void block2() {
    int nC = 60;
    std::cout << "block2: nA = " << nA << ", nC = " << nC << std::endl;
}

int main() {
    std::cout << "Main: nA = " << nA << ", nB = " << nB << std::endl;
    block1();
    nB = 20;
    std::cout << "Main after block1: nB = " << nB << std::endl;
    block2();

    int* pI = new int(10);
    int* pW = pI;
    delete pW;
    pW = nullptr;

    return 0;
}
