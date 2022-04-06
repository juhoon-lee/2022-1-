package week5_2;

public class Calc {
    // 오버로딩 예제
    int getSum(int a, int b) {
        return a + b;
    }

    int getSum(int a, int b, int c) {
        return a + b + c;
    }

    double getSum(int a, double b) {
        return (double)a + b;
    }

    // 생성자 예제
    int arg1 = 0;
    int arg2 = 0;

    // *** 생성자에서 생성자 호출의 contaraints
    // 생성자에서 생성자를 호출하는 것은 항상 첫번째 줄에서만 가능
    Calc(){
        // 생성자에서 생성자 부르기 -> 속도는 느려질 수 있음.
        this(1, 2);
        // 생성자 자체로 만들기
        arg1 = 1;
        arg2 = 2;
    }
    Calc(int arg1, int arg2){
        this.arg1 = arg1; // this Keyword 사용
        this.arg2 = arg2;
    }
    Calc(int arg1){
        this(arg1,1); // 생성자 -> 샹성자

        this.arg1 = arg1;
        this.arg2 = 1;
    }

    void  printArgs(){
        System.out.print(arg1 + " ");
        System.out.print(arg2);
        System.out.println();
    }

    public static void main(String[] args) {
        // 오버로딩
        Calc A = new Calc();
        System.out.println( "오버로딩 1" + A.getSum(1,2));
        System.out.println( "오버로딩 2" + A.getSum(1,3.0));
        System.out.println( "오버로딩 3" + A.getSum(1,2,3));

        // 생성자
        Calc a = new Calc();
        Calc b = new Calc(1);
        Calc c = new Calc(1, 2);

        System.out.print("생성자 1: ");
        a.printArgs();
        System.out.print("생성자 2: ");
        b.printArgs();
        System.out.print("생성자 3: ");
        c.printArgs();
    }

}
