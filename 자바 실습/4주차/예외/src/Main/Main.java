package Main;

import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;

public class Main {

    static void writeFileLog() throws IOException {
        // Try Catch 문으로 작성 또는 상위로 throws
        try {
            FileWriter fw = new FileWriter("Z:/log.txt");
            fw.write("Hello World! -- 1");
            fw.close();
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        try {
            writeFileLog();
        } catch ( IOException e ){
            e.printStackTrace();
        }


    }
}
