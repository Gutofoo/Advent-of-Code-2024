#ifndef _TYPES_HH_
#define _TYPES_HH_

enum class Parts { PART1, PART2 };

const int MAX_WIDTH = 101;
const int MAX_HEIGHT = 103;
// const int MAX_WIDTH = 11;
// const int MAX_HEIGHT = 7;

struct Vector2D {
    int x;
    int y;
};

using Position = Vector2D;
using Velocity = Vector2D;

Vector2D operator*(const int scalar, const Vector2D& vector);

Vector2D operator*(const Vector2D& vector, const int scalar);

Vector2D operator+(const Vector2D& left, const Vector2D& right);

Vector2D operator-(const Vector2D& left, const Vector2D& right);

#endif