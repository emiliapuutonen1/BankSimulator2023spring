var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var clientRouter = require('./routes/client');
var passwordRouter = require('./password');
var accountRouter = require('./routes/account');
var cardRouter = require('./routes/card');
var eventsRouter = require('./routes/events');


var app = express();


app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/account', accountRouter);
app.use('/client', clientRouter);
app.use('/card', cardRouter);
app.use('/events', eventsRouter);
app.use('/password', passwordRouter);



module.exports = app;
