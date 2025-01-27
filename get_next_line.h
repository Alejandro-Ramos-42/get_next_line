#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_list
{
  void           *content;
  struct s_list  *next;
} t_list;

  char  *get_next_line(int fd);
#endif
