const fs = require('fs');  // Import the 'fs' (file system) module

// Data to be written to the text file
const data = 'Mongo, Express, Angular';

// Write data to src.txt
fs.writeFile('src.txt', data, (err) => {
    if (err) {
        console.error('Error writing to file:', err);
    } else {
        console.log('Data successfully written to src.txt');

        // Copy data from src.txt to dest.txt after writing to the source file
        fs.copyFile('src.txt', 'dest.txt', (err) => {
            if (err) {
                console.error('Error copying to destination file:', err);
            } else {
                console.log('Data successfully copied to dest.txt');
            }
        });

    }
});
