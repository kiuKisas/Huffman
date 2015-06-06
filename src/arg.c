/*
** arg.c for huffman in /home/kinoo_m/rendu/huffman/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Mon Dec  1 09:22:14 2014 Martin Kinoo
** Last update Mon Dec  1 22:49:39 2014 Martin Kinoo
*/

#include	<stdlib.h>
#include	"huff.h"

static int	add_path(char **save, char *origin, char *name)
{
  if (*save)
    return (print_error(my_strcat("multiple definition for ", name)));
  if (!(*origin))
    return (print_error(my_strcat("empty definition for ", name)));
  *save = my_strdup(origin);
  return (0);
}

static int	find_my_start(char *str, char *from, char **to)
{
  int		i;

  if (!str || !from)
    return (0);
  i = 0;
  while (str[i])
    {
      if (from[i] != str[i])
	return (0);
      i++;
    }
  if (to)
  *to = &from[i];
  return (1);
}

static int	arg_manager_extra(char *av, t_huff *huffman)
{
  char		*save;

  save = NULL;
  if (find_my_start("--BIN=", av, &save))
    {
      if (add_path(&(huffman->bin_path), save, "var BIN"))
	return (1);
    }
  else if (find_my_start("--FILE=", av, &save))
    {
      if (add_path(&(huffman->file_path), save, "var FILE"))
	return (1);
    }
  else
    return (print_error(my_strcat("invalid argument ", av)));
  return (0);
}

int		arg_manager(int ac, char **av, t_huff *huffman, int *exec)
{
  int		tmp;

  if (ac > 4)
    return (print_error("too many arguments, ./huffman -h for help."));
  tmp = 1;
  while (tmp < ac)
    {
      if (!my_strcmp(av[tmp], "-h"))
	{
	  *exec = 2;
	  return (0);
	}
      else if (!my_strcmp(av[tmp], "-d"))
	*exec = 1;
      else if (arg_manager_extra(av[tmp], huffman))
	return (1);
      tmp++;
    }
  return (0);
}
