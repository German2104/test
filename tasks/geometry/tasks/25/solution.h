#pragma once

#include <stdio.h>

// INITIAL VALUES
const int INITIAL_VLUAES_I = -8;
const int INITIAL_VLUAES_J = -5;
const int INITIAL_VLUAES_L = 12;

// AUXILIARY VARIABLES
const int MOD_30 = 30;
const int TWO = 2;
const int Mod_20 = 20;
const int MAX_ITERETIONS = 50;
const int X_1 = -10;
const int Y_1 = 10;

typedef struct {
  int x;
  int y;
} Point;

int Pow(int value, int degree) {
  if (degree == 0) {
    return 1;
  } else {
    int result = 1;
    for (int i = 0; i < degree; ++i) {
      result *= value;
    }
    return result;
  }
}

int Abs(int a) {
  return (a >= 0) ? a : -a;
}

int Mod(int value_1, int value_2) {
  return Abs(value_1 % value_2);
}

int Sign(int num) {
  if (num > 0) {
    return 1;
  } else if (num < 0) {
    return -1;
  } else {
    return 0;
  }
}

int MaxValue(int a, int b) {
  return a > b ? a : b;
}
int MinValue(int a, int b) {
  return a < b ? a : b;
}

int CheckZone(Point p) {
  if (p.y >= Y_1 && p.y <= -p.x - X_1 && p.y >= p.x - X_1) {
    return 1;
  }
  return 0;
}

int Task() {
  int i = INITIAL_VLUAES_I;
  int j = INITIAL_VLUAES_J;
  int l = INITIAL_VLUAES_L;
  int is_point_hit_zone = 0;
  Point p;
  p.x = i;
  p.y = j;
  for (int k = 1; k < MAX_ITERETIONS; k++) {
    i = Mod(((Pow(p.x, TWO)/(Abs(p.y - l) + k + 1)) - (Pow(p.y, 2) / (Abs(p.x - l) + k + 1))), MOD_30);
    j = Sign(l) * MinValue(p.x, p.y) - Sign(p.y) * MaxValue(p.x, l) + k;
    l = (p.x - p.y) * (p.y - l) * Mod((l - p.x), Mod_20);

    p.x = i;
    p.y = j;
    if (CheckZone(p)) {
      is_point_hit_zone++;
    }
    printf("iter: %d, x = %d, y = %d, check = %d\n", k, p.x, p.y, CheckZone(p));

  }
  if (is_point_hit_zone == 0) {
    printf("Do not have point in zone");
  } else {
    printf("Do have point in zone they count = %d", is_point_hit_zone);
  }

  return 0;
}