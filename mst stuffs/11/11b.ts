class Product1 {
    productId: number;
    constructor(productId: number) {
        this.productId = productId;
    }
    getProductId() {
        return "Product ID - " + this.productId;
    }
}

let productList: Product1[] = [];
let p1: Product1 = new Product1(2222);
let p2: Product1 = new Product1(1111);
productList.push(p1, p2);
console.log(productList)

productList.forEach((product, index) => {
    console.log("Product " + index + " : " + product.getProductId())
});
