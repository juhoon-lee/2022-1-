package week6;

public class SamsungCamera extends Camera {
    String strVendor;

    public SamsungCamera(String strName, String strVendor) {
        super(strName);
        this.strVendor = strVendor;
    }

    @Override
    void printVender() {
        System.out.println("Samsung");
    }

    @Override
    void moveLeft() {
        byte[] bytes = new byte[3];
        bytes[0] = 0x02;
        bytes[1] = 0x03;
        bytes[2] = 0x0e;
        sendData(bytes);
    }
}
