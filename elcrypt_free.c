/*
** elcrypt_free.c for  in /home/mart_4/rendu/elcrypt
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar  1 19:23:16 2015 Thomas Martins
** Last update Sun Mar  1 20:04:23 2015 Thomas Martins
*/

#include "struct.h"

char	*process_input(int fd, char *filename, t_opt *opt)
{
  char	*s;
  char	buff[4096];
  int	ret;

  if (filename && !(fd = open(filename, O_RDONLY)))
    {
      printf("fail on input\n");
      exit(0);
    }
  s = memset(malloc(1), 1, 0);
  while ((ret = read(fd, buff, 4095)) > 0)
    {
      buff[ret] = 0;
      s = join_and_free(s, buff);
    }
  close(fd);
  return (set_size_64(opt->input));
}

char	*set_size_64(char *str)
{
  int	len;

  len = my_strlen(str);
  if (len % 64)
    {
      while (len % 64)
	++len;
      str = realloc(str, len + 1);
    }
  return (str);
}

char	*join_and_free(char *s1, char *s2)
{
  int	len1;
  int	len2;

  len1 = my_strlen(s1);
  len2 = my_strlen(s2);
  if ((s1 = realloc(s1, len1 + len2 + 1)))
    {
      memcpy(s1 + len1, s2, len2);
      s1[len1 + len2] = 0;
    }
  return (s1);
}
