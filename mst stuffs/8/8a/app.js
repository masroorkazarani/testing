const express = require('express')
const mongoose = require('mongoose')
const app = express()

app.use(express.json())

app.listen(3000,()=>{console.log('Listening on port 3000')})
const url="mongodb+srv://masroorkazaranispam:Youtuberz@test.t9d7f.mongodb.net/?retryWrites=true&w=majority&appName=Test"

mongoose.connect(url).then(()=>console.log("Database Connected..")).catch(err => console.log(err))

var bookSchema = mongoose.Schema({
    name: String,
    isbn: {type:String, index:true, unique: true},
    author: String,
    pages: Number
});

const Book = mongoose.model("books", bookSchema)

const book_1 = new Book({
    name: 'Sherlock Holmes',
    isbn: "389991270121",
    author: "Arthur Conon Doyles",
    pages: 167
})

const book_2 = new Book({
    name: 'The Great Gatsby',
    isbn: "0743273565",
    author: "F. Scott Fitzgerald",
    pages: 120
})

//CREATE
async function createBooks(){
    book_1.save().then(()=>console.log("Created : \n" + book_1)).catch(e=>console.log(e))
    book_2.save().then(()=>console.log("Created : \n" + book_2)).catch(e=>console.log(e))
}

//READ
async function findBooks() {
    Book.find().then(books => console.log("All Books : \n", books)).catch(e => console.log(e))
    Book.findOne({isbn: "389991270121"}) .then(book => console.log("Found Book : \n", book)).catch(e => console.log(e))
}

//UPDATE
async function updateBook() {
    Book.findOneAndUpdate(
    { isbn: "389991270121" },
    { name: 'The Great Gatsby - Special Edition' },
    { new: true }  // This option returns the updated document
).then(updatedBook => console.log("Updated Book : \n", updatedBook)).catch(e => console.log(e))
}

//DELETE
async function deleteBook() {
    Book.findOneAndDelete({ isbn: "389991270121" }).then(deletedBook => console.log("Deleted Book : \n", deletedBook)).catch(e => console.log(e))
}

// createBooks()
// findBooks()
// updateBook()
// deleteBook()
