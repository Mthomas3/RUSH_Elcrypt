/*
** error.c for  in /home/mart_4/rendu/elcrypt
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar  1 20:18:52 2015 Thomas Martins
** Last update Sun Mar  1 20:49:52 2015 Thomas Martins
*/

#include "struct.h"

void	error_opt(void)
{
  fprintf(stderr, "\033[01;31m");
  fprintf(stderr, "Error on opt, can you try again please\n");
  fprintf(stderr, "\033[0m");
  exit(0);
}

void	error_hexa(void)
{
  fprintf(stderr, "\033[01;31m");
  fprintf(stderr, "Error, can you try again please\n");
  fprintf(stderr, "\033[0m");
  exit(0);
}

void	error_process(void)
{
  fprintf(stderr, "\033[01;31m");
  fprintf(stderr, "Error on this key, try again please\n");
  fprintf(stderr, "\033[0m");
  exit(0);
}
