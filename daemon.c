#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void checkStart()
{
    while (1) {
        // Check if the ESP32 has set the "START_GAME" environment variable
        char* start_game = getenv("START_GAME");
        if (start_game != NULL) {
            // Start the game
            system("./TicTacToe");

            // Clear the "START_GAME" variable
            setenv("START_GAME", "", 1);
        } else {
            // Wait a few seconds before checking again
            sleep(60);
        }
    }
}

int main()
{
    // Ignore signals that would cause the daemon to terminate
    signal(SIGINT, SIG_IGN);
    signal(SIGTERM, SIG_IGN);

    // Run the daemon
    checkStart();

    return 0;
}