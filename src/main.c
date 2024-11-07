#include <stdio.h>
#include <stdlib.h>

#include "args.h"
#include "haversine.h"
#include "version.h"

int main(int argc, char *argv[]) {
  add_arg('a', "lat1", "The latitude part of the first coordinate.",
          ARG_REQUIRED);
  add_arg('b', "lon1", "The longitude part of the first coordinate.",
          ARG_REQUIRED);
  add_arg('c', "lat2", "The latitude part of the second coordinate.",
          ARG_REQUIRED);
  add_arg('d', "lon2", "The longitude part of the second coordinate.",
          ARG_REQUIRED);
  add_arg('h', "help", "Print this usage message.", ARG_NONE);
  add_arg('v', "version", "Print version information.", ARG_NONE);

  if (get_arg_bool(argc, argv, 'h', false)) {
    usage(argv[0]);
  }

  if (get_arg_bool(argc, argv, 'v', false)) {
    version(VERSION_STRING, LICENSE_STRING);
    exit(EXIT_SUCCESS);
  }

  bool is_set[] = {false, false, false, false};
  double lat1 = get_arg_double(argc, argv, 'a', 0, &is_set[0]);
  double lon1 = get_arg_double(argc, argv, 'b', 0, &is_set[1]);
  double lat2 = get_arg_double(argc, argv, 'c', 0, &is_set[2]);
  double lon2 = get_arg_double(argc, argv, 'd', 0, &is_set[3]);

  for (int i = 0; i < 4; i++) {
    if (!is_set[i]) {
      usage(argv[0]);
    }
  }

  // Coord london = {51.5074, -0.1278};
  // Coord caracas = {10.4806, -66.9036};

  Coord c1 = {lat1, lon1};
  Coord c2 = {lat2, lon2};

  double d = haversine(c1, c2);
  printf("Distance: %f km\n", d);
}
