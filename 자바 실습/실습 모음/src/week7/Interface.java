package week7;
// public과 abstract는 생략 가능
interface PhoneInterface {
    final int TIMEOUT = 10000;
    void sendCall();
    void receiveCall();
    default void printLogo() {
        System.out.println("**phone**");
    }
}

interface MobilePhoneInterface extends PhoneInterface {
    void sendSMS();
    void receiveSMS();
}

interface MP3Interface {
    void play();
    void stop();
}

class PDA {
    public int calculate(int x, int y) {
        return x + y;
    }
}

class SmartPhone extends PDA implements MobilePhoneInterface, MP3Interface {
    public void sendCall() {
        System.out.println("따르릉따르릉~~");
    }

    public void receiveCall() {
        System.out.println("전화 왔아요.");
    }

    public void sendSMS() {
        System.out.println("문자 보냅니다.");
    }

    public void receiveSMS() {
        System.out.println("문자 왔습니다.");
    }

    public void play() {
        System.out.println("음악을 연주합니다.");
    }

    public void stop() {
        System.out.println("음악을 중단합니다.");
    }
}

public class Interface {
    public static void main(String[] args) {
        SmartPhone phone = new SmartPhone();
        phone.printLogo();
        phone.sendCall();
        phone.play();
        System.out.println("3과 5를 더하면 " + phone.calculate(3,5));
    }
}