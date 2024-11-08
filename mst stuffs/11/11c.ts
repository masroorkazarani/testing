class Product2 {
    productId: number;
    constructor(productId: number) {
        this.productId = productId;
    }
    getProductId() {
        return "Product ID - " + this.productId;
    }
}

let p3: Product2 = new Product2(2211)
let p4: Product2 = new Product2(9999)
console.log(p3.getProductId())
console.log(p4.getProductId())
