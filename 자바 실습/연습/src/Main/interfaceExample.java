package Main;

interface Movable {
    public abstract void moveUp();
    void movemove();
}

class Moving implements Movable {

    @Override
    public void moveUp() {
        System.out.println("moveUP");
    }

    @Override
    public void movemove() {
        System.out.println("movemove");
    }
}

public class interfaceExample {
    public static void main(String[] args) {
        Moving A = new Moving();
        A.movemove();
        A.moveUp();
    }
}
