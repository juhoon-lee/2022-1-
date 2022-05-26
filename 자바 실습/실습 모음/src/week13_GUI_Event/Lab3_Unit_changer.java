package week13_GUI_Event;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class UnitChanger extends JFrame {
    private final double KMS_PER_MILE = 1.609;
    JTextField KMUnit = new JTextField(5); // 5는 초기값이 아니라 5칸이라는 뜻
    JLabel mileLabel = new JLabel("Result: ");

    UnitChanger() {
        setBounds(100, 100, 500, 500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setTitle("Lab3 - Unit Changer");

        JLabel distanceLabel = new JLabel("Distance in miles");
        JButton convertButton = new JButton("Convert");

        JPanel p = new JPanel();
        p.setSize(500,50);
        p.add(distanceLabel);
        p.add(KMUnit);
        p.add(convertButton);
        p.setBackground(Color.yellow);

        Container c = getContentPane();
        c.add(p, BorderLayout.NORTH);
        c.add(mileLabel, BorderLayout.CENTER);
        c.setBackground(Color.cyan);
        pack();

        convertButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String input = KMUnit.getText(); // exeption 처리 해야함
                double mile = Double.parseDouble(input)*KMS_PER_MILE;
                mileLabel.setText("Result: "+mile);
            }
        });

        setVisible(true);
    }
}

public class Lab3_Unit_changer {
    public static void main(String[] args) {
        UnitChanger frame = new UnitChanger();
    }
}
