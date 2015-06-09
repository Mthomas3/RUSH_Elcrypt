/*
** elcrypt.c for elcrypt in /home/alpha/rendu/elcrypt
**
** Made by Stéphane
** Login   <alpha@epitech.net>
**
** Started on  Fri Feb 27 21:27:18 2015 Stéphane
** Last update Sun Mar  1 21:01:47 2015 Thomas Martins
*/

#include "struct.h"

int	process_opt(char **av, t_opt *opt)
{
  static t_func tab[] = {
    {'d', &set_type},
    {'e', &set_type},
    {'f', &set_string},
    {'o', &set_string},
    {'k', &set_string},
    {-1, NULL}
  };
  int	i;

  i = -1;
  while (**av == '-' && tab[++i].flag >= 0)
    {
      if (tab[i].flag == av[0][1])
	return (tab[i].func(av[0][1], av[1], opt));
    }
  error_opt();
  return (0);
}

int		set_string(char flag, char *str, t_opt *opt)
{
  if (!str)
    {
      printf("Error in function set_string\n");
      exit(1);
    }
  if (flag == 'f')
    opt->input = str;
  else if (flag == 'o')
    opt->output = str;
  else
    opt->key = str;
  return (2);
}

int		set_type(char flag, char *str, t_opt *opt)
{
  (void)str;
  if (flag == 'd')
    opt->type = 1;
  return (1);
}

void		init_opt(t_opt *opt)
{
  opt->output = NULL;
  opt->input = NULL;
  opt->key = NULL;
  opt->type = 0;
}

int		main(int ac, char **av)
{
  t_opt		opt;
  char		*input;
  char		*output;
  uint32_t	pkey[2];
  t_crypt	crypt;

  (void)input;
  (void)ac;
  (void)output;
  (void)crypt;
  if ((check_args(ac, av)) < 0)
    return (1);
  if ((check_args_values(av)) < 0)
    return (1);
  output = NULL;
  init_opt(&opt);
  get_opt(++av, &opt);
  process_key(opt.key, (uint32_t *)pkey);
  printf("primary_key:\n");
  print_pkey((uint32_t *)pkey);
  printf("secondary_key:\n");
  print_skey(get_secondary_key(pkey[1]));
  return (0);
}
