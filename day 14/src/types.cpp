#include "types.hh"

Vector2D operator*(const int scalar, const Vector2D& vector) {
    return {scalar*vector.x, scalar*vector.y};
}

Vector2D operator*(const Vector2D& vector, const int scalar) {
    return {scalar*vector.x, scalar*vector.y};
}

Vector2D operator+(const Vector2D& left, const Vector2D& right) {
    return {left.x + right.x, left.y + right.y};
}

Vector2D operator-(const Vector2D& left, const Vector2D& right) {
    return {left.x - right.x, left.y - right.y};
}

bool operator<(const Vector2D& left, const Vector2D& right) {
    return false;
}
