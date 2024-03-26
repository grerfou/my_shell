#include <gtk/gtk.h>
#include "terminal_ui.h"
#include "base_command.h"

// Fonction callback appelée lorsque l'utilisateur appuie sur Entrée
static gboolean on_entry_activate(GtkWidget *entry, gpointer data) {
    const gchar *command = gtk_entry_get_text(GTK_ENTRY(entry));

    // Exécuter la commande
    execute_command((char *) command);

    // Effacer le contenu de l'entrée
    gtk_entry_set_text(GTK_ENTRY(entry), "");

    return TRUE;
}

void execute_command(char *command) {
    // Tableau pour stocker les arguments de la commande
    char *args[64];
    char *token;
    int i = 0;

    // Diviser la commande en arguments
    token = strtok(command, " \t\r\n\a");
    while (token != NULL && i < 63) {
        args[i] = token;
        i++;
        token = strtok(NULL, " \t\r\n\a");
    }
    args[i] = NULL;

    // Vérifier si la commande est une commande de base
    if (strcmp(args[0], "echo") == 0) {
        execute_echo(args);
    } else if (strcmp(args[0], "ls") == 0) {
        execute_ls(args);
    } else if (strcmp(args[0], "pwd") == 0) {
        execute_pwd();
    } else if (strcmp(args[0], "cd") == 0) {
        execute_cd(args);
    } else if (strcmp(args[0], "mkdir") == 0) {
        execute_mkdir(args);
    } else if (strcmp(args[0], "rmdir") == 0) {
        execute_rmdir(args);
    } else if (strcmp(args[0], "rm") == 0) {
        execute_rm(args);
    } else if (strcmp(args[0], "touch") == 0) {
        execute_touch(args);
    } else if (strcmp(args[0], "cat") == 0) {
        execute_cat(args);
    } else {
        // Si la commande n'est pas reconnue, afficher un message d'erreur
        printf("Commande inconnue: %s\n", args[0]);
    }
}

// Fonction pour créer l'interface utilisateur du terminal
GtkWidget *create_terminal_ui() {
    // Créer une nouvelle fenêtre
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Mon Terminal");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    // Créer un conteneur de boîte verticale
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Créer un widget de texte pour afficher la sortie du terminal
    GtkWidget *output = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(output), FALSE);
    gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(output), FALSE);
    gtk_box_pack_start(GTK_BOX(vbox), output, TRUE, TRUE, 0);

    // Créer un widget d'entrée pour saisir les commandes
    GtkWidget *entry = gtk_entry_new();
    gtk_box_pack_end(GTK_BOX(vbox), entry, FALSE, TRUE, 0);

    // Connecter le signal "activate" (l'utilisateur appuie sur Entrée) à la fonction callback
    g_signal_connect(entry, "activate", G_CALLBACK(on_entry_activate), output);

    // Retourner la fenêtre
    return window;
}
