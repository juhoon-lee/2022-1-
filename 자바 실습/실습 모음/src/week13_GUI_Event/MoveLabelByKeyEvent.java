package week13_GUI_Event;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

class MoveLabel extends JFrame {
    JLabel label = new JLabel("방향키!");

    MoveLabel() {
        setBounds(300, 100, 300, 300);
        setTitle("Move Label Frame");
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        Container c = getContentPane();

        c.add(label,BorderLayout.CENTER);
        c.setBackground(Color.yellow);
        setVisible(true);
        c.setFocusable(true);
        c.requestFocus();

        c.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                super.keyPressed(e);
                int code = e.getKeyCode();
                if (code == KeyEvent.VK_UP) {
                    label.setLocation(label.getX(),label.getY()-10);
                } else if (code == KeyEvent.VK_DOWN) {
                    label.setLocation(label.getX(),label.getY()+10);
                }
                else if (code == KeyEvent.VK_LEFT) {
                    label.setLocation(label.getX()-10, label.getY());
                } else if (code == KeyEvent.VK_RIGHT) {
                    label.setLocation(label.getX()+10,label.getY());
                }
            }
        });
    }
}

public class MoveLabelByKeyEvent {
    public static void main(String[] args) {
        MoveLabel m = new MoveLabel();
    }
}
