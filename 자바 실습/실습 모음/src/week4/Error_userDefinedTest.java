package week4;

public class Error_userDefinedTest {
    public static void someFunction() { // throws 문을 써도 되고 안 써도 된다.
        throw new RuntimeException("My exception"); // checked exception
    }

    public static void main(String[] args) {
        int a = 1;
        try{
            someFunction();
        } catch (RuntimeException e) {
            System.out.println(e.getMessage());
        }

        System.out.println("정상 종료");
    }
}
