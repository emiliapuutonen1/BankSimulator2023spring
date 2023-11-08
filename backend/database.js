
const mysql = require('mysql2');
const dotenv=require('dotenv');

dotenv.config();

const connection = mysql.createConnection({
  host: '127.0.0.1',
  user: 'netuser',
  password: 'netpass',
  database: 'bankSimul_O_R20db'
});

module.exports = connection;


