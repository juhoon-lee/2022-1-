package week13_GUI_Event;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class MoveIcon extends JFrame {
    JButton leftButton = new JButton("leftButton");
    JButton rightButton = new JButton("rightButton");
    JButton upButton = new JButton("upButton");
    JButton downButton = new JButton("downButton");
    JLabel iconLabel = new JLabel();

    MoveIcon() {
        setBounds(100, 100, 500, 500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setTitle("Lab2 - Move Icon");

        Container c = getContentPane();
        c.setBackground(Color.cyan);

        // 패널 만들기
        JPanel buttonPanel = new JPanel();
        buttonPanel.add(leftButton);
        buttonPanel.add(rightButton);
        buttonPanel.add(upButton);
        buttonPanel.add(downButton);
        buttonPanel.setBackground(Color.yellow);

        // 아이콘 넣기
        ImageIcon icon = new ImageIcon("img/inha.png");
        iconLabel.setIcon(icon);

        c.add(buttonPanel, BorderLayout.NORTH);
        c.add(iconLabel, BorderLayout.CENTER);


        leftButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Point curLocation = iconLabel.getLocation();
                iconLabel.setLocation(curLocation.x-10, curLocation.y);
            }
        });

        rightButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Point curLocation = iconLabel.getLocation();
                iconLabel.setLocation(curLocation.x+10, curLocation.y);
            }
        });
        upButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Point curLocation = iconLabel.getLocation();
                iconLabel.setLocation(curLocation.x, curLocation.y-10);
            }
        });
        downButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Point curLocation = iconLabel.getLocation();
                iconLabel.setLocation(curLocation.x, curLocation.y+10);
            }
        });


        setVisible(true);
    }
}

public class Lab2_MoveIcon {
    public static void main(String[] args) {
        MoveIcon frame = new MoveIcon();
    }
}
