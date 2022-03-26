import java.io.Serializable;

public class Money implements Serializable{
    protected double money = 0;

    public Money(){
        this.money = 0;
    }

    public Money(double money){
        this.money = money;
    }

    public double getMoney(){
        return this.money;
    }
    
    public void setMoney (double money){
        this.money = money;
    }
}
