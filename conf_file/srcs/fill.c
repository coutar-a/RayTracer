
#include <stdlib.h>
#include "raytracer.h"
#include "read.h"

int	fill_spots(t_params *params, char **file, int *i)
{
  int	j;

  j = -1;
  while (42)
    {
      if (file[*i][0] == '}')
	{
	  ++(*i);
	  return (0);
	}
      fill_window_in_params(params, file, i);
      ++(*i);
    }
  return (0);
}

int	fill_keywords(t_params *params, char **file, int *i)
{
   return (0);
}
