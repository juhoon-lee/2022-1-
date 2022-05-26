package week13_GUI_Event;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class TextAreaFrame extends JFrame {
    Container c = getContentPane();
    JLabel la = new JLabel("입력후 엔터키를 입력하세요.");
    TextField tx = new TextField(20);
    TextArea ta = new TextArea(6, 20);
    TextArea ta2 = new TextArea(6, 20);

    TextAreaFrame() {
        setBounds(300, 100, 300, 300);
        setTitle("TextArea Frame");
        setDefaultCloseOperation(EXIT_ON_CLOSE);



        c.setLayout(new FlowLayout());
        c.add(la);
        c.add(tx);
        c.add(new JScrollPane(ta));
        c.add(new JScrollPane(ta2));

        // 키 이벤트 add
        tx.setFocusable(true);
        tx.requestFocus();
        setVisible(true);

        tx.addKeyListener(new KeyListener() { // 키에 따라 배경 색상 바꾸기
            @Override
            public void keyTyped(KeyEvent e) {
                System.out.println("keyTyped");
            }

            @Override
            public void keyPressed(KeyEvent e) {
                System.out.println("keyPressed");
                char c = e.getKeyChar();
                int x = e.getKeyCode();
                String s = KeyEvent.getKeyText(x); // static method

                if (c == '%') {
                    TextAreaFrame.this.c.setBackground(Color.YELLOW);
                }
                else if ( x == KeyEvent.VK_SHIFT) {
                    TextAreaFrame.this.c.setBackground(Color.green);
                }

//                System.out.println("character: " + c + " Code: " + x + " String: " + s);
            }

            @Override
            public void keyReleased(KeyEvent e) {
                System.out.println("keyReleased");
            }
        });


        tx.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                ta.append(tx.getText() + "\n"); // append로 추가
            }
        });

        // 추상 메소드 불편 -> Adapter 사용으로 해결 가능
        // 일반 버전
        tx.addMouseListener(new MouseListener() { // MouseListener는 Interface임
            @Override
            public void mouseClicked(MouseEvent e) {
                int x = e.getX();
                int y = e.getY();
                ta.append("Clicked(" + x + ", " + y + ")\n");
            }

            @Override
            public void mousePressed(MouseEvent e) {
            }

            @Override
            public void mouseReleased(MouseEvent e) {
            }

            @Override
            public void mouseEntered(MouseEvent e) {
            }

            @Override
            public void mouseExited(MouseEvent e) {
            }
        });
        // Adapter 클래스 버전
        tx.addMouseListener(new MouseAdapter() { // 어댑터는 SuperClass임
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);
                System.out.println("어댑터 클래스 클릭!!");
            }
        });

        // 컨테이너에 마우스 클릭시 Label 이동
        c.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);
                int x = e.getX();
                int y = e.getY();
                la.setLocation(x, y);
            }
        });
    }
}

public class TextAreaTest {
    public static void main(String[] args) {
        TextAreaFrame frame = new TextAreaFrame();
    }
}
