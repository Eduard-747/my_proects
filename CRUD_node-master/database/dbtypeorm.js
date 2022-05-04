// Standard requires
const EntitySchema = require('typeorm').EntitySchema;

// Local requires
const Usermod = require('./model/usermodel.js');

module.exports = new EntitySchema({
    tableName: 'my_db',
    target: Usermod,
    columns: {
        ID: {
            primary: true,
            name: 'ID',
            type: 'int',
            generated: true,
            unique: true
        },
        Name: {
            name: 'Name',
            type: 'varchar',
        },
        Country: {
            name: 'Country',
            type: 'varchar',
        },
        Email: {
            name: 'Email',
            type: 'varchar',
            default: null
        },
        Age: {
            name: 'Age',
            type: 'varchar',
            createDate: true
        }
    }
});