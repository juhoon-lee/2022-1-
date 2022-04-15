package week6;

import java.util.Arrays;

public class Camera {
    String strName;

    public Camera(String strName) {
        this.strName = strName;
    }

    void printVender() {
        System.out.println("Base Class vender!");
    }

    void printInfo() {
        System.out.println(strName);
    }

    void sendData(byte[] data){
        System.out.println(Arrays.toString(data));
    }
    void moveLeft() {
        System.out.println("Base Class moveLeft!");
    }
}
