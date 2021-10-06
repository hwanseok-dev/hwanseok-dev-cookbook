package hwanseok.repository;

import hwanseok.entity.Product;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

/**
 * @author hwanseok on 2021/10/07
 */
@Repository
public interface ProductRepository extends JpaRepository<Product, Integer> {
}
