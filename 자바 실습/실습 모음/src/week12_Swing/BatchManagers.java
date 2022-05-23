package week12_Swing;

import javax.swing.*;
import java.awt.*;

class MyFrame extends JFrame {
    MyFrame() {
        setSize(300,300);
        setLocation(100,100);
        setTitle("Layout Test Frame");
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        Container c = getContentPane();
        c.setLayout(new FlowLayout(FlowLayout.LEFT,50,10));
        c.add(new JLabel("OK1"));
        c.add(new JLabel("OK2"));
        c.add(new JLabel("OK3"));
        c.add(new JLabel("OK4"));
        c.add(new JLabel("OK5"));

        JPanel p = new JPanel();
        p.setLayout(new BorderLayout());
        p.add(new JButton("Button1"), BorderLayout.EAST);
        p.add(new JButton("Button2"), BorderLayout.WEST);
        p.add(new JButton("Button3"), BorderLayout.CENTER);
        p.add(new JButton("Button4"), BorderLayout.NORTH);
        p.add(new JButton("Button5"), BorderLayout.SOUTH);
        setContentPane(p); // 컨텐트펜 변경

        JPanel g = new JPanel();
        g.setLayout(new GridLayout(2,4));
        g.add(new JButton("Button1"));
        g.add(new JButton("Button2"));
        g.add(new JButton("Button3"));
        g.add(new JButton("Button4"));
        g.add(new JButton("Button5"));
        g.add(new JButton("Button6"));
        g.add(new JButton("Button7"));
        g.add(new JButton("Button8"));

        setContentPane(g); // 컨텐트펜 변경

        // p,g 를 c에 추가
        c.add(p);
        c.add(g);

        setContentPane(c); // 컨텐트펜 원래대로 변경
        setVisible(true);
    }
}

public class BatchManagers {
    public static void main(String[] args) {
        EventFrame frame = new EventFrame();
    }
}
