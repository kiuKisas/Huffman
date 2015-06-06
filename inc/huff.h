/*
** huff.h for huffman in /home/kinoo_m/rendu/huffman
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Wed Nov 26 15:33:42 2014 Martin Kinoo
** Last update Thu Dec  4 19:56:07 2014 Martin Kinoo
*/

#ifndef		_HUFF_H_
# define	_HUFF_H_

# define        BUFF_SIZE 4096

typedef struct	s_node
{
  struct s_node	*left;
  struct s_node	*right;
  int		size;
  unsigned char	val;
}		t_node;

typedef struct	s_list
{
  void		*data;
  struct s_list	*prev;
  struct s_list	*next;
}		t_list;

typedef struct	s_print
{
  int		fd;
  unsigned char	print;
  unsigned char	len;
}		t_print;

typedef struct	s_bin
{
  void		(*f)(t_print *);
  struct s_bin	*next;
}		t_bin;

typedef struct	s_huff
{
  t_bin		**dico;
  t_list	*list;
  t_list	*file;
  char		*file_path;
  char		*bin_path;
  t_print	*print;
  int		fd;
  unsigned char	len;
}		t_huff;

void		new_list(t_list **);
void		delete_list(t_list **);
void		delete_elem(t_list *);
void		add_elem(t_list **, void *);
void		my_write_list(t_list *, int);

char		*my_strndup(char *, int);
char		*my_strdup(char *);
char		*my_strncat(char *, char *, int);
char		*my_strcat(char *, char *);
char		*get_next_line(int);

int		my_strlen(char *);
void		*xmalloc(int);

int		my_strcmp(char *, char *);

int		print_error(char *);
int		my_print(char *);

int		force_file_fd(char *, int (*f)(char *));
int		my_file_fd(char *, int (*f)(char *), int);
int		do_nothing(char *);

void		huff_elem(t_list *, unsigned char, unsigned char *);

t_node		*huff_tree(t_list *, unsigned char);

int		arg_manager(int, char **, t_huff *, int *);

t_bin		*new_bin(void (*)(t_print *));
char		add_bin(t_bin **, void (*f)(t_print *));
void		print_one(t_print *);
void		print_zero(t_print *);

char		*my_bin_converter(int, int);
void		print_bin_string(t_print *, char *);
void		print_bin_char(t_print *, unsigned char);
t_bin		*cpy_bin_list(t_bin *);

int		write_my_bin(t_node *, t_huff *);

int		code_huffman(t_huff *);

char		get_char_from_octet(t_list **, char *, char *);

int		bin_writer(int, t_list *, char, t_node *);
int		decode_huffman(t_huff *);

#endif
