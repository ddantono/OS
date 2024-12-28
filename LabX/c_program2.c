#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pipe(fd);
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        close(fd[1]); // Close unused write end
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));
        printf("Child read the data sent by the parent: %s\n", buffer);
        close(fd[0]);
    } else {
        // Parent process
        close(fd[0]); // Close unused read end
        const char *message = "Parent has written a message in the pipe";
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]);
    }

    return 0;
}
