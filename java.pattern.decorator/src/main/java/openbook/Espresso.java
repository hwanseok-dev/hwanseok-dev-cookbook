package openbook;

/**
 * @author hwanseok on 2021/10/19
 */
public class Espresso extends Beverage {

    public Espresso(){
        description = "에스프레소";
    }

    @Override
    public double cost() {
        return 1.99;
    }
}
