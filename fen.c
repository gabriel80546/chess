#include "chess.h"

void	print_fen(char *fen, char *file, const char *func, int line)
{
	int		i;
	int		j;
	char	*str;

	str = ft_strdup("");
	i = 0;
	while (fen[i] != '\0')
	{
		if (fen[i] >= '0' && fen[i] <= '9')
		{
			j = 0;
			while (j < fen[i] - '0')
			{
				str = concat(str, ' ');
				j++;
			}
		}
		else if (fen[i] == '/')
		{
			say("%s\n", file, func, line, str);
			free(str);
			str = ft_strdup("");
		}
		else if (fen[i] == ' ')
			break ;
		else
			str = concat(str, fen[i]);
		i++;
	}
	say("%s\n", file, func, line, str);
	free(str);
}
