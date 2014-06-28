#include <gtk/gtk.h>

/* Compilar con:
 * gcc `pkg-config --cflags gtk+-3.0` -o 001-hola 001-hola.c `pkg-config --libs gtk+-3.0`
 */

int main (int argc, char *argv[]) {
    GtkWidget *window;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Hola");
    gtk_widget_show(window);
    gtk_main();
}

