/*
** convet_bit.c for  in /home/mart_4/rendu/elcrypt
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sat Feb 28 13:56:38 2015 Thomas Martins
** Last update Sat Feb 28 16:35:26 2015 Stéphane
*/

#include "struct.h"

uint32_t		get_key_56(uint64_t key)
{
  uint32_t		key_56;

  key_56 = key << 24;
  return (key_56);
}

uint64_t	get_new_key(uint64_t key)
{
  int		i;
  uint64_t	new_key;
  uint8_t	*k;

  i = 7;
  new_key = 0;
  k = (uint8_t *)(&key);
  while (i >= 0)
    {
      new_key = new_key << 7;
      new_key = new_key + (k[i] >> 1);
      i--;
    }
  return (new_key);
}
