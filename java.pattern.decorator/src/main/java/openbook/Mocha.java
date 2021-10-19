/**
 * @author hwanseok on 2021/10/19
 */
public class Mocha extends CondimentDecorator{

    Beverage beverage;

    public Mocha(Beverage beverage){
        this.beverage = beverage;
    }

    @Override
    public double cost() {
        return .20 + beverage.cost();
    }

    @Override
    public String getDescription() {
        return "Mocha" + beverage.getDescription();
    }
}
