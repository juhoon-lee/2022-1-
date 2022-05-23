package week12_Swing;

import javax.swing.*;
import java.awt.*;

class SystemInfoFrame extends JFrame {
    SystemInfoFrame() {
        setSize(300,300);
        setLocation(2000,500 );
        setTitle("System Information Frame");
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        // 시스템에서 Key값으로 정보 가져오기
        String os = System.getProperty("os.name"); // OS 정보
        String arch = System.getProperty("os.arch"); // 아키텍쳐
        String user = System.getProperty("user.name"); // 사용자 이름

        // 런타임 사용량
        int p = Runtime.getRuntime().availableProcessors(); // 사용가능 cpu
        long m = Runtime.getRuntime().totalMemory(); // 메모리

        Container c = getContentPane();
        c.setLayout(new GridLayout(5,2,10,10));

        // 라벨 생성
        JLabel label1 = new JLabel("OS: ");
        JLabel label2 = new JLabel("ARCH: ");
        JLabel label3 = new JLabel("USER: ");
        JLabel label4 = new JLabel("CPU: ");
        JLabel label5 = new JLabel("MEM: ");

        // 가져온 정보를 표시할 텍스트필드 생성
        JTextField tx1 = new JTextField(os);
        tx1.setEditable(false);
        JTextField tx2 = new JTextField(arch);
        tx2.setEditable(false);
        JTextField tx3 = new JTextField(user);
        tx3.setEditable(false);
        JTextField tx4 = new JTextField(""+p); // 문자로 변환하기 위해
        tx4.setEditable(false);
        JTextField tx5 = new JTextField(""+m);
        tx5.setEditable(false);

        // 그리드 레이아웃에 배치
        c.add(label1);
        c.add(tx1);
        c.add(label2);
        c.add(tx2);
        c.add(label3);
        c.add(tx3);
        c.add(label4);
        c.add(tx4);
        c.add(label5);
        c.add(tx5);

        setVisible(true);
    }
}

public class Lab3 {
    public static void main(String[] args) {
        SystemInfoFrame frame = new SystemInfoFrame();
    }
}
