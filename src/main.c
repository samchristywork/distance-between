#include <stdio.h>

#include "haversine.h"

int main() {
  Coord london = {51.5074, -0.1278};
  Coord caracas = {10.4806, -66.9036};

  double d = haversine(london, caracas);
  printf("Distance: %f km\n", d);
}
