
#include <stdlib.h>
#include "raytracer.h"
#include "read.h"

static const t_fill	g_objet[] = {
  {"pos", &fill_spot_pos},
  {"ray", &fill_spot_ray},
  {"angle", &fill_spot_angle},
  {"color", &fill_spot_color},
  /* {"negative", &fill_spot_negative}, */
  {NULL, NULL},
};
