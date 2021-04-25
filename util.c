#include "chess.h"

char	*concat(char *string, char c)
{
	char	*temp;
	char	*c_string;

	c_string = ft_strdup(" ");
	c_string[0] = c;
	temp = ft_strjoin(string, c_string);
	free(string);
	string = temp;
	free(c_string);
	return (string);
}
