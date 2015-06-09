/*
** elcrypt_str_two.c for  in /home/mart_4/rendu/elcrypt
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar  1 19:19:15 2015 Thomas Martins
** Last update Sun Mar  1 19:23:00 2015 Thomas Martins
*/

#include "struct.h"

uint32_t	get_secondary_key(uint32_t pkey)
{
  uint32_t	skey;
  int		i;

  skey = pkey;
  i = -1;
  while (++i < 32)
    skey &= ~(1 << (i * 8));
  return (skey);
}

void		print_skey(uint32_t k)
{
  char		str[33];
  int		i;

  i = -1;
  while (++i < 32)
    str[31 - i] = k & (1 << i) ? '1' : '0';
  str[32] = 0;
  printf("%s\n", str);
}

void		print_pkey(uint32_t *k)
{
  print_skey(*k);
  print_skey(k[1]);
}

void		rotateleft_key(uint32_t *k, int n)
{
  uint32_t	tmp;

  tmp = *k >> (32 - n);
  *k = (*k << n) | tmp;
  tmp = k[1] >> (32 - n);
  k[1] = (k[1] << n) | tmp;
}

int		my_strlen(char *s)
{
  int		l;

  if (!s)
    return (0);
  l = 0;
  while (s[l])
    l++;
  return (l);
}
