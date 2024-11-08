const express = require('express')
const mongoose = require('mongoose')
const app = express()

app.listen(3000,()=>{console.log('Listening on port 3000')})
const url="mongodb+srv://masroorkazaranispam:69AgyFbGvewhauXh@cluster0.t9d7f.mongodb.net/hussain?retryWrites=true&w=majority&appName=Cluster0"

mongoose.connect(url).then(()=>console.log("Database Connected..")).catch(err => console.log(err))

var bookSchema = mongoose.Schema({
    name: String,
    isbn:{type:String,index:true},
    author:String,
    pages:Number
});
const Book = mongoose.model("books", bookSchema)
const book = new Book({
    name: 'abs',
    isbn: "helllo",
    author: "hussain",
    pages: 123
})
book.save().then(()=>console.log("Createed")).catch(e=>console.log(e))
