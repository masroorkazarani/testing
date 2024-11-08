interface Category {
    categoryName: string;
}

interface Product {
    productName: string;
    productId: number;
}

interface ProductList extends Category, Product {
    list: Array<string>;
}

const productDetails: ProductList = {
    categoryName: "Gadget",
    productName: "Mobiles",
    productId: 3369,
    list: ["Samsung", "Xiaomi", "OnePlus"]
};

const c_name = productDetails.categoryName;
const p_name = productDetails.productName;
const p_id = productDetails.productId;
const types = productDetails.list;

console.log(c_name)
console.log(p_name)
console.log(p_id)
console.log(types[0])
console.log(types)
for (const type of types) {
    console.log(type)
}
