const express = require('express')
const route = require('./route')
const app = express()

const logger= function(req,res,next){
    console.log(req.method)
    console.log(req.url)
    next()
}

app.use(logger)
app.use('/',route)

app.listen(3000,()=>{
    console.log('Listening on Port:3000')
})
