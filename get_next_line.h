#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*get_next_line(int fd);

#endif
