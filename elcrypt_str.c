/*
** elcrypt_str.c for  in /home/mart_4/rendu/elcrypt
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar  1 20:45:57 2015 Thomas Martins
** Last update Sun Mar  1 20:46:23 2015 Thomas Martins
*/

#include "struct.h"

void            process_key(char *str, uint32_t *key)
{
  if (!str || strlen(str) != 16)
    error_process();
  str_to_hexa(str, &key[0]);
  str_to_hexa(str + 8, &key[1]);
}

void            str_to_hexa(char *c, uint32_t *key)
{
  int           i;

  *key = 0;
  i = -1;
  while (++i < 4)
    {
      *key <<= 8;
      *key |= (char_to_hexa(*c) << 4) | char_to_hexa(*(c + 1));
      c += 2;
    }
}

uint32_t        char_to_hexa(char c)
{
  uint32_t      i;

  if (c >= 'a' && c<= 'f')
    c -= 'a' - 'A';
  if (c >= 'A' && c<= 'F')
    i = c - 'A' + 10;
  else if (c >= '0' && c <= '9')
    i = c - '0';
  else
    error_hexa();
  return (i);
}

void		get_opt(char **av, t_opt *opt)
{
  while (*av)
    av += process_opt(av, opt);
}
