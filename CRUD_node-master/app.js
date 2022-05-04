const express = require('express');
const controller = require('./controller/controller.js');

const router = express.Router();
const app = express();

app.use(express.json());

app.use(router); 

router.post('/register', controller.register);
router.get('/login', controller.login);
router.put('/modify', controller.update);
router.delete('/deleteUser',controller.deleteUser);


app.listen(3034, function(err) {
  if(err) throw err;
  console.log('Listening on Port 3003');
});

