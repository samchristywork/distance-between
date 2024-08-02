#include <math.h>
#include <stdio.h>

typedef struct {
  double lat;
  double lon;
} Coord;

double haversine(double lat1, double lon1, double lat2, double lon2) {
  double dLat = (lat2 - lat1) * M_PI / 180.0;
  double dLon = (lon2 - lon1) * M_PI / 180.0;
  double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1 * M_PI / 180.0) *
                                                 cos(lat2 * M_PI / 180.0) *
                                                 sin(dLon / 2) * sin(dLon / 2);
  double c = 2 * atan2(sqrt(a), sqrt(1 - a));
  return 6371 * c;
}

double distance(Coord c1, Coord c2) {
  return haversine(c1.lat, c1.lon, c2.lat, c2.lon);
}

int main() {
  Coord london = {51.5074, -0.1278};
  Coord caracas = {10.4806, -66.9036};

  double d = distance(london, caracas);
  printf("Distance: %f km\n", d);
}
