package week13_GUI_Event;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class ColorSelectionFrame extends JFrame {
    JButton red = new JButton("red");
    JButton blue = new JButton("blue");
    JButton green = new JButton("green");

    ColorSelectionFrame() {
        setBounds(100, 100, 500, 500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setTitle("Lab1 - Color Selection");

        Container c = getContentPane();

        JPanel buttonPanel = new JPanel();
        buttonPanel.add(red);
        buttonPanel.add(blue);
        buttonPanel.add(green);
        buttonPanel.setBackground(Color.gray);

        c.add(buttonPanel, BorderLayout.NORTH);
        c.setBackground(Color.CYAN);

        red.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                ColorSelectionFrame.this.getContentPane().setBackground(Color.red);
            }
        });
        blue.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                ColorSelectionFrame.this.getContentPane().setBackground(Color.blue);
            }
        });
        green.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                ColorSelectionFrame.this.getContentPane().setBackground(Color.green);
            }
        });

        setVisible(true);
    }
}

public class Lab1_colorChange {
    public static void main(String[] args) {
        ColorSelectionFrame frame = new ColorSelectionFrame();
    }
}
