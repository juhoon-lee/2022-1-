package week12_Swing;

import org.w3c.dom.html.HTMLLabelElement;

import javax.swing.*;
import java.awt.*;
import java.util.Calendar;

class CalenderFrame extends JFrame {
    CalenderFrame(){
        Container c = getContentPane();
        c.setLayout(new FlowLayout());
        ImageIcon inhaIcon = new  ImageIcon("img/inha.png");
        JLabel iconLabel = new JLabel(inhaIcon);
        JLabel dateText = new JLabel("날짜");

        Calendar cal = Calendar.getInstance();

        int year = cal.get(Calendar.YEAR);
        int month = cal.get(Calendar.MONTH) + 1;
        int day = cal.get(Calendar.DAY_OF_MONTH);
        int hour = cal.get(Calendar.HOUR_OF_DAY);
        int minute = cal.get(Calendar.MINUTE);

        JTextField date = new JTextField(year + "-" + month + "-" + day,15);
        date.setOpaque(true);
        date.setBackground(Color.gray);
        date.setEditable(false);
        JLabel timeLabel = new JLabel("시간");

        JTextField timeTextField = new JTextField(hour+":"+minute);
        timeTextField.setOpaque(true);
        timeTextField.setBackground(Color.gray);
        timeTextField.setEditable(false);
        c.add(iconLabel);
        c.add(dateText);
        c.add(date);
        c.add(timeLabel);
        c.add(timeTextField);
        c.setBackground(Color.gray);

        setTitle("Calender Frame");
        setSize(300,300);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
    }
}


public class Lab2_Calander {
    public static void main(String[] args) {
        CalenderFrame frame = new CalenderFrame();
    }
}
