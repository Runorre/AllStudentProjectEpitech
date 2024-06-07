/*
**
** user.js
**
*/

const jwt = require("jsonwebtoken");

function showalluser(req, res, db, secret) {
    const token = req.headers.authorization.split(" ")[1];
    return jwt.verify(token, secret, (err, decode) => {
        if (err)
            return res.status(401).json({"msg": "Token is not valid"});
        db.execute('SELECT * FROM `user` WHERE `password` = ?', [decode], (err, result, fields) => {
            if (err) {
                return res.status(500).json({"msg": " Internal server error "});
            } else if (Object.keys(result).length != 0) {
                return res.status(200).json(result[0]);
            } else
                return res.status(404).json({"msg": "Not found"});
        })
    })
}

module.exports = showalluser
