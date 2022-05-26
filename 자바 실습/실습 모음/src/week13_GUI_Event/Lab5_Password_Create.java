package week13_GUI_Event;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class PasswordCreate extends JFrame {

    JLabel labelN = new JLabel("비밀번호 자리수");
    JTextField tfN = new JTextField(5);
    JButton btnGen = new JButton("자동생성");
    JLabel labelPW = new JLabel("비밀번호:");

    PasswordCreate() {
        setBounds(100, 100, 500, 500);
        setTitle("실습4- 비밀번호 자동생성기");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);

        Container c = getContentPane();
        JPanel p = new JPanel();
        p.setSize(new Dimension(500, 50));
        p.add(labelN);
        p.add(tfN);
        p.add(btnGen);
        p.setBackground(Color.yellow);
        c.add(p, BorderLayout.NORTH);
        c.add(labelPW);
        pack();

        btnGen.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String numberOfPassword = tfN.getText();
                int num = Integer.parseInt(numberOfPassword);
                labelPW.setText("비밀번호: " + randomPw(num));
            }
        });
    }

    public static String randomPw(int d) {
        char[] candidate = new char[]{
                '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')'};
        String ranPassword = "";
        for (int i = 0; i < d; i++) {
            int rand = (int) (Math.random() * (candidate.length));
            ranPassword += candidate[rand];
        }
        return ranPassword;
    }


}

public class Lab5_Password_Create {
    public static void main(String[] args) {
        PasswordCreate frame = new PasswordCreate();
    }
}
