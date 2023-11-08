const db = require('../database');


const events = {
  getAll: function(callback) {
    return db.query('select * from events', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from events where idEvents=?', [id], callback);
  },
  add: function(events, callback) {
    return db.query(
      'insert into events (idEvents, Date , Time, Transactions, Amount, idAccount) values(?,?,?,?,?)',
      [events.idEvents, events.Date, events.Time, events.Transactions, events.Amount, events.idAccount],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from events where idevents=?', [id], callback);
  }, 
  update: function(id, events, callback) {
    return db.query(
      'update events set Date=?, Time=?, Transactions=?, Amount=?, idAccount=? where idevents=?',
      [events.Date, events.Time, events.Transactions, events.Amount, events.idAccount, id],
      callback
    );
  }
};
module.exports = events;