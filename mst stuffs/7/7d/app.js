const express = require('express');
const mongoose = require('mongoose');
const app = express();

mongoose.connect(url).then(()=> console.log('Database Connected')).catch((err)=> console.log(err))

const bookSchema = new mongoose.Schema({
    name: String,
    isbn: { type: String, index: true },
    author: String,
    pages: Number
});

const db = mongoose.connection;
db.on('error',console.error.bind(console.log('error:')))

app.listen(3000, () => {
    console.log("Listening on port 3000");
});
