const express = require('express')
const mongoose = require('mongoose')
const app = express()

app.use(express.json())

app.listen(3000,()=>{console.log('Listening on port 3000')})
const url="mongodb+srv://masroorkazaranispam:Youtuberz@test.t9d7f.mongodb.net/?retryWrites=true&w=majority&appName=Test"

mongoose.connect(url).then(()=>console.log("Database Connected..")).catch(err => console.log(err))

var noteSchema = mongoose.Schema({
    title: String,
    content: String,
    noteId: { type: String, unique: true }
});

const Note = mongoose.model("notes", noteSchema)

// API to fetch a note by noteId
function getById(){
    app.get('/notes/:noteId', async (req, res) => {
    const note = await Note.findOne({ noteId: req.params.noteId });
    if (note) {
      res.json(note);
    } else {
      res.status(404).json({ message: 'Note not found' });
    }
    });
}

// API to update a note by name
function updateByName(){
    app.get('/notes/:name', async (req, res) => {
    const updatedNote = await Note.findOneAndUpdate(
      { title: req.params.name },
      { content : "This is Edited Content That Im typing"},
      { new: true }
    );
    if (updatedNote) {
      res.json(updatedNote);
    } else {
      res.status(404).json({ message: 'Note not found for update' });
    }
    });
}

// API to update a note by name
function deleteByName(){
    app.get('/notes/:name', async (req, res) => {
    const deletedNote = await Note.findOneAndDelete({ title: req.params.name });
    if (deletedNote) {
      res.json({message : "Note Deleted Successfully",note : deletedNote});
    } else {
      res.status(404).json({ message: 'Note not found for deletions' });
    }
    });
}

// API to fetch all notes
app.get('/notes', async (req, res) => {
    const notes = await Note.find();
    res.json(notes);
});

//CREATION OF NOTESS
async function createNotes(){
const note1 = new Note({
    title: "First Note",
    content: "This is my first note",
    noteId: "7555"
})

const note2 = new Note({
    title: "Mathan",
    content: "This is Mathan's note",
    noteId: "7556"
})

    note1.save().then(()=>console.log("Created : \n" + note1)).catch(e=>console.log(e))
    note2.save().then(()=>console.log("Created : \n" + note2)).catch(e=>console.log(e))
}

// createNotes()
// getById()
// updateByName()
// deleteByName()
