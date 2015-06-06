/*
** decode_huffman.c for huffman in /home/kinoo_m/rendu/huffman/src
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Thu Dec  4 07:44:09 2014 Martin Kinoo
** Last update Thu Dec  4 18:49:08 2014 Martin Kinoo
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"huff.h"

static int	check_end_bin(t_list **octet, char *cur, char **cast)
{
  char		*tmp;

  tmp = *cast;
  if (!(tmp[(int)(*cur)]))
    {
      *octet = (*octet)->next;
      *cast = (*octet)->data;
      if (!(*cast))
	return (print_error("invalid tree.. programme ending"));
      *cur = 0;
    }
  return (0);
}

static t_node	*build_my_node(t_list **octet, char *cur, char *err)
{
  t_node	*node;
  char		*cast;

  if (*err == 1)
    return (NULL);
  *cur = *cur + 1;
  cast = (*octet)->data;
  if ((*err = check_end_bin(octet, cur, &cast)))
    return (NULL);
  if (!(node = xmalloc(sizeof(t_node))))
    return (NULL);
  if (cast[(int)(*cur)] == '0')
    {
      node->left = build_my_node(octet, cur, err);
      if (*err == 1)
	return (NULL);
      node->right = build_my_node(octet, cur, err);
      if (*err == 1)
	return (NULL);
      return (node);
    }
  node->val = get_char_from_octet(octet, cur, err);
  if (*err == 1)
    return (NULL);
  return (node);
}

static t_node	*make_bin_tree(t_list **octet, char *curs)
{
  char		*cast;
  char		start;
  t_node	*tree;

  if (!octet || !(*octet) || !((*octet)->next->data))
    return (NULL);
  (*octet) = (*octet)->next;
  cast = (*octet)->data;
  start = 0;
  if (cast[0] == '1')
    start += 4;
  if (cast[1] == '1')
    start += 2;
  if (cast[2] == '1')
    start += 1;
  *curs = 2;
  cast = (*octet)->prev->prev->data;
  start = 8 - start;
  cast[(int)start] = '\0';
  start = 0;
  if (!(tree = build_my_node(octet, curs, &start)))
    return (NULL);
  return (tree);
}

static t_node	*take_my_bin_file(int fd, t_list **octet, char *cur)
{
  char		buff[BUFF_SIZE];
  int		i;
  int		ret;
  unsigned char	cast;

  while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
    {
      i = 0;
      while (i < ret)
	{
	  cast = buff[i];
	  add_elem(octet, my_bin_converter((int)(cast), 8));
	  i++;
	}
    }
  close(fd);
  if (!((*octet)->next->data))
    {
      print_error("text to convert is empty");
      return (NULL);
    }
  return (make_bin_tree(octet, cur));
}

int		decode_huffman(t_huff *huffman)
{
  t_node	*tree;
  int		fd;
  t_list	*octet;
  char		curs;

  if (!(huffman->bin_path))
    return (print_error("bin file missing, --BIN=<path>"));
  if ((huffman->file_path))
    {
      if (((huffman->fd = my_file_fd(huffman->file_path, &do_nothing, O_RDONLY))
	   > -1))
	return (print_error(my_strcat("this file already exist ",
				      huffman->file_path)));
      if ((huffman->fd = force_file_fd(huffman->file_path, &print_error))
	  == -1)
	return (1);
    }
  if ((fd = my_file_fd(huffman->bin_path, &print_error, O_RDONLY)) == -1)
    return (1);
  new_list(&octet);
  curs = 0;
  if (!(tree = take_my_bin_file(fd, &octet, &curs)))
    return (1);
  return (bin_writer(huffman->fd, octet, curs, tree));
}
