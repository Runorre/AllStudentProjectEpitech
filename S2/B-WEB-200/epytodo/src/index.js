const express = require("express");
var bodyParser = require('body-parser');
const dotenv = require("dotenv");
const db = require("./config/db");
const { register_action, login_action, authtoken } = require("./routes/auth/auth");
const showalluser = require("./routes/user/user");
const { showspecuser, put_user, delete_user, showusertodo } = require("./routes/user/user.query");
const {showalltodo, showonetodo} = require("./routes/todos/todo");
const { post_todo, put_todo, delete_todo } = require("./routes/todos/todo.query");
const app = express();
dotenv.config();


app.post("/register", bodyParser.json(), (req, res) => register_action(req, res, process.env.SECRET, db));

app.post("/login", bodyParser.json(), (req, res) => login_action(req, res, process.env.SECRET, db));

app.get("/user", (req, res) => {
    if (!req.headers.authorization)
        return res.status(401).json({ "msg": "No token, authorization denied"});
    if (authtoken(req, process.env.SECRET, db) == 1)
        return res.status(401).json({"msg": "Token is not valid"});
    return showalluser(req, res, db, process.env.SECRET);
});

app.get("/user/todos", (req, res) => {
    if (!req.headers.authorization)
        return res.status(401).json({ "msg": "No token, authorization denied"});
    if (authtoken(req, process.env.SECRET, db) == 1)
        return res.status(401).json({"msg": "Token is not valid"});
    return showusertodo(req, res, db, process.env.SECRET);
})

app.get('/users/:id', (req, res) => {
    if (!req.headers.authorization)
        return res.status(401).json({ "msg": "No token, authorization denied"});
    if (authtoken(req, process.env.SECRET, db) == 1)
        return res.status(401).json({"msg": "Token is not valid"});
    return showspecuser(req, res, db, req.params.id);
});

app.put('/users/:id', bodyParser.json(), (req, res) => {
    if (!req.headers.authorization)
        return res.status(401).json({ "msg": "No token, authorization denied"});
    if (authtoken(req, process.env.SECRET, db) == 1)
        return res.status(401).json({"msg": "Token is not valid"});
    return put_user(req, res, db, req.params.id);
});

app.delete("/users/:id", (req, res) => {
    if (!req.headers.authorization)
        return res.status(401).json({ "msg": "No token, authorization denied"});
    if (authtoken(req, process.env.SECRET, db) == 1)
        return res.status(401).json({"msg": "Token is not valid"});
    return delete_user(req, res, req.params.id, db);
})

app.get("/todos", (req, res) => {
    if (!req.headers.authorization)
        return res.status(401).json({ "msg": "No token, authorization denied"});
    if (authtoken(req, process.env.SECRET, db) == 1)
        return res.status(401).json({"msg": "Token is not valid"});
    return showalltodo(req, res, db);
})

app.get("/todos/:id", (req, res) => {
    if (!req.headers.authorization)
        return res.status(401).json({ "msg": "No token, authorization denied"});
    if (authtoken(req, process.env.SECRET, db) == 1)
        return res.status(401).json({"msg": "Token is not valid"});
    return showonetodo(req, res, db, req.params.id);
})

app.post("/todos", bodyParser.json(), (req, res) => {
    if (!req.headers.authorization)
        return res.status(401).json({ "msg": "No token, authorization denied"});
    if (authtoken(req, process.env.SECRET, db) == 1)
        return res.status(401).json({"msg": "Token is not valid"});
    return post_todo(req, res, db);
})

app.put("/todos/:id", bodyParser.json(), (req, res) => {
    if (!req.headers.authorization)
        return res.status(401).json({ "msg": "No token, authorization denied"});
    if (authtoken(req, process.env.SECRET, db) == 1)
        return res.status(401).json({"msg": "Token is not valid"});
    return put_todo(req, res, db, req.params.id);
})

app.delete("/todos/:id", (req, res) => {
    if (!req.headers.authorization)
        return res.status(401).json({ "msg": "No token, authorization denied"});
    if (authtoken(req, process.env.SECRET, db) == 1)
        return res.status(401).json({"msg": "Token is not valid"});
    return delete_todo(req, res, db, req.params.id);
});

app.listen(process.env.PORT, () => {
    console.log(`App start on http://localhost:${process.env.PORT}`);
});