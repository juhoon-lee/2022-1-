package week12_Swing;
import javax.swing.*;
import java.awt.*;

class MyFirstFrame extends JFrame {
    MyFirstFrame(){
        setLocation(100,100); // 생성 위치
        setSize(400,200); // frame 크기
        setTitle("Java Programming 2022"); // title
        setDefaultCloseOperation(EXIT_ON_CLOSE); // GUI 종료시 프로그램 종료

        Container c = getContentPane();
        JLabel label = new JLabel();
        label.setText("이주훈"); // 생성자도 지원 -> new Jlabel("이주훈")
        c.add(label);
        // 아래처럼 쓰면 같은 위치에 add되어 세 번째만 보임
//        c.add(new JLabel("두 번째 레이블"));
//        c.add(new JLabel("세 번째 레이블"));

        // 그래서 flowLayout으로 바꿔줌 - add 하면 쭉 펴짐
        c.setLayout(new FlowLayout());

        ImageIcon icon = new ImageIcon("img/inha.png"); // 이미지 받아오기
        JLabel imgLabel = new JLabel(icon); // 이미지 레이블 만들기
        c.add(imgLabel); // 이미지 레이블 추가

        JLabel txtLabel = new JLabel("Password: ");
        txtLabel.setText("Password2: ");
//        txtLabel.setFont(new Font());
        txtLabel.setForeground(Color.blue);
        txtLabel.setOpaque(true); // default 배경 투명
        txtLabel.setBackground(Color.yellow);
        c.add(txtLabel);

        // background Color
        c.setBackground(Color.yellow);

        setVisible(true);
    }
}
public class GUITester {
    public static void main(String[] args) {
        MyFirstFrame frame = new MyFirstFrame();
    }
}
