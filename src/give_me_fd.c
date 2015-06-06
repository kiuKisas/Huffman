/*
** give_me_fd.c for projstarter in /home/kinoo_m/rendu/projstarter/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Thu Nov 13 21:46:56 2014 Martin Kinoo
** Last update Tue Dec  2 15:24:52 2014 Martin Kinoo
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<errno.h>
#include	"huff.h"

static int	error_file(int fd, char *path, int (*f)(char *))
{
  (*f)(path);
  free(path);
  close(fd);
  return (-1);
}

int		force_file_fd(char *path, int (*f)(char *))
{
  int		fd;
  char		*print;
  char		*tmp;

  if ((fd = open(path, O_DIRECTORY, S_IRUSR)) > 0)
    return (error_file(fd, my_strncat(path, " is a folder", 12), f));
  if ((fd = open(path, O_RDWR|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)) > 0)
    return (fd);
  tmp = my_strncat("can't access to ", path, my_strlen(path));
  if (errno == EACCES)
    print = my_strncat(tmp, ": permission denied", 19);
  else if  (errno == ENOENT)
    print = my_strncat(tmp, ": file not found", 16);
  else if  (errno == ENAMETOOLONG)
    print = my_strncat(tmp, ": too long pathname", 19);
  else
    print = tmp;
  if (print != tmp)
    free(tmp);
  (*f)(print);
  free(print);
  return (-1);
}

int		my_file_fd(char *path, int (*f)(char *), int flag)
{
  int		fd;
  char		*print;
  char		*tmp;

  if ((fd = open(path, O_DIRECTORY, S_IRUSR)) > 0)
    return (error_file(fd, my_strncat(path, " is a folder", 12), f));
  if ((fd = open(path, flag, S_IWUSR)) > 0)
    return (fd);
  tmp = my_strncat("can't access to ", path, my_strlen(path));
  if (errno == EACCES)
    print = my_strncat(tmp, " permission denied", 18);
  else if  (errno == ENOENT)
    print = my_strncat(tmp, " file not found", 15);
  else if  (errno == ENAMETOOLONG)
    print = my_strncat(tmp, " too long pathname", 18);
  else
    print = tmp;
  if (print != tmp)
    free(tmp);
  (*f)(print);
  free(print);
  return (-1);
}
