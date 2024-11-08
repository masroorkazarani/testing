class Product3 {
    private productId: number;
    public productName: string;
    static productPrice: number;
    protected productCategory: string;
    constructor(
        productId: number,
        productName: string,
        productPrice: number,
        productCategory: string
    ) {
        this.productId = productId;
        this.productName = productName;
        Product3.productPrice = productPrice;
        this.productCategory = productCategory;
    }

    public getProductId() { return this.productId }

    public getProductCategory() { return this.productCategory }
}

class Gadget extends Product3 {
    constructor(
        productId: number,
        productName: string,
        productPrice: number,
        productCategory: string
    ) {
        super(productId, productName, productPrice, productCategory);
    }
}

const gadget = new Gadget(1234, "Smartphone", 499, "Electronics");
console.log("Product Name: " + gadget.productName);
console.log("Product Category: " + gadget.getProductCategory());
console.log("Product ID: " + gadget.getProductId());
console.log("Product Price: " + Product3.productPrice);
