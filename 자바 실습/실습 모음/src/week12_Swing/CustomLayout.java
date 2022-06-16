package week12_Swing;

import javax.swing.*;
import java.awt.*;

class NullLayout extends JFrame {
    NullLayout() {
        setSize(500,500);
        setTitle("Null Layout");
        setLocation(2000,500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        Container c = getContentPane();
        c.setLayout(null);

        for (int i = 0; i <100; i++) {
            JLabel label = new JLabel(""+i);
            label.setForeground(Color.blue);
            label.setOpaque(true);
            label.setBackground(Color.gray);
            label.setBounds(10*i,10*i,20,20);
            c.add(label);
        }

        setVisible(true);
    }
}

public class CustomLayout {
    public static void main(String[] args) {
        NullLayout frame = new NullLayout();
    }
}
