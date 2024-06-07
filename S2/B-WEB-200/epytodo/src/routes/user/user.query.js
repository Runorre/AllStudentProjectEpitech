/*
**
** user.js
**
*/

const jwt = require("jsonwebtoken");
const bcrypt = require('bcryptjs');
const saltRounds = 10;

function showusertodo(req, res, db, secret)
{
    const token = req.headers.authorization.split(" ")[1];
    return jwt.verify(token, secret, (err, decode) => {
        if (err)
            return res.status(401).json({"msg": "Token is not valid"});
        db.execute('SELECT * FROM `user` WHERE `password` = ?', [decode], (err, result, fields) => {
            if (err) {
                return res.status(500).json({"msg": " Internal server error "});
            } else if (Object.keys(result).length != 0) {
                db.execute('SELECT * FROM `todo` WHERE `user_id` = ?', [result[0].id], (err, result, fields) => {
                    if (err) {
                        return res.status(500).json({"msg": " Internal server error "});
                    } else if (Object.keys(result).length != 0) {
                        return res.status(200).json(result);
                    } else
                        return res.status(404).json({"msg": "Not found"});
                })
            } else
                return res.status(404).json({"msg": "Not found"});
        })
    })
}

function delete_user(req, res, id, db)
{
    if (id === undefined)
        return res.status(400).json({ "msg": "Bad parameter" });
    return db.execute("DELETE FROM `user` WHERE id = ?", [id], (err, result) => {
        if (err)
            return res.status(500).json({"msg": " Internal server error "});
        else {
            return res.status(200).json({"msg" : `Successfully deleted record number: ${id}`});
        }
    });
}

function put_user(req, res, db, id)
{
    const { email, password, name, firstname } = req.body;
    db.execute('SELECT * FROM `user` WHERE id = ?', [id], (err, result, fields) => {
        if (err)
            return res.status(500).json({"msg": " Internal server error "});
        else if (Object.keys(result).length == 0)
            return res.status(404).json({"msg": "Not found"});
        else {
            if (email === undefined || password === undefined || name === undefined || firstname === undefined) {
                return res.status(400).json({ "msg": "Bad parameter " });
            } else {
                bcrypt.genSalt(saltRounds, function(err, salt) {
                    bcrypt.hash(password, salt, function(err, hash) {
                        if (err)
                            return res.status(500).json({"msg": " Internal server error "});
                        else
                            db.execute('UPDATE `user` SET email = ?, password = ?, name = ?, firstname = ? WHERE id = ?', [email, hash, name, firstname, id], (err, result) => {
                                if (err)
                                    return res.status(500).json({"msg": " Internal server error "});
                                else {
                                    db.execute('SELECT * FROM `user` WHERE id = ?', [id], (err, result) => {
                                        if (err)
                                            return res.status(500).json({"msg": " Internal server error "});
                                        else
                                            return res.status(200).json(result[0]);
                                    })
                                }
                            });
                    })})
            }
        }
    });
}

function showspecuser(req, res, db, find)
{
    return db.execute('SELECT * FROM `user` WHERE email = ? OR id = ?', [find, find], (err, result, fields) => {
        if (err) {
            return res.status(500).json({"msg": " Internal server error "});
        } else if (Object.keys(result).length != 0) {
            return res.status(200).json(result[0]);
        } else
            return res.status(404).json({"msg": "Not found"});
    })
}

module.exports = {put_user, showspecuser, delete_user, showusertodo};
