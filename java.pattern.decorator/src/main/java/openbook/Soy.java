package openbook;

/**
 * @author hwanseok on 2021/10/19
 */
public class Soy extends CondimentDecorator{

    Beverage beverage;

    public Soy(Beverage beverage){
        this.beverage = beverage;
    }

    @Override
    public double cost() {
        return 0.11 + beverage.cost();
    }

    @Override
    public String getDescription() {
        return "openbook.Soy" + beverage.getDescription();
    }
}
