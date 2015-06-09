/*
** elcrypt_checks.c for elcrypt in /home/alpha/rendu/elcrypt
**
** Made by Stéphane
** Login   <alpha@epitech.net>
**
** Started on  Fri Feb 27 23:06:14 2015 Stéphane
** Last update Sat Feb 28 01:11:12 2015 Stéphane
*/

#include "struct.h"

int             check_args(int ac, char **av)
{
  if (ac != 8)
    {
      fprintf(stderr, "\033[01;31m");
      fprintf(stderr, "Usage : ./elcrypt <options>\n");
      fprintf(stderr, "\033[0m");
      return (-1);
    }
  if (check_args_values(av) == -1)
    return (-1);
  if (check_args_values_bis(av) == -1)
    return (-1);
  return (0);
}

int             check_args_values(char **av)
{
  if (av[1][0] != '-' || (av[1][1] != 'e' && av[1][1] != 'd')
      || av[1][2] != '\0')
    {
      fprintf(stderr, "\033[01;31m");
      fprintf(stderr, "First argument incorrect. ");
      fprintf(stderr, "Use <-d> decryption or <-e> encryption.\n");
      fprintf(stderr, "\033[0m");
      return (-1);
    }
  if (av[2][0] != '-' || av[2][1] != 'f'
      || av[2][2] != '\0')
    {
      fprintf(stderr, "\033[01;31m");
      fprintf(stderr, "File entry incorrect. ");
      fprintf(stderr, "Use <-f> <file name>.\n");
      fprintf(stderr, "\033[0m");
      return (-1);
    }
  return (0);
}

int             check_args_values_bis(char **av)
{
  if (av[4][0] != '-' || av[4][1] != 'o'
      || av[4][2] != '\0')
    {
      fprintf(stderr, "\033[01;31m");
      fprintf(stderr, "File output incorrect. ");
      fprintf(stderr, "Use <-o> <file name>.\n");
      fprintf(stderr, "\033[0m");
      return (-1);
    }
  if (av[6][0] != '-' || av[6][1] != 'k'
      || av[6][2] != '\0')
    {
      fprintf(stderr, "\033[01;31m");
      fprintf(stderr, "Key entry incorrect. ");
      fprintf(stderr, "Use <-k> <key>.\n");
      fprintf(stderr, "\033[0m");
      return (-1);
    }
  return (0);
}
