package week6_1;

public class LGCamera extends Camera{
    String strVendor;

    public LGCamera(String strName, String strVendor) {
        super(strName);
        this.strVendor = strVendor;
    }

    @Override
    void printVender() {
        System.out.println("LG");
    }

    @Override
    void moveLeft() {
        byte[] bytes = new byte[3];
        bytes[0] = 0x01;
        bytes[1] = 0x02;
        bytes[2] = 0x0f;
        sendData(bytes);
    }
}
