interface Mobile {
    productId: number;
    name: string;
    vendor: string;
    price: number;
}

const mobiles: Mobile[] = [
    { productId: 1, name: "Phone A", vendor: "Vendor1", price: 700 },
    { productId: 2, name: "Phone B", vendor: "Vendor2", price: 1200 },
    { productId: 3, name: "Phone C", vendor: "Vendor1", price: 800 },
];

// Function to get mobiles by vendor
function getMobileByVendor(vendor: string): Mobile[] {
    return mobiles.filter(mobile => mobile.vendor === vendor);
}

// Example usage
const vendorMobiles = getMobileByVendor("Vendor1");
console.log(vendorMobiles);
