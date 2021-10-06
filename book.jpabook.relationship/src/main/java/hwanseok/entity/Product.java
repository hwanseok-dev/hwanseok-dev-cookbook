package hwanseok.entity;

import javax.persistence.*;

/**
 * @author hwanseok on 2021/10/06
 */
@Entity
public class Product {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;

    @Enumerated(EnumType.STRING)
    private ProductType typeStr;

    @ManyToOne
    private Orders order;

    public Orders getOrder() {
        return order;
    }

    public void setOrder(Orders order) {
        this.order = order;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public ProductType getTypeStr() {
        return typeStr;
    }

    public void setTypeStr(ProductType typeStr) {
        this.typeStr = typeStr;
    }
}
