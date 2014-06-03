
#include "raytracer.h"

void	disp_params(t_params *prams, )
{
  int	i;

  i = -1;
  while (++i < params->nb_objs)
    {
      printf("NB_OBJET == %d\n NB_SPOT == %d\n COLOR = %d\n NEGATIVITE = %d\n %f\n %f\n %f\n %f\n", params->nb_objs, params[i].nb_spots, params->objs[i].color, params->objs[i].negative, params->objs[i].texture, params->objs[i].shine, params->objs[i].angle);
    }
}
