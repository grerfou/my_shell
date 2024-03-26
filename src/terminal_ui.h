#ifndef TERMINAL_UI_H
#define TERMINAL_UI_H

#include <gtk/gtk.h>

// Déclaration de la fonction pour créer l'interface utilisateur du terminal
GtkWidget *create_terminal_ui();

// Fonction pour exécuter la commande entrée par l'utilisateur
void execute_command(char *command);

#endif /* TERMINAL_UI_H */
