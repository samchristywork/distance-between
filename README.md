![Banner](https://s-christy.com/sbs/status-banner.svg?icon=navigation/assistant_navigation&hue=200&title=Distance%20Between&description=A%20program%20for%20finding%20the%20distance%20between%20two%20points%20on%20Earth)

## Overview

`distance-between` is a program for calculating the distance between two
geographical coordinates on the Earth's surface using the Haversine formula.
This formula is typically employed to compute distances assuming a spherical
Earth, providing a means to estimate how far apart two points are based on their
latitude and longitude.

## Features

- Computes the distance between two sets of latitude and longitude coordinates.
- Utilizes the Haversine formula to determine the distance over the Earth’s surface.
- Accepts coordinates as command-line arguments for ease of use.
- Allows the user to choose between kilometers and miles for displaying the distance.
- Includes a help flag to guide users on how to properly use the application.
- Includes a test program to make sure the program is working properly.
- Uses a Makefile to easily build the program.

## Build

Run `make` to build the program.

Run `make test` to run tests.

## Usage

```
Usage: ./build/main [options]

Options:
  -a, --lat1:     The latitude part of the first coordinate.
  -b, --lon1:     The longitude part of the first coordinate.
  -c, --lat2:     The latitude part of the second coordinate.
  -d, --lon2:     The longitude part of the second coordinate.
  -h, --help:     Print this usage message.
  -m, --miles:    Display the distance in miles instead of kilometers.
  -v, --version:  Print version information.
```

## Examples

The distance between the North and South pole in miles:

```
./build/main --lat1 0 --lon1 -90 --lat2 00 --lon2 90 --miles
Distance: 12436.794498 miles
```

Distance between London and Caracas:

```
./buid/main --lat1 51.5074 --lon1 -0.1278 --lat2 10.4806 --lon2 -66.9036
Distance: 7498.544064 km
```

## Dependencies

```
gcc
make
```

## Limitations

This program assumes the Earth is spherical, but it is not exactly spherical.

## License

This work is licensed under the GNU General Public License version 3 (GPLv3).

[<img src="https://s-christy.com/status-banner-service/GPLv3_Logo.svg" width="150" />](https://www.gnu.org/licenses/gpl-3.0.en.html)
