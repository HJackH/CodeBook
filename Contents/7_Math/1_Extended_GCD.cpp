// ax + by = c
int extgcd(int a, int b, int c, int &x, int &y) {
  if (b == 0) {
    x = c / a;
    y = 0;
    return a;
  }
  int d = extgcd(b, a % b, c, x, y);
  int tmp = x;
  x = y;
  y = tmp - (a / b) * y;
  return d;
}