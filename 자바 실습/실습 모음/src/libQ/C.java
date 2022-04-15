package libQ;

import libP.A;

public class C extends A {
    void printC() {
        // private은 당연히 안되고
        // default는 같은 패키지에서 허용이기 때문에 사용 불가능
        System.out.println(protectedVar);
        System.out.println(publicVar);
    }
}
