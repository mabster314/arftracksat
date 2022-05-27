#pragma once

#include "sgdp4/sgdp4.h"

#include <string>
#include <vector>
#include <cinttypes>
#include <chrono>

#include <nlohmann/json.hpp>
using namespace nlohmann;

struct shape {
	std::vector<xyz_t> points;
};

struct sat {
	std::string name;
	std::string norad;
	std::string intid;
	orbit_t orbit;
	xyz_t pos;
	xyz_t vel;
	xyz_t geo;
	xyz_t aer;
	double doppler;
	time_t aos;
	time_t los;
	shape geoOrbit;
	float aosRadiusAngle;
};

struct station {
	std::string name;
	xyz_t pos;
	xyz_t vel;
	xyz_t geo;
};

#define TORAD	PI/180.0
#define TODEG	180.0/PI

#define EARTHR	6371.0
#define EQR		6378.0
#define POR		6356.8

#define LIGHTC	299792458.0

// xyz_t C++ utils
inline xyz_t operator+(const xyz_t left, const xyz_t right) {
  return xyz_t{ left.x + right.x, left.y + right.y, left.z + right.z };
}

inline xyz_t operator-(const xyz_t left, const xyz_t right) {
  return xyz_t{ left.x - right.x, left.y - right.y, left.z - right.z };
}

inline xyz_t operator*(const xyz_t left, double right) {
  return xyz_t{ left.x * right, left.y * right, left.z * right };
}

inline xyz_t operator/(const xyz_t left, double right) {
  return xyz_t{ left.x / right, left.y / right, left.z / right };
}

inline double xyzmod(xyz_t v) {
  return std::hypot(v.x, v.y, v.z);
}

inline xyz_t xyzunit(xyz_t v) {
	return v / xyzmod(v);
}

inline double xyzdot(xyz_t left, xyz_t right) {
  return ((left.x * right.x) + (left.y * right.y) + (left.z * right.z));
}

// main
extern json config;
extern station sta;

extern std::vector<std::string> show;
extern std::vector<std::vector<sat>::iterator>  shownSats;
extern std::vector<std::string> columns;
extern int selsatidx;
extern time_t t_now;
extern tm utctime, loctime, aosloctime, aosutctime, losloctime, losutctime;
extern std::chrono::nanoseconds computeTime;