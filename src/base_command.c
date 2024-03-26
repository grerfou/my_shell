#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "base_command.h"

// Fonction pour exécuter la commande "echo"
void execute_echo(char **args) {
    int i = 1;
    while (args[i] != NULL) {
        printf("%s ", args[i]);
        i++;
    }
    printf("\n");
}

// Fonction pour exécuter la commande "ls"
void execute_ls(char **args) {
    DIR *dp;
    struct dirent *dirp;

    if ((dp = opendir(".")) == NULL) {
        perror("Erreur lors de l'ouverture du répertoire");
        exit(1);
    }

    while ((dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp->d_name);
    }
    closedir(dp);
}

// Fonction pour exécuter la commande "pwd"
void execute_pwd() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd);
    } else {
        perror("getcwd() error");
        exit(1);
    }
}

// Fonction pour exécuter la commande "cd"
void execute_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "cd: Argument manquant\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("cd failed");
        }
    }
}

// Fonction pour exécuter la commande "mkdir"
void execute_mkdir(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "mkdir: Argument manquant\n");
    } else {
        if (mkdir(args[1], 0777) != 0) {
            perror("mkdir failed");
        }
    }
}

// Fonction pour exécuter la commande "rmdir"
void execute_rmdir(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "rmdir: Argument manquant\n");
    } else {
        if (rmdir(args[1]) != 0) {
            perror("rmdir failed");
        }
    }
}

// Fonction pour exécuter la commande "rm"
void execute_rm(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "rm: Argument manquant\n");
    } else {
        if (remove(args[1]) != 0) {
            perror("rm failed");
        }
    }
}

// Fonction pour exécuter la commande "touch"
void execute_touch(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "touch: Argument manquant\n");
    } else {
        int fd = open(args[1], O_CREAT | O_WRONLY | O_EXCL, 0644);
        if (fd == -1) {
            perror("touch failed");
        } else {
            close(fd);
        }
    }
}

// Fonction pour exécuter la commande "cat"
void execute_cat(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "cat: Argument manquant\n");
    } else {
        FILE *file = fopen(args[1], "r");
        if (file == NULL) {
            perror("cat failed");
        } else {
            char buffer[1024];
            while (fgets(buffer, sizeof(buffer), file)) {
                printf("%s", buffer);
            }
            fclose(file);
        }
    }
}

