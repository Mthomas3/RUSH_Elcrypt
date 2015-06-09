/*
** elcrypt_calc.c for calc in /home/alpha/rendu/elcrypt
**
** Made by Stéphane
** Login   <alpha@epitech.net>
**
** Started on  Sat Feb 28 15:26:04 2015 Stéphane
** Last update Sun Mar  1 19:54:53 2015 Thomas Martins
*/

#include "struct.h"

void		get_R0_L0(t_crypt *crypt, uint64_t file)
{
  crypt->R0 = file;
  crypt->L0 = file << 32;
}

uint32_t	key_shifting(t_crypt *crypt, uint64_t key)
{
  uint32_t	new_key_32;

  key = key << 4 * crypt->i;
  new_key_32 = key << 24;
  return (new_key_32);
}

void		feistel(t_crypt *crypt, uint32_t key_32, uint64_t key)
{
  uint32_t	c1;
  uint32_t	c2;
  uint32_t	c12;
  uint32_t	c21;
  int		i;

  i = 1;
  while (i < 5)
    {
      c1 = crypt->R0 ^ key_32;
      c2 = crypt->L0 ^ c1;
      crypt->i = i;
      key_32 = key_shifting(crypt, key);
      c12 = c2 ^ key_32;
      c21 = crypt->R0 ^ c12;
      crypt->R0 = c21;
      crypt->L0 = c2;
      i++;
      crypt->i = i;
      key_32 = key_shifting(crypt, key);
    }
  crypt->R0 = c21;
  crypt->L0 = c2;
}
