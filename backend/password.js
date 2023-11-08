const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const salt = 10;

router.get('/', function(req, res){
    bcrypt.hash('1234',salt, function (err, hashed){
        console.log(hashed)
    });
    bcrypt.hash('1234',salt, function (err, hashed){
        console.log(hashed)
    });

    bcrypt.compare(req.body.password,req.body.hash, function (err, hashed){
        console.log(hashed)
        res.send(hashed)
    })
});

module.exports=router;