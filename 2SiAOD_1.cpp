#include <iostream>
#include <cstdlib>

using namespace std;

int mask1(int d16) {
    const int mask = 0xf;
    int i = 1;
    int k = 1;
    while (true) {
        if (i > (d16 - i)) break;
        i *= 2;
        k++;
    }
    if (k <= 4) {
        return (d16 | (mas >> (4 - k)));
    } else {
        return (d16 | (mas << (k - 4)));
    }
}

int mask2(int d16_2) {
    const int mask2 = 0xffafb;
    return (d16_2 & mask2);
}

int multiply(int d16_3) {
    return (d16_3 « 9);
}

int divide(int d16_3) {
    return (d16_3 >> 9);
}

int mask(int d16, int n) {
    int i = 1;
    int mask = 1;
    int k = 0;
    while (true) {
        if (i > (d16 - i)) break;
        i *= 2;
        k++;
    }
    if (k + 1 == n) {
        while (k > 1) {
            mask << 1;
            mask++;
            k--;
        }
    } else {
        for (int j = k; j > 0; j--) {
            mask << 1;
            if (k != n)
                mask++;
        }
    }
    return (d16 & mask);
}

int main() {
    setlocale(0, "rus");
    const int d16 = 0x0005;
    int d16_2;
//cout « hex « d16«endl;
    cout << mask1(d16) << endl;
    cin >> d16_2;
    cout << mask2(d16_2) << endl;
    int d2;
    cin >> d2;
    cout << multiply(d2) << endl;
    cin >> d2;
    cout << divide(d2) << endl;
/*int n;
int digitN;
cin » hex»digitN;
cout « "бит, который требуется изменить на 0" « endl;
cin » n;
cout « hex « mask(digitN, n) « endl;*/
}