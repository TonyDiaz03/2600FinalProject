TicTacToe: TicTacToe.c
    gcc -o TicTacToe TicTacToe.c

daemon: daemon.c
    gcc -o daemon daemon.c

run: TicTacToe
    ./TicTacToe

run-daemon: daemon
    ./daemon &
