// app.js

// Import the math module
const math = require('./math');

// Import the greeting module
const greet = require('./greeting');

// Using the greeting module to greet a user
const greetingMessage = greet('John');
console.log(greetingMessage);  // Output: Hello, John! Welcome to Node.js modular programming.

// Using the math module to perform calculations
const sum = math.add(5, 3);
console.log(`5 + 3 = ${sum}`);  // Output: 5 + 3 = 8

const difference = math.subtract(9, 4);
console.log(`9 - 4 = ${difference}`);  // Output: 9 - 4 = 5
