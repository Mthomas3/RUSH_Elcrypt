/*
** elcrypt_read.c for elc read in /home/alpha/rendu/elcrypt
**
** Made by Stéphane
** Login   <alpha@epitech.net>
**
** Started on  Sat Feb 28 01:20:55 2015 Stéphane
** Last update Sun Mar  1 19:09:27 2015 Thomas Martins
*/

#include "struct.h"

char		*get_next_line(const int fd)
{
  t_next	next;
  static int	readd;
  static int	cpt = 0;

  next.j = 0;
  if ((next.str = malloc(sizeof(next.str) + (sizeof(char) *
					     SIZE + 1000))) == NULL)
    exit(1);
  while (next.buffer[cpt] != '\n')
    {
      if ((readd = read(fd, next.buffer, SIZE)) == -1 || readd == 0)
	return (NULL);
      cpt = 0;
      next.buffer[readd] = 0;
      while (next.buffer[cpt] != 0 && next.buffer[cpt] != '\n')
	next.str[next.j++] = next.buffer[cpt++];
    }
  if (next.buffer[cpt] == '\n')
    next.str[next.j] = '\n';
  cpt++;
  next.str[next.j] = 0;
  return (next.str);
}
