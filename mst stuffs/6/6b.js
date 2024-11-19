const http = require('http');  // Import HTTP module

// Create the server
const server = http.createServer((req, res) => {
    res.statusCode = 200;  // Set status code to 200 (OK)
    res.setHeader('Content-Type', 'text/plain');  // Set content type to plain text

    // Respond to the request
    res.end('Hello, World! This is your web server in Node.js!\n');
});

// Listen on port 3000 and log a message
server.listen(3000, '127.0.0.1', () => {
    console.log('Server running at http://127.0.0.1:3000/');
});
