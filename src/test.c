#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "haversine.h"

#define EPSILON 0.001

int approximately_equal(double a, double b, double epsilon) {
  return fabs(a - b) < epsilon;
}

void test_same_point() {
  Coord point = {0.0, 0.0};
  double result = haversine(point, point);
  assert(approximately_equal(result, 0.0, EPSILON));
}

void test_london_caracas() {
  Coord london = {51.5074, -0.1278};
  Coord caracas = {10.4806, -66.9036};
  double expected_distance = 7454.21;
  double result = haversine(london, caracas);
  assert(approximately_equal(result, expected_distance, EPSILON));
}

void test_equator() {
  Coord point1 = {0.0, 0.0};
  Coord point2 = {0.0, 90.0};
  double expected_distance = 10007.54;
  double result = haversine(point1, point2);
  assert(approximately_equal(result, expected_distance, EPSILON));
}

void test_poles() {
  Coord north_pole = {90.0, 0.0};
  Coord south_pole = {-90.0, 0.0};
  double expected_distance = 20015.09;
  double result = haversine(north_pole, south_pole);
  assert(approximately_equal(result, expected_distance, EPSILON));
}

int main() {
  test_same_point();
  test_london_caracas();
  test_equator();
  test_poles();

  printf("All tests passed!\n");
}
