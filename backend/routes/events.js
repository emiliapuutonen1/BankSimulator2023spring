const express = require('express');
const router = express.Router();
const events = require('../models/events_model');

router.get('/',function(request,response){
    events.getAll(function(err,dbResult){
        if(err){
            response.json(err);
        }
        else {
          
          const formattedResults = dbResult.map(result => {
            result.Date = result.Date ? result.Date.toISOString().slice(0, 10) : null;
            return result;
          });
          response.json(formattedResults);
          
        }
    })
});

router.get('/:id',
    function (request, response) {
        events.getById(request.params.id, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult[0]);
            }
        })
    });


router.post('/', 
function(request, response) {
  events.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/:id', 
function(request, response) {
  events.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:id', 
function(request, response) {
  events.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;
