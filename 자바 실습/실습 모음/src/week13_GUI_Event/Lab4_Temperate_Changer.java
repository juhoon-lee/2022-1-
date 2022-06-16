package week13_GUI_Event;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class TempChanger extends JFrame {
    JLabel labelC = new JLabel("섭씨");
    JTextField tfC = new JTextField(5);
    JLabel labelF = new JLabel("화씨");
    JTextField tfF = new JTextField(5);

    JButton btnCF = new JButton("C->F");
    JButton btnFC = new JButton("F->C");
    JButton btnReset = new JButton("Reset");

    TempChanger() {
        setBounds(100, 100, 500, 500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setTitle("Lab4 - Temperate Changer");

        Container c = getContentPane();
        JPanel p = new JPanel();
        p.setSize(new Dimension(500,50));
        p.add(labelC);
        p.add(tfC);
        p.add(labelF);
        p.add(tfF);
        p.setBackground(Color.yellow);
        c.add(p,BorderLayout.NORTH);

        JPanel p2 = new JPanel();
        p2.setSize(new Dimension(500,50));
        p2.add(btnCF);
        p2.add(btnFC);
        p2.add(btnReset);
        p2.setBackground(Color.cyan);
        c.add(p2, BorderLayout.CENTER);
        pack();
        setVisible(true);

        btnCF.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String strC = tfC.getText();
                double c = Double.parseDouble(strC);
                double f = 9/5.0*c + 32;
                tfF.setText(""+f);
            }
        });
        btnFC.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String strF = tfF.getText();
                double f = Double.parseDouble(strF);
                double c = (f-32)*5/9;
                tfC.setText(""+c);
            }
        });

        btnReset.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tfC.setText("");
                tfF.setText("");
            }
        });
    }
}

public class Lab4_Temperate_Changer {
    public static void main(String[] args) {
        TempChanger frame = new TempChanger();
    }
}
