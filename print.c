#include "chess.h"
#include <stdarg.h>
#include <sys/time.h>

int	say(const char *format, char *file, const char *func, int line, ...)
{
	va_list			args;
	int				saida;
	struct timeval	tempo;

	gettimeofday(&tempo, NULL);
	printf("%03ld.%06ld:%s(%s:%d): ", (tempo.tv_sec % 600), tempo.tv_usec,
		file, func, line);
	va_start(args, line);
	saida = vprintf(format, args);
	va_end(args);
	fflush(stdout);
	return (saida);
}
