/**
 * Copyright (c) 2000 itopia
 * All Rights Reserved
 *
 * AppletButton.java
 * $Id$
 *
 */


import java.awt.*;
import java.util.*;
import java.applet.Applet;

/**
 *
 * Simple Button which opens a new window.
 * 
 * @author		bub
 * @version		$Id$
 * @since		28.7.00
 * @see			java.applet.Applet
 * 
 */
public class AppletButton extends Applet implements Runnable {
    int frameNumber = 1;
    String windowClass;
    String buttonText;
    String windowTitle;
    String font;
    int requestedWidth = 0;
    int requestedHeight = 0;
    Button button;
    Thread windowThread;
    Label label;
    boolean pleaseCreate = false;

    public void init() {
        windowClass = getParameter("WINDOWCLASS");
        if (windowClass == null) {
            windowClass = "TestWindow";
        }

        buttonText = getParameter("BUTTONTEXT");
        if (buttonText == null) {
            buttonText = "Click here to bring up a " + windowClass;
        }

        windowTitle = getParameter("WINDOWTITLE");
        if (windowTitle == null) {
            windowTitle = windowClass;
        }

        String windowWidthString = getParameter("WINDOWWIDTH");
        if (windowWidthString != null) {
            try {
                requestedWidth = Integer.parseInt(windowWidthString);
            } catch (NumberFormatException e) {
                //Use default width.
            }
        }
 
        String windowHeightString = getParameter("WINDOWHEIGHT");
        if (windowHeightString != null) {
            try {
                requestedHeight = Integer.parseInt(windowHeightString);
            } catch (NumberFormatException e) {
                //Use default height.
            }
        }
 
        setLayout(new GridLayout(2,0));
        add(button = new Button(buttonText));
        font = getParameter("FONT");
        if (font != null) {
	        button.setFont(new Font(font, Font.PLAIN, 20));
		} else {
	        button.setFont(new Font("Serif", Font.PLAIN, 20));
		}

        add(label = new Label("", Label.CENTER));
    }

    public void start() {
        if (windowThread == null) {
            windowThread = new Thread(this, "Bringing Up " + windowClass);
            windowThread.start();
        }
    }

    public synchronized void run() {
        Class windowClassObject = null;
        Class tmp = null;
        String name = null;
        
        // Make sure the window class exists and is really a Frame.
        // This has the added benefit of pre-loading the class,
        // which makes it much quicker for the first window to come up.
        try {
            windowClassObject = Class.forName(windowClass);
        } catch (Exception e) {
            // The specified class isn't anywhere that we can find.
            label.setText("Can't create window: Couldn't find class "
                              + windowClass);
            button.setEnabled(false);
            return;
        }

        // Find out whether the class is a Frame.
        for (tmp = windowClassObject, name = tmp.getName();
             !( name.equals("java.lang.Object") ||
                name.equals("java.awt.Frame") ); ) {
            tmp = tmp.getSuperclass();
            name = tmp.getName();
        }
        if ((name == null) || name.equals("java.lang.Object")) {
            //We can't run; ERROR; print status, never bring up window
            label.setText("Can't create window: "
                              + windowClass +
                          " isn't a Frame subclass.");
            button.setEnabled(false);
            return;
        } else if (name.equals("java.awt.Frame")) { 
            //Everything's OK. Wait until we're asked to create a window.
            while (windowThread != null) {
                while (pleaseCreate == false) {
                    try {
                        wait();
                    } catch (InterruptedException e) {
                    }
                }

                //We've been asked to bring up a window.
                pleaseCreate = false;
                Frame window = null;
                try {
                    window = (Frame)windowClassObject.newInstance();
                } catch (Exception e) {
                    label.setText("Couldn't create instance of class "
                                  + windowClass);
                    button.setEnabled(false);
                    return;
                }
                if (frameNumber == 1) {
                    window.setTitle(windowTitle);
                } else {
                    window.setTitle(windowTitle + ": " + frameNumber);
                }
                frameNumber++;

                //Set the window's size.
                window.pack();
                if ((requestedWidth > 0) | (requestedHeight > 0)) {
                    window.setSize(Math.max(requestedWidth,
                                           window.getSize().width),
                                  Math.max(requestedHeight,
                                           window.getSize().height));
                }

                window.show();
                label.setText("");
            }
        }
    }
                
    public synchronized boolean action(Event event, Object what) {
        if (event.target instanceof Button) {
            //signal the window thread to build a window
            label.setText("Please wait while the window comes up...");
            pleaseCreate = true;
            notify();
        } 
        return true;
    }
}

class TestWindow extends Frame {
    public TestWindow() {
        setSize(300, 300);
    }
}
