#include <iostream>
#include <string>
using namespace std;

void operator1() {
    int x = 0xF; // 10101
    int mask = 10;
    cout << x;
}

int main() {
    operator1();
    return 0;
}
    