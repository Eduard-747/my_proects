let mysql = require('mysql');
let dbtypeorm = require('../database/dbtypeorm');
// const con = require("../database/db.js");

// con.connect(function(err) {
//     if (err) {
//         throw err;
//     };
//     console.log("Successfully Connected To DataBase !!!");
// });

const {createConnection} =  require("typeorm");
const config = require("../config.json");

console.log(config);

const connection = async () => await createConnection(config);

console.log(connection);


function getUserEmail (user,res)
{        
    // con.query(`SELECT Email FROM Persons WHERE ID='${user.ID}'`,(err, rows, field) => {
    // if (err) throw err;
    //     res.status(200).send(rows[0]);         
    // })
    // console.log(connection.apply().Age = 34)
    
}

function getUserID (user,res)
{        
    con.query(`SELECT ID FROM Persons WHERE Email='${user.Email}'`,(err, rows, field) => {
        if (err) throw err;
        
        if(rows.length > 0 ) {
            res.status(200).send(rows[0]);
        } else {
            res.status(401).send("Invalid Email !!!");
        }
    })
}

function getUserAge(user, res)
{
    con.query(`SELECT Age FROM Persons WHERE ID='${user.ID}'`,(err, rows, field) => {
        if (err) throw err;
            res.status(200).send(rows[0]);         
    })
}

function modifyAge(user)
{
    con.query(`UPDATE Persons SET Age='${user.Age}' WHERE ID = '${user.ID}';`,(err,rows,fields)=> {
        if(err) throw err;
       
        console.log('Age has Changed');
    })
}

function modifyCountry(user)
{
    con.query(`UPDATE Persons SET Country='${user.Country}' WHERE ID = '${user.ID}';`,(err,rows,fields)=> {
        if(err) throw err;
       
        console.log('Country has Changed');
    })
}

function modifyName(user)
{
    
    con.query(`UPDATE Persons SET Name='${user.Name}' WHERE ID = '${user.ID}';`,(err,rows,fields)=> {
        if(err) throw err;
       
        console.log('Name has Changed');
    })
}

function modifyEmail(user)
{
    
    con.query(`UPDATE Persons SET Email='${user.Email}' WHERE ID = '${user.ID}';`,(err,rows,fields)=> {
        if(err) throw err;
       
        console.log('Email has Changed');
    })
}

function deleteUser(user)
{
    con.query(`DELETE FROM Persons WHERE ID='${user.ID}';`,(err,row,field) =>{
        if(err) throw err;
        console.log("User Has Been Deleted");
    })
}

function create (user){
    con.query(`INSERT INTO Persons (ID,Name,Country,Email,Age) VALUES('${user.ID}','${user.Name}','${user.Country}','${user.Email}','${user.Age}')`,(err,row,field) =>{
        if(err) throw err;
        console.log("Record Inserted");
        console.log(row);
    })
}

module.exports = {
    create : create,
    deleteUser : deleteUser,
    modifyName : modifyName,
    getUserEmail : getUserEmail,
    getUserID : getUserID,
    modifyEmail : modifyEmail,
    modifyCountry : modifyCountry ,
    getUserAge : getUserAge,
    modifyAge : modifyAge
}