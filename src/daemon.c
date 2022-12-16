#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
  // Run the program in the background as a daemon
  pid_t pid = fork();
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }
  umask(0);
  pid_t sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }
  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }
  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  // Loop indefinitely
  while (1) {
    // Check if ESP32 is present
    int esp32_present = check_esp32();
    if (esp32_present) {
      // Start the Tic-Tac-Toe game
      printf("Starting TicTacToe game...\n");
      main();
    }

    // Sleep for 1 second before checking again
    sleep(1);
  }

  return 0;
}
