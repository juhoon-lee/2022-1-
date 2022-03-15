package Armstrong;
import java.lang.Math;

public class Armstrong {
    static boolean checkArmstrong(int arg) {
        int sum = 0;
        int n = arg;

        while( n > 0 ){
            int r = n % 10; // 나머지를 이용해 일의자리 수 구하기
            sum += Math.pow(r,3); // 세제곱을 더하기
            n = n / 10; // 10으로 나눠 일의자리 바꾸기
        }

        return arg == sum;
    }

    public static void  printStrong(int n) {
        System.out.print("Armstrong Number:\n" + " " );
        for (int i = 2; i <= n; i++) {
            if (checkArmstrong(i)) {
                System.out.print(i + " ");
            }

        }
        System.out.println();
    }

}
