
#include "raytracer.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  if (my_strlen(s1) != my_strlen(s2))
    return (1);
  i = -1;
  while (s1[++i] != '\0')
    if (s1[i] != s2[i])
      return (1);
  return (0);
}

int	my_strncmp(char *s1, char *s2, int size)
{
  int	i;

  if (my_strlen(s1) != my_strlen(s2))
    return (1);
  i = -1;
  while (s1[++i] != '\0' && i < size)
    if (s1[i] != s2[i])
      return (1);
  return (0);
}
