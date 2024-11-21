interface Mobile2 {
    id: number;
    name: string;
    manufacturer: string;
}

const mobiles2: Mobile2[] = [
    { id: 101, name: "Moto X", manufacturer: "Moto" },
    { id: 102, name: "Samsung Galaxy", manufacturer: "Samsung" },
    { id: 103, name: "Apple iPhone", manufacturer: "Apple" },
    { id: 104, name: "Samsung Note", manufacturer: "Samsung" },
];

// Function to get mobiles by manufacturer with optional id parameter
function getMobileByManufacturer(manufacturer: string = "Samsung", id?: number): Mobile2[] {
    if (id === 101) {
        return mobiles2.filter(mobile => mobile.manufacturer === "Moto");
    } else if (manufacturer === "Samsung" || manufacturer === "Apple") {
        return mobiles2.filter(mobile => mobile.manufacturer === manufacturer);
    } else {
        return [];
    }
}

// Example usage:
console.log(getMobileByManufacturer("Samsung"));  // Returns Samsung mobiles
console.log(getMobileByManufacturer("Apple"));    // Returns Apple mobiles
console.log(getMobileByManufacturer("Samsung", 101));  // Returns Moto mobiles
console.log(getMobileByManufacturer());  // Defaults to Samsung and returns Samsung mobiles
