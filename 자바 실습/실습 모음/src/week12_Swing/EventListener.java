package week12_Swing;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class EventFrame extends JFrame {
    JButton plusButton = new JButton("카운트+");
    JLabel label = new JLabel("이주훈");
    JButton minusButton = new JButton("카운트-");
    int count = 0;

    EventFrame(){
        setBounds(500,500,300,200);
        setTitle("Event Frame");
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        Container c = getContentPane();
        c.add(plusButton, BorderLayout.WEST);
        c.add(label, BorderLayout.CENTER);
        c.add(minusButton, BorderLayout.EAST);

        // 내부 클래스로 이벤트 구현
        plusButton.addActionListener(new MyListener());

        // 익명 클래스로 이벤트 구현
        minusButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                count-=1 ;
                label.setText("카운트: "+count);
            }
        });

        setVisible(true);
    }

    // 내부 클래스
    class MyListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            count += 1;
            label.setText("카운트: "+count);
        }
    }

}

public class EventListener {
    public static void main(String[] args) {
        EventFrame frame = new EventFrame();
    }
}
