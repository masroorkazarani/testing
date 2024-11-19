const express = require('express')
const mongoose = require('mongoose')
const app = express()

app.listen(3000,()=>{console.log('Listening on port 3000')})
const url="mongodb+srv://masroorkazaranispam:Youtuberz@test.t9d7f.mongodb.net/?retryWrites=true&w=majority&appName=Test"

mongoose.connect(url).then(()=>console.log("Database Connected..")).catch(err => console.log(err))

var bookSchema = mongoose.Schema({
    name: String,
    isbn:{type:String,index:true},
    author:String,
    pages:Number
});
const Book = mongoose.model("books", bookSchema)

// const book = new Book({
//     name: 'Sherlock Holmes',
//     isbn: "389991270121",
//     author: "Arthur Conon Doyles",
//     pages: 167
// })
// book.save().then(()=>console.log("Created")).catch(e=>console.log(e))
