
const express = require('express')
const routing = express.Router()

const notes = require('./myNotes.js')

routing.get('/package',notes.package)
routing.post('/bookpackage',notes.bookpackage)
routing.all('*', notes.invalid);

module.exports = routing
