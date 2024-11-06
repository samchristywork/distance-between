#ifndef HAVERSINE_H
#define HAVERSINE_H

typedef struct {
  double lat;
  double lon;
} Coord;

double haversine(Coord c1, Coord c2);

#endif
