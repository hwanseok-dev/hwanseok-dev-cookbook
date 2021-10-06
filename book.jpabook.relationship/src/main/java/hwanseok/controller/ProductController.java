package hwanseok.controller;

import hwanseok.entity.Orders;
import hwanseok.entity.Product;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;
import hwanseok.repository.OrdersRepository;
import hwanseok.repository.ProductRepository;

/**
 * @author hwanseok on 2021/10/07
 */
@RestController
public class ProductController {

    @Autowired
    private ProductRepository productRepository;

    @Autowired
    private OrdersRepository ordersRepository;

    @GetMapping("/product/test")
    public void test(){
        Orders orders_1 = new Orders();
        Product product_1 = new Product();
        Product product_2 = new Product();

        product_1.setOrder(orders_1);
        product_2.setOrder(orders_1);

        productRepository.save(product_1);
        productRepository.save(product_2);
    }
}
