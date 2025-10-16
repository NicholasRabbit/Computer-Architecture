#line 145 "bits.c"
int bitXor(int x, int y) {
  return ~(~x & ~y) & ~(x & y);
#line 1 "<command-line>"
#include "/usr/include/stdc-predef.h"
#line 147 "bits.c"
}
#line 154
int tmin(void) {

  return 1 << 31;

}
#line 167
int isTmax(int x) {
  int map=  x + 0x01;
  int res=  ~(map + x);
  return !res &( !!map);
}
#line 180
int allOddBits(int x) {
  int y=  0xAA + 0xAA << 8;
  y = y +( y << 16);
  x = x & y;
  x = x ^ y;
  return !x;

}
#line 195
int negate(int x) {
  return ~x + 1;
}
#line 208
int isAsciiDigit(int x) {
  return 2;
}
#line 218
int conditional(int x, int y, int z) {
  return 2;
}
#line 228
int isLessOrEqual(int x, int y) {
  return 2;
}
#line 240
int logicalNeg(int x) {
  return 2;
}
#line 255
int howManyBits(int x) {
  return 0;
}
#line 270
unsigned floatScale2(unsigned uf) {
  return 2;
}
#line 285
int floatFloat2Int(unsigned uf) {
  return 2;
}
#line 301
unsigned floatPower2(int x) {
    return 2;
}
