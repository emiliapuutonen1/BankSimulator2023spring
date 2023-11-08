const db = require('../database');

const client = {
  getAll: function(callback) {
    return db.query('select * from client', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from client where idClient=?', [id], callback);
  },
  add: function(client, callback) {
    return db.query(
      'insert into client (idClient, Client_firstname,Client_lastname) values(?,?,?)',
      [client.idClient, client.Client_firstname, client.Client_lastname],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from client where idClient=?', [id], callback);
  }, 
  update: function(id, client, callback) {
    return db.query(
      'update client set client_firstname=?, client_lastname=? where idClient=?',
      [client.Client_firstname, client.Client_lastname, id],
      callback
    );
  }
};
module.exports = client;