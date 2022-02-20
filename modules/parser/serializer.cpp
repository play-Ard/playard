#include "../ui/UI.h"
#include <iostream>

int main(void)
{
    Point point1(3, 5);
    Point point2(5, 8);
    Point point3(2, 10);
    Layout layout;

    Triangle triangle;
    triangle.setLayout(&layout);
    triangle.setPoints(&point1, &point2, &point3);

    FILE* file;
    fopen_s(&file, "db.dat", "w+");
    if (file == NULL) {
        std::cout << "File is null";
        return 1;
    }

    return 0;
}
