#include "quad.h"

quad::quad(){

}

quad::quad(float _x, float _y, float _size, int f)
{
    x = _x;
    y = _y;
    size = _size;
    flag = f;
}

float quad::getsize() const{
    return this->size;
}
float quad::getx() const{
    return this->x;
}
float quad::gety() const{
    return this->y;
}
int quad::getf() const{
    return this->flag;
}
