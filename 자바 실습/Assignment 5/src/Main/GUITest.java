package Main;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.util.Objects;

class MyCalculator extends JFrame implements ActionListener {
    private JTextField txt;
    private JPanel panel;
    double arg;
    String operator="";

    public MyCalculator() {
        setTitle("계산기 만들기 - 12181818 이주훈");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        txt = new JTextField(10);
        txt.setFont(new Font("serif", Font.BOLD, 40));
        txt.setEditable(false);
        txt.setHorizontalAlignment(JTextField.RIGHT); // 오른쪽 부터 정렬되도록
        add(txt, BorderLayout.NORTH);

        panel = new JPanel();
        panel.setLayout(new GridLayout(5, 4,5,5));
        add(panel, BorderLayout.CENTER);

        String[] syntaxs = new String[] {"1/x", "x²","√x","➗"};
        for (String s : syntaxs) {
            JButton btn = new JButton(s);
            btn.addActionListener(this);
            btn.setPreferredSize(new Dimension(60, 50));
            btn.setBackground(Color.cyan);
            btn.setOpaque(true);
            panel.add(btn);
        }

        for (int i = 7; i <= 9; i++) {
            JButton btn = new JButton("" + i);
            btn.addActionListener(this);
            btn.setPreferredSize(new Dimension(60, 50));
            btn.setBackground(Color.ORANGE);
            btn.setOpaque(true);
            panel.add(btn);
        }
        {
            JButton btn = new JButton("✖");
            btn.addActionListener(this);
            btn.setPreferredSize(new Dimension(60, 50));
            btn.setBackground(Color.cyan);
            btn.setOpaque(true);
            panel.add(btn);
        }
        for (int i = 4; i <= 6; i++) {
            JButton btn = new JButton("" + i);
            btn.addActionListener(this);
            btn.setPreferredSize(new Dimension(60, 50));
            btn.setBackground(Color.ORANGE);
            btn.setOpaque(true);
            panel.add(btn);
        }
        {
            JButton btn = new JButton("➖");
            btn.addActionListener(this);
            btn.setPreferredSize(new Dimension(60, 50));
            btn.setBackground(Color.cyan);
            btn.setOpaque(true);
            panel.add(btn);
        }
        for (int i = 1; i <= 3; i++) {
            JButton btn = new JButton("" + i);
            btn.addActionListener(this);
            btn.setPreferredSize(new Dimension(60, 50));
            btn.setBackground(Color.ORANGE);
            btn.setOpaque(true);
            panel.add(btn);
        }
        {
            JButton btn = new JButton("➕");
            btn.addActionListener(this);
            btn.setPreferredSize(new Dimension(60, 50));
            btn.setBackground(Color.cyan);
            btn.setOpaque(true);
            panel.add(btn);
        }
        JButton clearButton = new JButton("C");
        clearButton.addActionListener(this);
        clearButton.setPreferredSize(new Dimension(60, 50));
        clearButton.setBackground(Color.cyan);
        clearButton.setOpaque(true);
        panel.add(clearButton);

        JButton btnZero = new JButton("" + 0);
        btnZero.addActionListener(this);
        btnZero.setPreferredSize(new Dimension(60, 50));
        btnZero.setBackground(Color.ORANGE);
        btnZero.setOpaque(true);
        panel.add(btnZero);

        JButton deleteButton = new JButton("⌫");
        deleteButton.addActionListener(this);
        deleteButton.setPreferredSize(new Dimension(60, 50));
        deleteButton.setBackground(Color.cyan);
        deleteButton.setOpaque(true);
        panel.add(deleteButton);
        {
            JButton btn = new JButton("🟰");
            btn.addActionListener(this);
            btn.setPreferredSize(new Dimension(60, 50));
            btn.setBackground(Color.red);
            btn.setOpaque(true);
            panel.add(btn);
        }
        pack();
        setResizable(false);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        String actionCommand = e.getActionCommand(); // 컴포넌트의 텍스트 값

        switch (actionCommand) {
            case "C":
                txt.setText("");
                arg = 0.0;
                operator = "";
                break;
            case "⌫":
                if (txt.getText().length() > 0) {
                    txt.setText(txt.getText().substring(0, txt.getText().length() - 1));
                }
                break;
            case "1/x":
                txt.setText(String.format("%15.3f", 1.0 / Integer.parseInt(txt.getText())));
                break;
            case "x²":
                long powNumber = Integer.parseInt(txt.getText());
                txt.setText(String.valueOf(powNumber * powNumber));
                break;
            case "√x":
                double rootNum = Double.parseDouble(txt.getText());
                txt.setText(String.format("%15.3f", Math.sqrt(rootNum)));

                break;
            case "➗":
                try {
                    arg = Double.parseDouble(txt.getText());
                } catch (NumberFormatException ignored) {
                }
                operator = "/";
                txt.setText("/");
                break;
            case "✖":
                try {
                    arg = Double.parseDouble(txt.getText());
                } catch (NumberFormatException ignored) {
                }
                operator = "*";
                txt.setText("*");
                break;
            case "➖":
                try {
                    arg = Double.parseDouble(txt.getText());
                } catch (NumberFormatException ignored) {
                }
                operator = "-";
                txt.setText("-");
                break;
            case "➕":
                try {
                    arg = Double.parseDouble(txt.getText());
                } catch (NumberFormatException ignored) {
                }
                operator = "+";
                txt.setText("+");
                break;
            case "🟰":
                if (Objects.equals(operator, "*")) {
                    txt.setText(String.format("%15.3f",arg * Double.parseDouble(txt.getText())));
                    operator = "";
                } else if (Objects.equals(operator, "/")) {
                    txt.setText(String.format("%15.3f",arg / Double.parseDouble(txt.getText())));
                    operator = "";
                } else if (Objects.equals(operator, "+")) {
                    txt.setText(String.format("%15.3f",arg + Double.parseDouble(txt.getText())));
                    operator = "";
                } else if (Objects.equals(operator, "-")) {
                    txt.setText(String.format("%15.3f",arg - Double.parseDouble(txt.getText())));
                    operator = "";
                }
                break;
            default:
                String text = txt.getText();
                if (Objects.equals(text, "*") || Objects.equals(text, "/") || Objects.equals(text, "+") || Objects.equals(text, "-")) {
                    txt.setText(actionCommand);
                } else {
                    txt.setText(txt.getText() + actionCommand);
                }
                break;
        }
    }
}

public class GUITest {
    public static void main(String[] args) {
        MyCalculator frame = new MyCalculator();
        System.out.println("12181818 이주훈");
    }
}
