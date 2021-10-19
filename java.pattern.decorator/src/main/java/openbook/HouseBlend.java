package openbook;

/**
 * @author hwanseok on 2021/10/19
 */
public class HouseBlend extends Beverage {

    public HouseBlend(){
        description = "하우스 블렌드";
    }

    @Override
    public double cost() {
        return .89;
    }
}
