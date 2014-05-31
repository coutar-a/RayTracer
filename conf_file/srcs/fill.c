
#include <stdlib.h>
#include "raytracer.h"
#include "read.h"

static const t_fill	g_objet[] = {
  {"pos", &fill_sphere_pos},
  {"ray", &fill_sphere_ray},
  {"angle", &fill_sphere_angle},
  {"color", &fill_sphere_color},
  {"transparency", &fill_sphere_transparencuy},
  {"negative", &fill_sphere_negative},
  {"texture", &fill_sphere_texture},
  {NULL, NULL},
};

int	fill_spots(t_params *params, char **file, int *i)
{
  t_params	*obj;

  if ((obj = malloc(sizeof(t_params))) == NULL)
    return (ERROR);
  if ((obj->objs = malloc((params->nb_objs * sizeof(t_objs)) + 1)) == NULL)
    return (ERROR);
  printf("%d\n", (params->nb_objs + 1));
  fill_sphere(obj, file, i);
  return (0);
}
