package week12_Swing;

import javax.swing.*;
import java.awt.*;

class MyTimer extends Thread {
    JLabel label = new JLabel();
     MyTimer() {
         JFrame frame = new JFrame();
         frame.setTitle("My Timer");
         frame.setSize(300,100);
         frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

         Container c = frame.getContentPane();
         c.add(label);

         frame.setVisible(true);
     }

     @Override
     public void run() {
         super.run();
         long currentMillis = System.currentTimeMillis();
         while (true) {
             long elapsed = System.currentTimeMillis() - currentMillis;
             long ms, sec, min;

             ms = elapsed % 1000;
             sec = elapsed / 1000 % 60;
             min = elapsed / 1000 / 60;
            label.setFont(new Font("고딕체", 0,40));

             label.setText(String.format("%02d:%02d:%03d",min,sec,ms));
         }
     }
 }

public class Lab4_timer {
    public static void main(String[] args) {
        MyTimer timer = new MyTimer();
        timer.start();
    }
}
