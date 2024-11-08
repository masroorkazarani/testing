const express = require('express')
const router = express.Router()
const notes = require('./myNotes.js')

router.get('/',notes.homePage)
router.get('/about',notes.aboutPage)

module.exports = router
