#include "chess.h"

int	main(void)
{
	char	*fen;
	t_board	board;

	board = new_board();
	say("diga um fen\n", DEB);
	say("", DEB);
	if (get_next_line(STDIN_FILENO, &fen) == 1)
	{
		print_fen(fen, DEB);
		set_board(board, fen);
		print_board(board, DEB);
		free(fen);
	}
	else
		say("gnl failed\n", DEB);
	free(board.squares);
	return (0);
}
