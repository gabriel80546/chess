#include "chess.h"

void	print_fen(char *fen, char *file, const char *func, int line)
{
	int		i;
	char	*str;
	char	*temp;
	char	*c_string;

	c_string = ft_strdup(" ");
	str = ft_strdup("");
	i = 0;
	while (fen[i] != '\0')
	{
		c_string[0] = fen[i];
		temp = ft_strjoin(str, c_string);
		free(str);
		str = temp;
		i++;
	}
	say("%s\n", file, func, line, str);
	free(c_string);
	free(str);
}

int	main(void)
{
	char	*fen;

	say("diga um fen\n", DEB);
	say("", DEB);
	if (get_next_line(STDIN_FILENO, &fen) == 1)
	{
		print_fen(fen, DEB);
		free(fen);
	}
	else
		say("gnl failed\n", DEB);
	return (0);
}
