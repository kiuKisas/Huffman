/*
** gnl.c for get_next_line in /home/kinoo_m/rendu/fonctions/gnl
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on Wed Oct 29 00:14:32 2014 Martin Kinoo
** Last update Sat Nov 29 09:04:06 2014 Martin Kinoo
*/

#include		<stdlib.h>
#include		<unistd.h>
#include		"huff.h"

static int		find_end(char *str)
{
  int			i;

  if (str == NULL)
    return (-1);
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	{
	  return (i);
	}
      i++;
    }
  return (-1);
}

static char		*check_end(char **save)
{
  int			i;
  char			*ret;
  char			*over;

  if (save == NULL || *save == 0 || ((i = find_end(*save)) == -1))
    return (NULL);
  ret = my_strndup(*save, i + 1);
  over = my_strdup(*save + i + 1);
  free(*save);
  *save = over;
  return (ret);
}

char			*get_next_line(int fd)
{
  int			nbr;
  char			*ret;
  static char		*save = NULL;
  char			buff[BUFF_SIZE];

  while (!(ret = check_end(&save)))
    {
      if ((nbr = read(fd, buff, BUFF_SIZE)) < 0)
	return (NULL);
      if (!nbr)
	{
	  ret = save;
	  save = NULL;
	  return (ret);
	}
      save = my_strncat(save, buff, nbr);
    }
  return (ret);
}
