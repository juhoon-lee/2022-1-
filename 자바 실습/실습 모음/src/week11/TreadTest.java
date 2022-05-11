package week11;

class MyThread extends Thread {
    @Override
    public void run() {
        System.out.println("Thread 1");
        for (int i = 0; i < 1000; i++) {
            System.out.print("+");
        }
        System.out.println();
    }
}

class MyRunnable implements Runnable {

    @Override
    public void run() {
        System.out.println("Thread 2 (Runnable)");
        for (int i = 0; i < 1000; i++) {
            System.out.print("-");
        }
        System.out.println();
    }
}

public class TreadTest {

    static void g() throws InterruptedException {

        // thread 상속해서 만들기
        MyThread td1 = new MyThread();
        td1.setName("A"); // th1의 이름은 A로 정함
        td1.start();

        // Runnable interface 상속해서 만들기
        Thread td2 = new Thread(new MyRunnable());
        td2.start();
        // 이후 병행 처리 -> 실행해보기

        // 아래는 Thread의 종료를 기다림
        td1.join(); // 쓰레드들은 실행되지만 코드 기준으로 td1 작업이 끝나야 다음 줄 실행되네!
        td2.join();

    }
    public static void main(String[] args) throws InterruptedException {
        System.out.println("Main Thread");
        g();
        // 현재 실행 쓰레드의 이름 출력
        System.out.println(Thread.currentThread().getName());
    }
}
