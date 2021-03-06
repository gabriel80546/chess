#ifndef CHESS_H
# define CHESS_H

# include "libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define DEB __FILE__, __func__, __LINE__

typedef struct s_board
{
	int	*squares;
}	t_board;

void	ler(void);
int		say(const char *format, char *file, const char *func, int line, ...);
void	print_fen(char *fen, char *file, const char *func, int line);
char	*concat(char *string, char c);
t_board	new_board(void);
t_board	set_board(t_board input, char *fen);
void	print_board(t_board board, char *file, const char *func, int line);

#endif
