/*
** basic_functions.c for raytraceur in /home/grelli_t/ABUZAY/Raytraceur/Raytraceur/Ganesha51-raytracer-40f2a2190e64
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Mon Apr 21 10:05:35 2014 grelli_t
** Last update Mon Apr 21 10:05:36 2014 grelli_t
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_putstr(char *str)
{
  while (*str)
    write(1, str++, 1);
}

int	my_getnbr(char *str)
{
  int	ret;
  int	sign;
  int	i;

  sign = 1;
  i = 0;
  if (str[0] == '-')
    {
      sign = -1;
      i++;
    }
  while (str[i] != '\0')
    {
      ret = ret * 10;
      ret = ret + (str[i++] - 48);
    }
  if (ret < 0)
    return (0);
  return (ret * sign);
}

void	my_put_nbr(int nb)
{
  int	a;
  int	n;

  a = 1;
  n = 0;
  if (nb < 0)
    {
      nb = nb * (-1);
      my_putchar('-');
    }
  while ((nb / a) >= 10)
    a = a * 10;
  while (a != 0)
    {
      n = nb / a;
      n = n % 10;
      my_putchar(n + 48);
      a = a / 10;
    }
}
