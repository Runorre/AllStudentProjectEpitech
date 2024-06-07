/*
**
** todo.js
**
*/

function delete_todo(req, res, db, id)
{
    db.execute('DELETE FROM `todo` WHERE id = ?', [id], (err, result) => {
        if (err)
            return res.status(500).json({"msg": " Internal server error "});
        else if (result.affectedRows == 0)
            return res.status(404).json({"msg": "Not found"});
        else
            return res.status(200).json({"msg" : `Successfully deleted record number: ${id}`});
    });
}

function put_todo(req, res, db, id)
{
    const {title, description, due_time, user_id, status} = req.body;
    db.execute('SELECT * FROM `todo` WHERE id = ?', [id], (err, result) => {
        if (err)
            return res.status(500).json({"msg": " Internal server error "});
        else if (Object.keys(result).length == 0)
            return res.status(404).json({"msg": "Not found"});
        else {
            db.execute('UPDATE `todo` SET title = ?, description = ?, due_time = ?, user_id = ?, status = ? WHERE id = ?', [title, description, due_time, user_id, status, id], (err, result) => {
                if (err)
                    return res.status(500).json({"msg": " Internal server error "});
                else {
                    return res.status(200).json(req.body);
                }
            });
        }
    });
}

function post_todo(req, res, db)
{
    const {title, description, due_time, user_id, status} = req.body;
    if (title == undefined || description == undefined || due_time == undefined || user_id == undefined || status == undefined)
        return res.status(400).json({"msg": "Bad request"});
    db.execute('INSERT INTO `todo` (title, description, due_time, user_id, status) VALUES (?, ?, ?, ?, ?)', [title, description, due_time, user_id, status], (err, result) => {
        if (err)
            return res.status(500).json({"msg": " Internal server error "});
        else {
            db.execute('SELECT * FROM `todo` WHERE id = ?', [result.insertId], (err, result) => {
                if (err)
                    return res.status(500).json({"msg": " Internal server error "});
                else
                    return res.status(200).json(result[0]);
            })
        }
    })
}

module.exports = {post_todo, put_todo, delete_todo}
