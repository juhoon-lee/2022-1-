package Harshad;

public class Harshad {
    static boolean checkHarshad(int arg) {
        int sum = 0;
        int n = arg;

        while (n > 0) {
            int r = n % 10;
            sum += r;
            n = n / 10;
        }
        int answer = arg % sum;
        return answer == 0;
    }

    public static void  printHarshad(int n) {
        System.out.print("Harshad Number:\n" + " " );
        for (int i = 2; i <= n; i++) {
            if (checkHarshad(i)) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
    }
}
