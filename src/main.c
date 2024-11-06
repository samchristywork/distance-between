#include <stdio.h>

#include "args.h"
#include "haversine.h"
#include "version.h"

int main(int argc, char *argv[]) {
  add_arg('h', "help", "Print this usage message.", ARG_NONE);
  add_arg('v', "version", "Print version information.", ARG_NONE);

  if (get_arg_bool(argc, argv, 'h', false)) {
    usage(argv[0]);
  }

  if (get_arg_bool(argc, argv, 'v', false)) {
    version(VERSION_STRING, LICENSE_STRING);
    exit(EXIT_SUCCESS);
  }

  Coord c1 = {51.5074, -0.1278};
  Coord c2 = {10.4806, -66.9036};

  double d = haversine(c1, c2);
  printf("Distance: %f km\n", d);
}
