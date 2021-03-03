#include <iostream>

using namespace std;

int main() {
    const int ci = 1;
    const int *const cpc = &ci;
    cout << cpc << endl << *cpc;
    return 0;
}