#include <gtk/gtk.h>
#include "terminal_ui.h"

int main(int argc, char *argv[]) {
    // Initialiser GTK
    gtk_init(&argc, &argv);

    // Créer l'interface utilisateur du terminal
    GtkWidget *window = create_terminal_ui();

    // Afficher tous les widgets dans la fenêtre
    gtk_widget_show_all(window);

    // Démarrer la boucle principale de GTK
    gtk_main();

    return 0;
}
