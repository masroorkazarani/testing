const prices: { [key: string]: number } = {
    GoldPlatinum: 1000,
    PinkGold: 1200,
    SilverTitanium: 900,
};

console.log("Mobile Prices:");
for (const color in prices) {
    console.log(`${color}: $${prices[color as keyof typeof prices]}`);
}
