package week4;

import java.io.FileWriter;
import java.io.IOException;

public class Error_CheckedTest {
    static void writeFileLog() {
        try {
            FileWriter fw = new FileWriter("log.txt");
            fw.write("Hello World! -- 2");
            fw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        writeFileLog();
    }
}
