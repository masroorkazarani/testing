
exports.package = async (req,res) => {
    try {
        res.status(200).json({status:"pass",message : "SUCCESSFUL 200"})
    } catch (error) {
        res.status(404).json({status:"fail",message:"UNSUCCESSFUL PACKAGES 404"})
    }
}

exports.bookpackage = async (req,res) => {
    try {
        res.status(201).json({status:"pass",message : "SUCCESSFUL 201"})
    } catch (error) {
        res.status(404).json({status:"fail",message:"UNSUCCESSFUL BOOKPACKAGES 404"})
    }
}

exports.invalid = async (req,res) => {
    res.status(404).json({status:"fail",message:"UNSUCCESSFUL INVALID 404"})
}
