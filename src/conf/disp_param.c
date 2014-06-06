
#include <stdio.h>
#include "raytracer.h"

void	disp_params(t_params *params)
{
  int	i;

  i = -1;
  while (++i < params->nb_objs)
    {
      printf("======================START_OBJ===========================\n=================================================\n\nPOS_EYE[0] = %f\n POS_EYE[1] = %f\n POS_EYE[2] = %f\n ROT_EYE[0] = %f\n ROT_EYE[1] = %f\n ROT_EYE[2] = %f\n NB_OBJET == %d\n NB_SPOT == %d\n OBJ_COLOR = %d\n OBJ_NEGATIVITE = %d\n OBJ_ANGLE = %f\n OBJ_POS[0] = %f\n OBJ_POS[1] = %f\n OBJ_POS[2] = %f\n OBJ_ROT[0] = %f\n OBJ_ROT[1] = %f\n OBJ_ROT[2] = %f =================================================\n==========================END_OBJ=======================\n\n", params->pos_eye[0], params->pos_eye[1], params->pos_eye[2], params->rot_eye[0], params->rot_eye[1], params->rot_eye[2], params->nb_objs, params->nb_spots, params->objs[i].color, params->objs[i].negative, params->objs[i].angle, params->objs[i].pos[0], params->objs[i].pos[1], params->objs[i].pos[2], params->objs[i].rot[0], params->objs[i].rot[1], params->objs[i].rot[2]);
    }
  i = -1;
  while (++i < params->nb_spots)
    printf("======================START_SPOTS===========================\n=================================================\n\nSPOT_POS[0] = %f\n SPOT_POS[1] = %f\n SPOT_POS[2] = %f\n SPOT_COLOR = %d\n =================================================\n==========================END_SPOTS=======================\n\n", params->spots[i].pos[0], params->spots[i].pos[1], params->spots[i].pos[2], params->spots[i].color);
}
