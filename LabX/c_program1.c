#include <stdio.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 3; i++) {
        if (fork() == 0) {
            // Child process
            printf("Child Process PID: %d\n", getpid());
            return 0; // Ensure the child doesn't fork further
        }
    }
    return 0;
}
