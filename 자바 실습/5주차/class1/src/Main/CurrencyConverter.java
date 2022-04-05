package Main;

public class CurrencyConverter {
    static Double rate = 0.0;

    static void setRate(Double kwrRate) {
        rate = kwrRate;
    }
    static Double toKWR(int dollar) {
        return rate * dollar;
    }

}
