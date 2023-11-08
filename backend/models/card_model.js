const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;
const card = {
  getAll: function(callback) {
    return db.query('select * from card', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from card where idCard=?', [id], callback);
  },
  add: function(card, callback) {
    bcrypt.hash(card.pincode, saltRounds, function(err, hash) {
    return db.query(
      'insert into card (idCard, pincode, card_type, idClient, idAccount) values(?,?,?,?,?)',
      [card.idCard, hash, card.card_type, card.idClient, card.idAccount],
      callback);
  });
  },
  delete: function(id, callback) {
    return db.query('delete from card where idCard=?', [id], callback);
  }, 
  update: function(id, card, callback) {
    bcrypt.hash(card.pincode, saltRounds, function(err, hash){
    return db.query(
      'update card set idCard=?, pincode=?, card_type=?, idClient=?, idAccount=? where idCard=?',
      [card.idCard, hash, card.card_type, card.idClient, card.idAccount, id],
      callback)
    });
  }
}
module.exports = card;