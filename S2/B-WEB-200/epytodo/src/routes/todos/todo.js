/*
**
** todo.js
**
*/

function showalltodo(req, res, db)
{
    db.execute('SELECT * FROM `todo`', (err, result) => {
        if (err)
            return res.status(500).json({"msg": " Internal server error "});
        else {
            return res.status(200).json(result);
        }
    });
}

function showonetodo(req, res, db, id)
{
    db.execute('SELECT * FROM `todo` WHERE id = ?', [id],(err, result) => {
        if (err)
            return res.status(500).json({"msg": " Internal server error "});
        else if (Object.keys(result).length != 0)
            return res.status(200).json(result[0]);
        else
            return res.status(404).json({"msg": "Not found"});
    });
}

module.exports = {showalltodo, showonetodo}
