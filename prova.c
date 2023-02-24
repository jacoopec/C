#include <iostream>

struct Point{
    int x;
    int y;
    int z;
};

int main(){
    Point triangle[3];

    triangle[0].x=0;
    triangle[0].y=0;
    triangle[1].x=1;
    triangle[1].y=1;
    triangle[2].x=0;
    triangle[2].y=2;

    std::cout << triangle << std::endl;
    Point* a = &triangle[2];
    std::cout << a-- << std::endl;
    std::cout << a->y << std::endl;
    std::cout << --a << std::endl;
    int d = 9;

    std::cout << d-- << std::endl;
    std::cout << --d << std::endl;
    std::cout << d << std::endl;
}