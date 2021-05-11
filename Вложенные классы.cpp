#include <iostream>
#include <string>
using namespace std;

class Image {
public:
    void GetImageInfo() {
        for (int i = 0; i < length; i++) {
            cout << "#" << i << " " << pixels[i].GetInfo() << endl; // вызов метода GetInfo для каждого объекта из
            // массива пикселей
        }
    }
private:
    class Pixel {
    public:
        Pixel(int r, int g, int b) {
            this->r = r;
            this->g = g;
            this->b = b;
        }

        string GetInfo() {
            return "Pixel: r=" + to_string(r) + " g=" + to_string(g) + " b=" + to_string(b);
        }
    private:
        int r;
        int g;
        int b;
    }; // служебный класс, который используется только Image

    static const int length = 5; // переменная должна быть static, т.к. у каждого объекта Image одина и таже длинна
    // массива pixels

    Pixel pixels[length] {
            Pixel(0, 4, 64),
            Pixel(23, 187, 63),
            Pixel(1, 25, 104),
            Pixel(89, 228, 112),
            Pixel(206, 52, 67)

    };
};

int main() {
    Image a;
    a.GetImageInfo();
    return 0;
}