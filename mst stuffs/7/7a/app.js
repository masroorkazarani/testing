
const express = require('express');
const route = require("./route.js")
const app = express();
app.use('/',route)

app.listen(3000,()=>{
    console.log("Listening on Port : 3000")
})
