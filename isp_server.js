var express = require("express");
var os = require("os");
var fs = require("fs");
var bodyParser = require('body-parser');
var sleeper = require('system-sleep');
var request = require('request');

var _server = express();

_server.use(bodyParser.urlencoded({extended:true}));
_server.listen(80,'127.0.0.1');

_server.post("/sensors_data",function(req,res) {
	request({
	url: 'http://alfa.smartstorm.io/api/v1/measure',
	method: 'POST',
	json: {"user_id":"esp8266@test.com","sensor_id":"5a5a34e7498f190f7a9ef50b","desc":"temperature","measure_value":20}
	});
	request({
	url: 'http://alfa.smartstorm.io/api/v1/measure',
	method: 'POST',
	json: {"user_id":"esp8266@test.com","sensor_id":"5a5a34f2498f190f7a9ef50c","desc":"magnetic sensor state","measure_value":1}
	});	
	res.send("ACK");	
});



