package libQ;

import libP.A;

public class D {
    void printD() {
        A a = new A();
        // private -> 안됨
        // default -> 다른패키지 안됨
        // protected(동일패키지 + 자식클래스 사용 가능) -> 상속 X -> 안됨
        System.out.println(a.publicVar);
    }
}
