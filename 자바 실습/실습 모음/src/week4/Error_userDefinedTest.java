package week4;

public class Error_userDefinedTest {
    public static void someFunction() {
        throw new RuntimeException("My exception"); // checked exception
    }

    public static void main(String[] args) {
        int a = 1;
        System.out.println("정상 종료");
    }
}
