package week12_Swing;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Objects;

class ColorFrame extends JFrame {
    JButton changeButton = new JButton("확인");
    ColorFrame() {
        setBounds(500,500,300,200);
        setTitle("이벤트창");
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        getContentPane().add(changeButton, BorderLayout.CENTER);

        changeButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // 강의노트에서는 Flag를 만들어서 토글 형식으로 사용
                JButton btn = (JButton) e.getSource();
                String btnText = btn.getText();
                if (Objects.equals(btnText, "확인")) {
                    changeButton.setText("OK");
                    setTitle("Event Frame");// ColorFrame.this.setTitle(); 이렇게도 가능
                    btn.setOpaque(true);
                    btn.setBackground(Color.GREEN);
                }
                else if (Objects.equals(btnText, "OK")) {
                    changeButton.setText("확인");
                    setTitle("이벤트 창");
                    btn.setBackground(Color.YELLOW);
                }
            }
        });
        setVisible(true);
    }
}

public class EventLab2 {
    public static void main(String[] args) {
        ColorFrame frame = new ColorFrame();
    }
}
