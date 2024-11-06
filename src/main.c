#include <math.h>
#include <stdio.h>

typedef struct {
  double lat;
  double lon;
} Coord;

double haversine(Coord c1, Coord c2) {
  double dLat = (c2.lat - c1.lat) * M_PI / 180.0;
  double dLon = (c2.lon - c1.lon) * M_PI / 180.0;
  double a = sin(dLat / 2) * sin(dLat / 2) + cos(c1.lat * M_PI / 180.0) *
                                                 cos(c2.lat * M_PI / 180.0) *
                                                 sin(dLon / 2) * sin(dLon / 2);
  double c = 2 * atan2(sqrt(a), sqrt(1 - a));
  return 6371 * c;
}

int main() {
  Coord london = {51.5074, -0.1278};
  Coord caracas = {10.4806, -66.9036};

  double d = haversine(london, caracas);
  printf("Distance: %f km\n", d);
}
