/*
** my_strcmp.c for my_strcmp in /home/kinoo_m/rendu/Piscine_C_J06/ex_05
**
** Made by Martin Kinoo
** Login   <kinoo_m@epitech.net>
**
** Started on  Thu Nov 13 17:35:02 2014 Martin Kinoo
** Last update Sun Nov 23 03:54:26 2014 Martin Kinoo
*/

int		my_strcmp(char *s1, char *s2)
{
  int		i;

  if (!s1 || !s2 || !(*s1) || !(*s2))
    return (0);
  i = 0;
  while (s1[i] != '\0' || s1[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  return (0);
}
