#include <gtk/gtk.h>
#include <string>
#include "controllerG.h"

GtkWidget *lbl_posicion, *lbl_resultado;
GtkWidget *txt_posicion;
GtkWidget *btn_aceptar, *btn_limpiar;
GtkWidget *box;

bool on_delete_event(GtkWidget *widget, GdkEvent *event, gpointer user_data ){
    gtk_main_quit();
    return false;
}

void limpiar(GtkButton *btn_limpiar, gpointer data){
    gtk_entry_set_text((GtkEntry *)txt_posicion, "");
    gtk_label_set_text((GtkLabel *)lbl_resultado, "...");
}

void aceptar(GtkButton *btn_aceptar, gpointer data){
    int n;
    const char *mensaje;

    n = atoi(gtk_entry_get_text(GTK_ENTRY(txt_posicion)));
    mensaje = g_strdup_printf("Valor: %i", secuenciaFibonacci(n));
    gtk_label_set_text((GtkLabel *)lbl_resultado, mensaje);
}

int main(int argc,char *argv[]){
    gtk_init(&argc, &argv);

    GtkWidget *window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"E2P2");
    gtk_window_set_default_size(GTK_WINDOW(window),300,300);
    gtk_container_set_border_width(GTK_CONTAINER(window), 15);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    lbl_posicion = gtk_label_new("Escriba una posicion para conocer su valor en la secuencia de Fibonacci:");
    lbl_resultado = gtk_label_new("...");
    txt_posicion = gtk_entry_new();
    btn_aceptar = gtk_button_new_with_label("Aceptar");
    btn_limpiar = gtk_button_new_with_label("Limpiar");

    box = gtk_vbox_new(0,0);

    gtk_box_pack_start(GTK_BOX(box),lbl_posicion,0,0,0);
    gtk_box_pack_start(GTK_BOX(box),txt_posicion,0,0,0);
    gtk_box_pack_start(GTK_BOX(box),lbl_resultado,0,0,0);
    gtk_box_pack_start(GTK_BOX(box),btn_aceptar,0,0,0);
    gtk_box_pack_start(GTK_BOX(box),btn_limpiar,0,0,0);

    gtk_container_add(GTK_CONTAINER(window),box);

    g_signal_connect(btn_aceptar,"clicked",G_CALLBACK(aceptar),NULL);
    g_signal_connect(btn_limpiar,"clicked",G_CALLBACK(limpiar),NULL);
    g_signal_connect(G_OBJECT(window),"delete-event",G_CALLBACK(on_delete_event),NULL);

    gtk_widget_show_all(window);

    gtk_main();
    return 0;
}

//g++ controllerG.h E2P2G.cpp -o main `pkg-config --cflags --libs gtk+-2.0` -Wno-deprecated-declarations