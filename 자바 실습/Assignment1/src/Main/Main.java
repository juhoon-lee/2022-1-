package Main;

import Harshad.Harshad;
import Armstrong.Armstrong;
import Perfect.perfect;

public class Main {

    public static void main(String[] args) {
        int n = 1000;
        System.out.println("학번 12181818 이름: 이주훈");

        // 하샤드수 출력
        Harshad.printHarshad(n);
        // 암스트롱수 출력
        Armstrong.printStrong(n);
        // 완전수 출력
        perfect.printPerfect(n);
    }
}