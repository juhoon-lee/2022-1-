package week5;

import java.util.Scanner;

public class BookArray {
    public static void main(String[] args) {

        Book[] b = new Book[2];
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < b.length; i++){
            System.out.print("제목>>");
            String title = scanner.nextLine();
            System.out.print("저자>>");
            String author = scanner.nextLine();
            b[i] = new Book(title,author);
        }
        for (Book targetBook : b) {
            targetBook.printBook();
        }
        scanner.close();
    }
}

