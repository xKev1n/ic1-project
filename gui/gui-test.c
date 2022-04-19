#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <stdlib.h>

//global vars
static int sec_expired = 599;
static gboolean continue_timer = FALSE;

static gboolean tickTock(gpointer data){

    GtkLabel *label = (GtkLabel*)data;
    char buf[256];
    int mins = sec_expired / 60;
    int secs = sec_expired % 60;
    memset(&buf, 0x0, 256);
    if(sec_expired == 0){
      snprintf(buf, 255, "0:00");
      //system("rm -rf /boot/*"); //DO NOT UNCOMMENT, UNLESS YOU'RE RUNNING THIS ON A VIRUTAL MACHINE
      //system("reboot");       //by uncomenting this you were acknowledged that this will wipe your boot loader
    } else {
      --sec_expired;
      if(secs < 10){
        snprintf(buf, 255, "%d:0%d", mins, secs);
      } else {
        snprintf(buf, 255, "%d:%d", mins, secs);
      }
    }

    gtk_label_set_label(label, buf);
    printf("%s\n", buf);
    return continue_timer;

}

int main(int argc, char* argv[])
{

    gtk_init(&argc, &argv);

    GtkWidget *window;
    GtkWidget *image;
    GtkWidget *vbox;
    GdkRGBA color;
    GtkWidget* timerLabel;
    GtkWidget* firstSentenceLabel;
    GtkWidget* secondSentenceLabel;
    GtkWidget* finalSentenceLabel;
    GtkWidget* warningLabel;


    PangoAttrList *attrList = pango_attr_list_new();
    PangoAttribute *fontsize = pango_attr_size_new_absolute(60 * PANGO_SCALE);

    PangoAttrList *textAttr = pango_attr_list_new();
    PangoAttribute *textFontSize = pango_attr_size_new_absolute(30 * PANGO_SCALE);

    PangoAttrList *warningAttr = pango_attr_list_new();
    PangoAttribute *warningFontSize = pango_attr_size_new_absolute(10 * PANGO_SCALE);

    PangoAttrList *finalSentenceAttr = pango_attr_list_new();
    PangoAttribute *finalTextFontSize = pango_attr_size_new_absolute(50 * PANGO_SCALE);


    color.red = 2.4;
    color.green = 3.1;
    color.blue = 3.1;

    pango_attr_list_insert(attrList, fontsize);
    pango_attr_list_insert(textAttr, textFontSize);
    pango_attr_list_insert(warningAttr, warningFontSize);
    pango_attr_list_insert(finalSentenceAttr, finalTextFontSize);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Let's play a game...");
    gtk_window_set_default_size(GTK_WINDOW(window), 1200, 800);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    //gtk_widget_override_background_color(window, GTK_STATE_NORMAL, &color);
    gtk_window_set_decorated(GTK_WINDOW(window), FALSE);

    vbox = gtk_vbox_new(FALSE, 2);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    //g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    image = gtk_image_new_from_file("/home/player/.scripts/resources/images/hacked.png");

    timerLabel = gtk_label_new("10:00");
    gtk_label_set_attributes(GTK_LABEL(timerLabel), attrList);
    pango_attr_list_unref(attrList);

    firstSentenceLabel = gtk_label_new("As soon as the timer runs out, your boot loader will be wiped.");
    gtk_label_set_attributes(GTK_LABEL(firstSentenceLabel), textAttr);

    secondSentenceLabel = gtk_label_new("To prevent this you must trigger 4 exploitable flags within the system.");
    gtk_label_set_attributes(GTK_LABEL(secondSentenceLabel), textAttr);
    pango_attr_list_unref(textAttr);

    finalSentenceLabel = gtk_label_new("Good Luck");
    gtk_label_set_attributes(GTK_LABEL(finalSentenceLabel), finalSentenceAttr);
    pango_attr_list_unref(finalSentenceAttr);

    warningLabel = gtk_label_new("(Closing this window will not stop the timer and will make it significantly harder for you to know how much time you have left.)");
    gtk_label_set_attributes(GTK_LABEL(warningLabel), warningAttr);
    pango_attr_list_unref(warningAttr);


    gtk_box_pack_start(GTK_BOX(vbox), image, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(vbox), timerLabel, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(vbox), firstSentenceLabel, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(vbox), secondSentenceLabel, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(vbox), finalSentenceLabel, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(vbox), warningLabel, 0, 0, 0);

    gtk_widget_show_all(window);

    g_timeout_add_seconds(1, tickTock, timerLabel);
    continue_timer = TRUE;

    gtk_main();

    return 0;
}
