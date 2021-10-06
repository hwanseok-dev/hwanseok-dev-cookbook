package hwanseok.repository;

import hwanseok.entity.Orders;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

/**
 * @author hwanseok on 2021/10/07
 */
@Repository
public interface OrdersRepository extends JpaRepository<Orders, Integer> {
}
