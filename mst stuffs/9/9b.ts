interface Product {
    productId: number;
    name: string;
    price: number;
}

const products: Product[] = [
    { productId: 1, name: "Phone", price: 700 },
    { productId: 2, name: "Laptop", price: 1500 },
    { productId: 3, name: "Tablet", price: 500 },
];

// Function to handle the event and pass the selected product to the next screen
const handleProductSelection = (productId: number) => {
    const selectedProduct = products.find(product => product.productId === productId);

    if (selectedProduct) {
        // Pass the selected product to the next screen (for example, log it here)
        console.log("Selected Product:", selectedProduct);
    } else {
        console.log("Product not found");
    }
};

// Example: Simulating a product selection with productId 2
handleProductSelection(2);
