#include "main.h"

/**
 * execute_command - Executes the given command.
 * @command: The command to execute.
 * Return: The exit status of the executed command.
 */
int execute_command(char *command) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        free(command);
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        execute_child_process(command);
    } else {
        return wait_child_process(pid, command);
    }
}

/**
 * execute_child_process - Executes the command in the child process.
 * @command: The command to execute.
 * Return: This function does not return; it exits the child process.
 */
void execute_child_process(char *command) {
    char **args;
    args = tokenize_command(command);

    if (args[0] == NULL) {
        free(command);
        exit(EXIT_SUCCESS);
    }

    if (strcmp(args[0], "env") == 0) {
        print_environment();
    }

    if (strchr(args[0], '/') != NULL) {
        execute_absolute_path(args);
    } else {
        execute_relative_path(args);
    }

    // If none of the conditions above are met, command not found
    fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
    free(command);
    exit(127);
}

/**
 * wait_child_process - Waits for the child process to finish.
 * @pid: The process ID of the child process.
 * @command: The command string.
 * Return: The exit status of the child process.
 */
int wait_child_process(pid_t pid, char *command) {
    int status;
    waitpid(pid, &status, 0);
    free(command);
    if (WIFEXITED(status)) {
        return WEXITSTATUS(status);
    } else {
        return 1;
    }
}
