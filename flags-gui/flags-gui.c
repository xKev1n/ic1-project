#include <stdio.h>
#include <gtk/gtk.h>

//TODO: functions for button triggers

int main(int argc, char *argv[]){

    gtk_init(&argc, &argv);

    GtkWidget *window;
    GtkWidget *table;
    GtkWidget *firstFlagLabel;
    GtkWidget *firstFlagEntry;
    GtkWidget *firstSubmitButton;
    GtkWidget *secondFlagLabel;
    GtkWidget *secondFlagEntry;
    GtkWidget *secondSubmitButton;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Flags");
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 300);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    g_signal_connect(GTK_CONTAINER(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    table = gtk_table_new(10, 3, 0); //the 10 is an overkill, will be changed
    gtk_container_add(GTK_CONTAINER(window), table);

    firstFlagLabel = gtk_label_new("Flag 1");
    secondFlagLabel = gtk_label_new("Flag 2");

    firstFlagEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(firstFlagEntry), "Flag 1");
    secondFlagEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(secondFlagEntry), "Flag 2");

    firstSubmitButton = gtk_button_new_with_label("Submit");

    secondSubmitButton = gtk_button_new_with_label("Submit");

    gtk_table_attach(GTK_TABLE(table), firstFlagLabel, 0, 1, 0, 1, GTK_FILL, GTK_FILL, 4, 4);
    gtk_table_attach(GTK_TABLE(table), firstFlagEntry, 1, 2, 0, 1, GTK_FILL, GTK_FILL, 4, 4);
    gtk_table_attach(GTK_TABLE(table), firstSubmitButton, 2, 3, 0, 1, GTK_FILL, GTK_FILL, 4, 4);
    gtk_table_attach(GTK_TABLE(table), secondFlagLabel, 0, 1, 1, 2, GTK_FILL, GTK_FILL, 4, 4);
    gtk_table_attach(GTK_TABLE(table), secondFlagEntry, 1, 2, 1, 2, GTK_FILL, GTK_FILL, 4, 4);
    gtk_table_attach(GTK_TABLE(table), secondSubmitButton, 2, 3, 1, 2, GTK_FILL, GTK_FILL, 4, 4);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;

}
