/*
** my_xmalloc.c<2> for projstarter in /home/kinoo_m/rendu/projstarter/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Fri Nov  7 11:11:10 2014 Martin Kinoo
** Last update Sat Nov  8 18:36:35 2014 Martin Kinoo
*/

#include	<stdlib.h>
#include	<unistd.h>

static void	*my_memset(char *res, size_t size)
{
  size_t	i;

  i = 0;
  while (i < size)
    {
      res[i] = '\0';
      i++;
    }
  return (res);
}

void            *xmalloc(int size)
{
  void          *res;

  if ((res = malloc(size)) == NULL)
    {
      write(2, "malloc failed.\n", 15);
      return (NULL);
    }
  return (my_memset(res, size));
}
