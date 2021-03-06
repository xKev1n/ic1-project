#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <stdlib.h>


//Flags
static const char* flag1 = "UlLWnC5EzCU2jsnEt8v8";
static const char* flag2 = "ShUvQ0HaVrVtss3RZTgl";
static const char* flag3 = "WAWb7QOIfp8OQeMRfuiY";
static const char* flag4 = "K7T173uQmno5Cd7rdGg5";

//counter
static int counter = 0;

static void checkFirstFlag(GtkWidget *widget, gpointer data){

    const char* text = gtk_entry_get_text(GTK_ENTRY(data));
    if(strcmp(flag1, text) == 0){
      //printf("1. Equals\n");
      counter++;
      gtk_button_set_label(GTK_BUTTON(widget), "Correct");
      gtk_widget_set_sensitive(widget, FALSE);
      gtk_widget_set_sensitive(GTK_WIDGET(data), FALSE);
    } else {
      //printf("1. Doesn't equal\n");
      gtk_entry_set_text(GTK_ENTRY(data), "Incorrect");
    }
}

static void checkSecondFlag(GtkWidget *widget, gpointer data){
    const char* text = gtk_entry_get_text(GTK_ENTRY(data));
    if(strcmp(flag2, text) == 0){
      //printf("2. Equals\n");
      counter++;
      gtk_button_set_label(GTK_BUTTON(widget), "Correct");
      gtk_widget_set_sensitive(widget, FALSE);
      gtk_widget_set_sensitive(GTK_WIDGET(data), FALSE);
    } else {
      //printf("2. Doesn't equal\n");
      gtk_entry_set_text(GTK_ENTRY(data), "Incorrect");
    }
}

static void checkThirdFlag(GtkWidget *widget, gpointer data){
    const char* text = gtk_entry_get_text(GTK_ENTRY(data));
    if(strcmp(flag3, text) == 0){
      //printf("3. Equals\n");
      counter++;
      gtk_button_set_label(GTK_BUTTON(widget), "Correct");
      gtk_widget_set_sensitive(widget, FALSE);
      gtk_widget_set_sensitive(GTK_WIDGET(data), FALSE);
    } else {
      //printf("3. Doesn't equal\n");
      gtk_entry_set_text(GTK_ENTRY(data), "Incorrect");
    }
}

static void checkFourthFlag(GtkWidget *widget, gpointer data){
   const char* text = gtk_entry_get_text(GTK_ENTRY(data));
   if(strcmp(flag4, text) == 0){
     //printf("3. Equals\n");
     counter++;
     gtk_button_set_label(GTK_BUTTON(widget), "Correct");
     gtk_widget_set_sensitive(widget, FALSE);
     gtk_widget_set_sensitive(GTK_WIDGET(data), FALSE);
   } else {
     //printf("3. Doesn't equal\n");
     gtk_entry_set_text(GTK_ENTRY(data), "Incorrect");
   }
}

static void ctrCheck(GtkWidget *widget, gpointer data){
  if(counter == 4){
    system("kill `pgrep gui-test`");
  }
}



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
    GtkWidget *thirdFlagLabel;
    GtkWidget *thirdFlagEntry;
    GtkWidget *thirdSubmitButton;
    GtkWidget *fourthFlagLabel;
    GtkWidget *fourthFlagEntry;
    GtkWidget *fourthSubmitButton;
    GtkWidget *allSubmitButton;
    GtkWidget *warningLabel;

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
    thirdFlagLabel = gtk_label_new("Flag 3");
    fourthFlagLabel = gtk_label_new("Flag 4");
    warningLabel = gtk_label_new("DO NOT CLOSE THIS WINDOW, it cannot be opened again");

    firstFlagEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(firstFlagEntry), "Flag 1");
    secondFlagEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(secondFlagEntry), "Flag 2");
    thirdFlagEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(thirdFlagEntry), "Flag 3");
    fourthFlagEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(fourthFlagEntry), "Flag 4");

    firstSubmitButton = gtk_button_new_with_label("Submit");
    g_signal_connect(firstSubmitButton, "clicked", G_CALLBACK(checkFirstFlag), firstFlagEntry);
    secondSubmitButton = gtk_button_new_with_label("Submit");
    g_signal_connect(secondSubmitButton, "clicked", G_CALLBACK(checkSecondFlag), secondFlagEntry);
    thirdSubmitButton = gtk_button_new_with_label("Submit");
    g_signal_connect(thirdSubmitButton, "clicked", G_CALLBACK(checkThirdFlag), thirdFlagEntry);
    fourthSubmitButton = gtk_button_new_with_label("Submit");
    g_signal_connect(fourthSubmitButton, "clicked", G_CALLBACK(checkFourthFlag), fourthFlagEntry);
    allSubmitButton = gtk_button_new_with_label("Submit all");
    g_signal_connect(allSubmitButton, "clicked", G_CALLBACK(ctrCheck), NULL);

    gtk_table_attach(GTK_TABLE(table), firstFlagLabel, 0, 1, 0, 1, GTK_FILL, GTK_FILL, 4, 4);
    gtk_table_attach(GTK_TABLE(table), firstFlagEntry, 1, 2, 0, 1, GTK_FILL, GTK_FILL, 4, 4);
    gtk_table_attach(GTK_TABLE(table), firstSubmitButton, 2, 3, 0, 1, GTK_FILL, GTK_FILL, 4, 4);
    gtk_table_attach(GTK_TABLE(table), secondFlagLabel, 0, 1, 1, 2, GTK_FILL, GTK_FILL, 4, 4);
    gtk_table_attach(GTK_TABLE(table), secondFlagEntry, 1, 2, 1, 2, GTK_FILL, GTK_FILL, 4, 4);
    gtk_table_attach(GTK_TABLE(table), secondSubmitButton, 2, 3, 1, 2, GTK_FILL, GTK_FILL, 4, 4);
    gtk_table_attach(GTK_TABLE(table), thirdFlagLabel, 0, 1, 2, 3, GTK_FILL, GTK_FILL, 4, 4);
    gtk_table_attach(GTK_TABLE(table), thirdFlagEntry, 1, 2, 2, 3, GTK_FILL, GTK_FILL, 4, 4);
    gtk_table_attach(GTK_TABLE(table), thirdSubmitButton, 2, 3, 2, 3, GTK_FILL, GTK_FILL, 4, 4);
    gtk_table_attach(GTK_TABLE(table), fourthFlagLabel, 0, 1, 3, 4, GTK_FILL, GTK_FILL, 4, 4);
    gtk_table_attach(GTK_TABLE(table), fourthFlagEntry, 1, 2, 3, 4, GTK_FILL, GTK_FILL, 4, 4);
    gtk_table_attach(GTK_TABLE(table), fourthSubmitButton, 2, 3, 3, 4, GTK_FILL, GTK_FILL, 4, 4);
    gtk_table_attach(GTK_TABLE(table), allSubmitButton, 1, 2, 4, 5, GTK_FILL, GTK_FILL, 4, 4);
    gtk_table_attach(GTK_TABLE(table), warningLabel, 1, 2, 5, 6, GTK_FILL, GTK_FILL, 4, 4);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;

}
