/*
** print_and_len.c for projstarter in /home/kinoo_m/rendu/projstarter/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Tue Oct 28 21:07:09 2014 Martin Kinoo
** Last update Tue Dec  2 14:29:06 2014 Martin Kinoo
*/

#include	<stdlib.h>
#include	<unistd.h>

int		my_strlen(char *str)
{
  char		*curs;

  if (!str || !(*str))
    return (0);
  curs = str;
  while (*curs)
    curs++;
  return (curs - str);
}

int		print_error(char *str)
{
  write(2, "[HUFFMAN] Error: ", 17);
  write(2, str, my_strlen(str));
  write(2, "\n", 1);
  return (1);
}

int		my_print(char *str)
{
  write(1, "[HUFFMAN] ", 10);
  write(1, str, my_strlen(str));
  write(1, "\n", 1);
  return (0);
}

int		do_nothing(char *nothing)
{
  (void)	(nothing);

  return (0);
}
