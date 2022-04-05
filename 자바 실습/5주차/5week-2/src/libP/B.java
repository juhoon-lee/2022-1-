package libP;

public class B {
    void printB() {
        A a = new A();
//        System.out.println(a.privateVar); // private 컴파일 에러
        System.out.println(a.defaultVar);
        System.out.println(a.protectedVar);
        System.out.println(a.publicVar);
    }
}
