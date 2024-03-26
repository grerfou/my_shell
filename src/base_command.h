#ifndef BASE_COMMAND_H
#define BASE_COMMAND_H

// Fonction pour exécuter la commande "echo"
void execute_echo(char **args);
// Fonction pour exécuter la commande "ls"
void execute_ls(char **args);
// Fonction pour exécuter la commande "pwd"
void execute_pwd();
// Fonction pour exécuter la commande "cd"
void execute_cd(char **args);
// Fonction pour exécuter la commande "mkdir"
void execute_mkdir(char **args);
// Fonction pour exécuter la commande "rmdir"
void execute_rmdir(char **args);
// Fonction pour exécuter la commande "rm"
void execute_rm(char **args);
// Fonction pour exécuter la commande "touch"
void execute_touch(char **args);
// Fonction pour exécuter la commande "cat"
void execute_cat(char **args);

#endif /* BASE_COMMAND_H */

