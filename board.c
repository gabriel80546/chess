#include "chess.h"

t_board	new_board(void)
{
	t_board	saida;

	saida.squares = (int *)calloc(sizeof(int), 64);
	return (saida);
}

t_board	set_board(t_board input, char *fen)
{
	t_board	saida;
	int		i;
	int		j;

	saida = input;
	i = 0;
	j = 0;
	while (i < 64 && fen[j] != '\0')
	{
		if (fen[j] != '/')
		{
			saida.squares[i] = fen[j];
			j++;
		}
		i++;
	}
	return (saida);
}

void	print_board(t_board board, char *file, const char *func, int line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (i < 8)
	{
		str = ft_strdup("12345678");
		j = 0;
		while (j < 8)
		{
			str[j] = (char)board.squares[(i * 8) + j];
			j++;
		}
		say("%s\n", file, func, line, str);
		free(str);
		i++;
	}
}
