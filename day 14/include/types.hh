#ifndef _TYPES_HH_
#define _TYPES_HH_

enum class Parts { PART1, PART2 };

// Treat as const
// these are set at runtime based on whether it is the example or the real input
extern int MAX_WIDTH;
extern int MAX_HEIGHT;

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