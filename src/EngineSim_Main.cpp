/*  
    This program simulates an engine for developement of the ECU software

    Author: Nicholas Kent
    
    Date: 20/12/18

    To Do List
    - Open a Gui with running details
    - Get program to run at idle as a four cyclinder
    - Work out timing  
    - Get crank position in deg

*/




// Standard Includes
#include <iostream>
#include <chrono>
#include <gtk/gtk.h>

// Namespaces

using namespace std;
using namespace chrono;

// Custom Includes




int main(int   argc,char *argv[])
{	


    // GTK stuff
    static GtkWidget *window = NULL;
    GtkWidget *hbox;
    GtkWidget *vbox;
    GtkWidget *frame;
    GtkWidget *label;

    /* Initialise GTK */
    gtk_init(&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    //gtk_signal_connect (GTK_OBJECT (window), "destroy", GTK_SIGNAL_FUNC(gtk_main_quit), NULL);

    gtk_window_set_title (GTK_WINDOW (window), "Engine Simulator");
    vbox = gtk_vbox_new (FALSE, 5);
    hbox = gtk_hbox_new (FALSE, 5);
    gtk_container_add (GTK_CONTAINER (window), hbox);
    gtk_box_pack_start (GTK_BOX (hbox), vbox, FALSE, FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (window), 5);
      
    frame = gtk_frame_new ("Cylinder 1");
    label = gtk_label_new ("O");
    gtk_container_add (GTK_CONTAINER (frame), label);
    gtk_box_pack_start (GTK_BOX (vbox), frame, FALSE, FALSE, 0);

    label->set_markup("<span background=\"black\" foreground=\"red\">Gin and Tonic</span>");

    frame = gtk_frame_new ("Cylinder 2");
    label = gtk_label_new ("O");
    gtk_container_add (GTK_CONTAINER (frame), label);
    gtk_box_pack_start (GTK_BOX (hbox), frame, FALSE, FALSE, 0);

    frame = gtk_frame_new ("Cylinder 3");
    label = gtk_label_new ("O");
    gtk_container_add (GTK_CONTAINER (frame), label);
    gtk_box_pack_start (GTK_BOX (hbox), frame, FALSE, FALSE, 0);

    frame = gtk_frame_new ("Cylinder 4");
    label = gtk_label_new ("O");
    gtk_container_add (GTK_CONTAINER (frame), label);
    gtk_box_pack_start (GTK_BOX (hbox), frame, FALSE, FALSE, 0);
    
    gtk_widget_show_all (window);

    gtk_main ();
  
    



    //unsigned int mainTick = 0;
	int loop = 0;
    //double crankAngle = 0; // This can be any number between 0 and 359
    auto timeZero = high_resolution_clock::now();
    //double degPerMricoSec = 0.018;

    auto prevTime = timeZero;
    //int microSec;

	while(loop)
	{	
        // Get current time
        auto checkTime = high_resolution_clock::now();
        
        // Work out diffence between curren time and previous time
        auto elapsedTime = checkTime - prevTime;

        // Store current time
        prevTime = checkTime;
        
        // Convert time difference for output
        //duration<double, microseconds> microSec = checkTime - prevTime;    
        
        high_resolution_clock::time_point timeOP = prevTime;
        



        //crankAngle = crankAngle + (microSec*0.018);
        //cout << "Crank Angle: " << microSec.count() << " @ " << high_resolution_clock::to_time_t(timeOP) << " uS" << endl;
		//mainTick++;
        loop--;
	}

    
    time_t time_Start = high_resolution_clock::to_time_t(timeZero);
    time_t time_End = high_resolution_clock::to_time_t(prevTime);
    cout << "Time start = " << time_Start << endl;
    cout << "Time end = " << time_End << endl;

    //duration::to_stream(timeZero);
   // auto theTime = high_resolution_clock::now();
    //long testTime = chrono::duration_cast<chrono::microseconds>(theTime).count();
   // printf("Time Out %ld\n", testTime);
    
    //cout << "End time = " << testTime << " us\n";
}
