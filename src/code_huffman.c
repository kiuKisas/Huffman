/*
** code_huffman.c for huffman in /home/kinoo_m/rendu/huffman/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Tue Dec  2 01:57:19 2014 Martin Kinoo
** Last update Thu Dec  4 19:44:23 2014 Martin Kinoo
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"huff.h"

static t_node	*get_file(t_huff *huffman)
{
  char		*str;
  int		i;

  new_list(&(huffman->list));
  new_list(&(huffman->file));
  while ((str = get_next_line(huffman->fd)))
    {
      add_elem(&(huffman->file), str);
      i = 0;
      while (str[i])
	{
	  huff_elem(huffman->list->next, str[i], &(huffman->len));
	  i++;
	}
    }
  return (huff_tree(huffman->list, huffman->len));
}

int		code_huffman(t_huff *huffman)
{
  t_node	*tree;

  if (!(huffman->bin_path))
    huffman->bin_path = my_strdup("huff.bin");
  if (!(huffman->print = xmalloc(sizeof(t_print))))
    return (1);
  if ((huffman->print->fd = my_file_fd(huffman->bin_path, &do_nothing,
				       O_RDONLY)) > -1)
    return (print_error(my_strcat("this file already exist ",
				  huffman->bin_path)));
  if ((huffman->print->fd = force_file_fd(huffman->bin_path, &print_error))
      == -1)
    return (1);
  if (huffman->file_path &&
      ((huffman->fd = my_file_fd(huffman->file_path, &print_error, O_RDWR))
       == -1))
    return (1);
  if (!(tree = get_file(huffman)))
    return (print_error("text to convert is empty"));
  free(huffman->bin_path);
  free(huffman->file_path);
  write_my_bin(tree, huffman);
  return (0);
}
