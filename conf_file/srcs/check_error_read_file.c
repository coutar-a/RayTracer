
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "read.h"

int	check_error_read_file_part(int *fd, int *ret, char *file_name)
{
  if ((*fd = open(file_name, O_RDONLY)) == -1)
    {
      my_error("Open fail\n");
      return (ERROR);
    }
  if ((*ret = lseek(*fd, 0, SEEK_END)) == -1)
    {
      my_error("Lseek fail\n");
      close(*fd);
      return (ERROR);
    }
  lseek(*fd, 0, SEEK_SET);
  return (0);
}

char	*check_error_read_file(int *fd, int *ret, char *file_name)
{
  char	*buff;

  /*if ((*fd = open(file_name, O_RDONLY)) == -1)
    {
      my_error("Open fail\n");
      return (NULL);
    }
  if ((*ret = lseek(*fd, 0, SEEK_END)) == -1)
    {
      my_error("Lseek fail\n");
      close(*fd);
      return (NULL);
    }
  lseek(*fd, 0, SEEK_SET);*/
  if (check_error_read_file_part(fd, ret, file_name) == ERROR)
    return (NULL);
  if ((buff = malloc((*ret + 1) * sizeof(char))) == NULL)
    {
      my_error("Malloc fail\n");
      close(*fd);
      return (NULL);
    }
  if ((*ret = read(*fd, buff, *ret)) <= 0)
    {
      my_error("Fail in read_fail\n");
      close(*fd);
      return (NULL);
    }
  buff[*ret] = '\0';
  return (buff);
}
