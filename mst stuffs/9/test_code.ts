class Product100 {
    productId: number;
    constructor(productId: number) {
        this.productId = productId;
    }
    getProductId() {
        return "Product ID - " + this.productId;
    }
}

let p3: Product100 = new Product100(2211)
let p4: Product100 = new Product100(9999)
console.log(p3.getProductId())
console.log(p4.getProductId())
