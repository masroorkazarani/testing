
exports.homePage = async(req,res,next) => {
    res.send("<h1>WELCOME</h1>")
}

exports.aboutPage = async(req,res,next) => {
    res.send("<h1>ABOUT</h1>")
}
