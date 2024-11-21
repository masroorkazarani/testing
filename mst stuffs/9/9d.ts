interface Manufacturer {
    id: number;
    price: number;
}

const manufacturers: Manufacturer[] = [
    { id: 1, price: 100 },
    { id: 2, price: 200 },
    { id: 3, price: 150 },
    { id: 4, price: 80 },
];

// Arrow function to populate the id of manufacturers with price >= 150
const myfunction = (manufacturers: Manufacturer[]): number[] => {
    return manufacturers
        .filter(manufacturer => manufacturer.price >= 150)
        .map(manufacturer => manufacturer.id);
};

// Example usage
const ids = myfunction(manufacturers);
console.log(ids); // [2, 3]
