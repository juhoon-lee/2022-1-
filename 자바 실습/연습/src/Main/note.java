package Main;

class A {
    public A() {
        System.out.println("construtor A");
    }

    void example() {
        System.out.println("hello AAA");
    }
}
class B extends A {
    public B() {
        System.out.println("constructor B");
    }
    void example() {
        System.out.println("hello BBB");
    }
}

public class note {
    public static void main(String[] args) {
        A ex = new B();
        ex.example();
    }
}

