/*
** elcrypt_action.c for  in /home/mart_4/rendu/elcrypt
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar  1 19:28:26 2015 Thomas Martins
** Last update Sun Mar  1 20:58:40 2015 Thomas Martins
*/

#include "struct.h"

void	process_action(int type, uint32_t key, uint64_t *input, t_crypt *crypt)
{
  int	i;

  get_R0_L0(t_crypt *crypt, input);
  i = -1;
  if (type == 0)
    {
      while (++i < 8)
	{
	  feistel(t_crypt *crypt, pkey);
	  rotateleft_key(pkey, 4);
	}
    }
}
