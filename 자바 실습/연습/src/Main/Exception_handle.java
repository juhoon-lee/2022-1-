package Main;

import java.util.Scanner;

public class Exception_handle {

    private static void someThing() throws Exception {
        throw new RuntimeException("이거 맞아?");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            someThing();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        scanner.close();
    }
}
