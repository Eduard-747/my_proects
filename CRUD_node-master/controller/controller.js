const { use } = require('express/lib/application');
const service = require('../service/service.js');

function register(req, res) 
{
    const user = req.body;
    service.create(user);
    res.status(200).send('account created!!!');     
}

function login(req, res) 
{
    const user = req.body;
    for(let key in req.body) 
        if(key === 'ID')
            service.getUserEmail(user, res);
        else if(key === 'Email')
            service.getUserID(user, res);
}

function update(req, res) 
{
    const user = req.body;
    for(let key in req.body) 
        if(key === 'Name') {
            service.modifyName(user);
            res.status(200).send('Name has changed !!!');
        } else if(key === 'Email') {
            service.modifyEmail(user);
            res.status(200).send('Email has changed !!!');
        } else if(key === 'Country') {
            service.modifyCountry(user);
            res.status(200).send('Country has changed !!!');
        } else if(key === 'Age') {
            service.modifyAge(user);
            res.status(200).send('Age has been changes !!!');
        }
}

function deleteUser (req,res) 
{
    const user = req.body;
    console.log(user);
    service.deleteUser(user);
    res.status(200).send('Your Account has been deleted !!!');
}

module.exports = {
    register : register,
    login : login,
    update : update,
    deleteUser : deleteUser
}