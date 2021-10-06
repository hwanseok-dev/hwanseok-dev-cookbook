package hwanseok.entity;

import javax.persistence.*;

/**
 * @author hwanseok on 2021/10/06
 */
@Entity
@SequenceGenerator(
        name = "ORDERS_SEQ_GENERATOR",
        sequenceName = "ORDERS_SEQ", // 매핑할 데이터베이스 시퀀스 이름
        initialValue = 1, allocationSize = 1
)
public class Orders {
    @Id
    @GeneratedValue(strategy = GenerationType.SEQUENCE, generator = "ORDERS_SEQ_GENERATOR")
    private int id;
}
