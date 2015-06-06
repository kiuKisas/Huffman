/*
** my_strcat.c for my_strcat in /home/kinoo_m/rendu/projstarter
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Tue Nov 25 05:04:05 2014 Martin Kinoo
** Last update Wed Nov 26 16:00:03 2014 Martin Kinoo
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		"huff.h"

char			*my_strcat(char *dest, char *src)
{
  int			i;
  int			j;
  char			*ret;

  i = my_strlen(dest) + my_strlen(src);
  if ((ret = xmalloc(sizeof(char) * (i + 1))) == NULL)
    {
      write(2, "erreur malloc.\n", 15);
      return (NULL);
    }
  i = 0;
  while (dest && dest[i])
    {
      ret[i] = dest[i];
      i++;
    }
  j = 0;
  while (src && src[j])
    ret[i++] = src[j++];
  return (ret);
}
