#include <gtk/gtk.h>
#include <unistd.h>

char* getTime(){
	return NULL;


}


int main(int argc, char* argv[])
{
    gtk_init(&argc, &argv);

    GtkWidget *window;
    GtkWidget *image;
    GtkWidget *fixed;
    GdkRGBA color;
    GtkWidget* label;

    double OGtimeSecs = 300;
    double currTimeSecs = OGtimeSecs;
    char currTimeStr[20];
    sprintf(currTimeStr, "%f", currTimeSecs / 60);
    char textus1[200] = "<b><span foreground=\"red\">";
    char textus2[20] = "</span></b>";
    strcat(textus1, currTimeStr);
    printf("%s\n", textus1);
    strcat(textus1, textus2);
    printf("%s\n", textus1);

    PangoAttrList *attrList = pango_attr_list_new();
    PangoAttribute *fontsize = pango_attr_size_new_absolute(60 * PANGO_SCALE);


    color.red = 2.4;
    color.green = 3.1;
    color.blue = 3.1;

    pango_attr_list_insert(attrList, fontsize);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
     
    gtk_window_set_title(GTK_WINDOW(window), "Let's play a game..."); 
    gtk_window_set_default_size(GTK_WINDOW(window), 1200, 800);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    gtk_widget_override_background_color(window, GTK_STATE_NORMAL, &color);
    //gtk_window_set_decorated(GTK_WINDOW(window), FALSE);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    fixed = gtk_fixed_new();
	
    image = gtk_image_new_from_file("resources/images/hacked.png");

    label = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(label), textus1);
    gtk_label_set_attributes(GTK_LABEL(label), attrList);

    pango_attr_list_unref(attrList);

    gtk_fixed_put(GTK_FIXED(fixed), image, 0, 0);
    gtk_fixed_put(GTK_FIXED(fixed), label, 530, 650);

    gtk_container_add(GTK_CONTAINER(window), fixed);

    gtk_widget_show_all(window);

    //printf("Pixels: %d\n", gtk_image_get_pixel_size(GTK_IMAGE(image)));

    gtk_main();
}
