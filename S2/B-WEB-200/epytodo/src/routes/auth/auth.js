const bcrypt = require('bcryptjs');
const jwt = require("jsonwebtoken");
const saltRounds = 10;

function register_action(req, res, secret, db) 
{
    const { email, password, name, firstname } = req.body;
    if (email === undefined || password === undefined || name === undefined || firstname === undefined) {
        res.status(400).json({ error: "missing parameters" });
        return;
    } else {
        db.execute('SELECT * FROM `user` WHERE `email` = ?', [email], (err, result, fields) => {
            if (err)
                return res.status(500).json({"msg": " Internal server error "});
            else if (Object.keys(result).length == 0) {
                bcrypt.genSalt(saltRounds, function(err, salt) {
                    bcrypt.hash(password, salt, function(err, hash) {
                        if (err) {
                            return res.status(500).json({"msg": " Internal server error "});
                        } else {
                            db.execute('INSERT into `user` (email, password, name, firstname) VALUES (?, ?, ?, ?)', [email, hash, name, firstname], (err, result, fields) => {
                                if (err)
                                    return res.status(500).json({"msg": " Internal server error "});
                                else {
                                    const token = jwt.sign(hash, secret);
                                    return res.status(201).json({"token": token});
                                }
                        });
                        }
                    });
                })
            } else
                return res.status(409).json({"msg": "Account already exists"});
        })
    }
}

function login_action(req, res, secret, db) 
{
    const { email, password } = req.body;
    if (email === undefined || password === undefined) {
        res.status(400).json({ error: "missing parameters" });
        return;
    }
    db.execute('SELECT * FROM `user` WHERE `email` = ?', [email], (err, result, fields) => {
        if (err)
            return res.status(500).json({"msg": " Internal server error "});
        else {
            if (Object.keys(result).length == 0)
                return res.status(404).json({"msg": "Invalid Credentials"});
            else {
                const hash = result[0].password;
                bcrypt.compare(password, hash, function(err, result) {
                    if (err)
                        return res.status(500).json({"msg": " Internal server error "});
                    else {
                        if (result) {
                            const token = jwt.sign(hash, secret);
                            return res.status(200).json({"token": token});
                        } else {
                            res.status(401).json({"msg": "Invalid Credentials"});
                        }
                    }
                })
            }
        }
    })
}

function authtoken(req, secret, db)
{
    const token = req.headers.authorization.split(" ")[1];
    return jwt.verify(token, secret, (err, decode) => {
        if (err) {
            return 1;
        } else {
            db.execute('SELECT * FROM `user` WHERE `password` = ?', [decode], (err, result, fields) => {
                if (err) {
                    return 1;
                } else {
                    if (Object.keys(result).length != 0) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            });
        }
    })
}

module.exports = {register_action, login_action, authtoken};
