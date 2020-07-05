//ABC triangle area
double area(Point A, Point B, Point C) {
    return (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.0;
}