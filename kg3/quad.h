#ifndef QUAD_H
#define QUAD_H


class quad
{
private:
    float x;
    float y;
    float size;
    int flag;
public:
    quad(float _x, float _y, float _size, int f);
    quad();
    float getsize() const;
    float getx() const;
    float gety() const;
    int getf() const;
};

#endif // QUAD_H
