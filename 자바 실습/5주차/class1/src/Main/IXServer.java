package Main;

public class IXServer {

    private String strHostName = "Inha Server";
    private String strIPAddress = "192.168.0.1";
    private int portNum = 8080;

    public int getPortNum() {
        return portNum;
    }

    public void setPortNum(int portNum) {
        this.portNum = portNum;
    }

    public String getStrIPAddress() {
        return strIPAddress;
    }

    public void setStrIPAddress(String strIPAddress) {
        this.strIPAddress = strIPAddress;
    }

    public String getStrHostName() {
        return strHostName;
    }

    public void setStrHostName(String strHostName) {
        this.strHostName = strHostName;
    }

    void printHostServer() {
        System.out.println(getStrHostName());
        System.out.println(getStrIPAddress());
        System.out.println(getPortNum());
    }
}
