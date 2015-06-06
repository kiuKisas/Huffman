/*
** main.c for huffman in /home/kinoo_m/rendu/huffman
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Wed Nov 26 15:33:33 2014 Martin Kinoo
** Last update Thu Dec  4 08:22:37 2014 Martin Kinoo
*/

#include	<unistd.h>
#include	"huff.h"

static int	print_info()
{
  write(1, "Usage: ./huffman [options]...\n", 30);
  write(1, "Compress a text with Huffman coding and save it.\n", 49);
  write(1, "By default, reads standard input", 32);
  write(1, " and save compression in \"./huff.bin\"\n", 38);
  write(1, "\nOptions :\n", 11);
  write(1, "-d\t\thuffman in decompression mode\n", 34);
  write(1, "--BIN=<path>\tspecify the path of the binary\n", 44);
  write(1, "--FILE=<path>\tspecify the path of the file\n", 43);
  write(1, "-h\t\tprint this message\n", 23);
  return (0);
}

int		main(int ac, char **av)
{
  t_huff	*huffman;
  int		exec;

  if (!(huffman = xmalloc(sizeof(t_huff))))
    return (1);
  exec = 0;
  if (arg_manager(ac, av, huffman, &exec))
    return (1);
  if (exec > 1)
    return (print_info());
  else if (exec == 1)
    {
      if (decode_huffman(huffman))
	return (1);
    }
  else if (code_huffman(huffman))
    return (1);
  return (0);
}
