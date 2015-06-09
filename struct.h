/*
** struct.h for struct in /home/charre_s/rendu/CPE_2014_bsq
**
** Made by stephane  charre
** Login   <charre_s@epitech.net>
**
** Started on  Tue Jan 13 16:55:44 2015 stephane  charre
** Last update Sun Mar  1 21:05:37 2015 Thomas Martins
*/

#ifndef STRUCT_H_
# define STRUCT_H_
# define SIZE 1

#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

typedef struct	s_get_next_line	t_next;
typedef struct	s_opt	t_opt;
typedef struct	s_crypt	t_crypt;
typedef struct	s_func	t_func;

struct		s_func
{
  char		flag;
  int		(*func)(char, char *, t_opt *);
};

struct		s_opt
{
  char		*output;
  char		*input;
  char		*key;
  char		type;
};

struct		s_crypt
{
  uint32_t	R0;
  uint32_t	L0;
  int		i;
  uint32_t	p1;
  uint32_t	p2;
};

struct		s_get_next_line
{
  char		buffer[SIZE + 1];
  char		*str;
  int		j;
};

int		process_opt(char **av, t_opt *opt);
int		my_strlen(char *str);
void		get_opt(char **av, t_opt *opt);
void		error_opt(void);
void		error_hexa(void);
void		error_process(void);
char		*process_input(int fd, char *filename, t_opt *opt);
char		*set_size_64(char *str);
char		*join_and_free(char *s1, char *s2);
int		set_type(char flag, char *str, t_opt *opt);
int		set_string(char flag, char *str, t_opt *opt);
int             check_args(int ac, char **av);
char		*get_next_line(const int fd);
int             check_args_values(char **av);
int             check_args_values_bis(char **av);
int		elcrypt(char **av, t_crypt *crypt);
int		my_read(char **av);
uint64_t	get_new_key(uint64_t key);
uint64_t	get_key(char **av);
uint32_t	get_key_56(uint64_t key);
void		feistel(t_crypt *crypt, uint32_t key_32, uint64_t key);
void		get_R0_L0(t_crypt *crypt, uint64_t file);
uint32_t	key_shifting(t_crypt *crypt, uint64_t key);
void		process_key(char *str, uint32_t *key);
void		str_to_hexa(char *c, uint32_t *key);
uint32_t	char_to_hexa(char c);
void		get_opt(char **av, t_opt *opt);
void		process_action(int type, uint32_t key, uint64_t intput, t_crypt *crypt);
void		print_pkey(uint32_t *k);
void		print_skey(uint32_t k);
void		rotateleft_key(uint32_t *k, int n);
uint32_t	get_secondary_key(uint32_t pkey);

#endif /* elcrypt */
