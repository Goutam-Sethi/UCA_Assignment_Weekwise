#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define LOGFILE "audit.log"
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int logFd, openFlags;
    mode_t filePerms;
    ssize_t numRead;
    char buf[BUF_SIZE];

    if (argc < 2) {
        printf("Usage:\n");
        printf("./auditlog --add \"message\"\n");
        printf("./auditlog --view\n");
        exit(-1);
    }


    if (strcmp(argv[1], "--add") == 0) {
        if (argc != 3) {
            printf("Usage: ./auditlog --add \"message\"\n");
            exit(-1);
        }

        openFlags = O_CREAT | O_WRONLY | O_APPEND;
        filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

        logFd = open(LOGFILE, openFlags, filePerms); //third argument only considered when new file is created

        if (logFd == -1) {
            printf("Error opening log file\n");
            exit(-1);
        }

        write(logFd, argv[2], strlen(argv[2]));
        write(logFd, "\n", 1);

        close(logFd);
    }
    else if (strcmp(argv[1], "--view") == 0) {
        logFd = open(LOGFILE, O_RDONLY);

        if (logFd == -1) {
            printf("Error opening log file\n");
            exit(-1);
        }

        int line = 1;
        char lineNo[20];

        sprintf(lineNo, "%d: ", line); //convert to string
        write(1, lineNo, strlen(lineNo)); //1 means stdout -> prints on the screen

        while ((numRead = read(logFd, buf, 1)) > 0) {
            write(1, buf, numRead);

            if (buf[0] == '\n') {
                line++;
                sprintf(lineNo, "%d: ", line);
                write(1, lineNo, strlen(lineNo));
            }
        }

        close(logFd);
    }
    else {
        printf("Invalid command\n");
    }

    return 0;
}