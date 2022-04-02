#include <gtk/gtk.h>


int main(int argc, char* argv[])
{
    gtk_init(&argc, &argv);

    GtkWidget *window;
    GtkWidget *image;
    GdkRGBA color;

    color.red = 2.4;
    color.green = 3.1;
    color.blue = 3.1;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
     
    gtk_window_set_title(GTK_WINDOW(window), "Let's play a game..."); 
    gtk_window_set_default_size(GTK_WINDOW(window), 1200, 800);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    gtk_widget_override_background_color(window, GTK_STATE_NORMAL, &color);
    //gtk_window_set_decorated(GTK_WINDOW(window), FALSE);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    image = gtk_image_new_from_file("hacked.png");

    //gtk_image_set_pixel_size(GTK_IMAGE(image), 1000);

    gtk_container_add(GTK_CONTAINER(window), image);

    gtk_widget_show_all(window);

    //printf("Pixels: %d\n", gtk_image_get_pixel_size(GTK_IMAGE(image)));

    gtk_main();
}
