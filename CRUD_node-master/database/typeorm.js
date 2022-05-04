// Standard requires
const typeorm = require("typeorm"); 

// Library requires

class Typeorm {

        constructor() {

            console.log('constructor');
            this.connection = undefined;
            const c = {
                type: "mysql",
                host: "localhost",
                port: 3000,
                username: "root",
                password: "qwer1234",
                database: "my_db",
                synchronize: true,
                logging: false,
                ...{ entities: [
                    require('./dbtypeorm')
                ] }
            };
            
            this.initialized = new Promise((resolve, reject) => {
                typeorm.createConnection(c).then((connection) => {
                    this.connection = connection;
                    resolve();
                })
                .catch(function(error) {
                    console.log("Error: ", error);
                    reject();
                });
            });
        }

}

module.exports = new Typeorm();
