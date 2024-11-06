#include <math.h>

#include "haversine.h"

double haversine(Coord c1, Coord c2) {
  double dLat = (c2.lat - c1.lat) * M_PI / 180.0;
  double dLon = (c2.lon - c1.lon) * M_PI / 180.0;
  double a = sin(dLat / 2) * sin(dLat / 2) + cos(c1.lat * M_PI / 180.0) *
                                                 cos(c2.lat * M_PI / 180.0) *
                                                 sin(dLon / 2) * sin(dLon / 2);
  double c = 2 * atan2(sqrt(a), sqrt(1 - a));
  return 6371 * c;
}
