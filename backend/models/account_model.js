
const db = require('../database');


const account = {
  getAll: function(callback) {
    return db.query('select * from account', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from account where idAccount=?', [id], callback);
  },
  add: function(account, callback) {
    
      return db.query(
        'insert into account (idAccount, creditAccountNumber, debitAccountNumber, creditBalance, creditWithdrawal, creditLimit, debitBalance, debitWithdrawal, idClient) values(?,?,?,?,?,?,?,?,?)',
        [account.idAccount, account.creditAccountNumber, account.debitAccountNumber, account.creditBalance, account.creditWithdrawal, account.creditLimit, account.debitBalance, account.debitWithdrawal, account.idClient],
        callback
      );
    
  },
  delete: function(id, callback) {
    return db.query('delete from account where idAccount=?', [id], callback);
  }, 
  update: function(id, account, callback) {
  
      return db.query(
        'update account set creditAccountNumber=?, debitAccountNumber=?, creditBalance=?, creditWithdrawal=?, creditLimit=?, debitBalance=?, debitWithdrawal=?, idClient=? where idAccount=?',
        [account.creditAccountNumber, account.debitAccountNumber, account.creditBalance, account.creditWithdrawal, account.creditLimit, account.debitBalance, account.debitWithdrawal, account.idClient, id],
        callback
      );
    }
  }


module.exports = account;
