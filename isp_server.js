var express = require("express");
var os = require("os");
var fs = require("fs");
var bodyParser = require('body-parser');

var _server = express();

_server.use(bodyParser.urlencoded({extended:true}));
_server.listen(80,'127.0.0.1');

_server.post("/sensors_data",function(req,res) {
	res.send("ACK");
	
	fs.writeFile("sensors_data.txt","T",function(err){
		if (err) console.log("error during writing to file");
	});

	fs.appendFile("sensors_data.txt",os.EOL,function(err){
		if (err) console.log("error during writing to file");
	});

	fs.appendFile("sensors_data.txt",req.body.temperature,function(err){
		if(err) console.log("error during writing to file");
	});

	fs.appendFile("sensors_data.txt",os.EOL,function(err){
		if (err) console.log("error during writing to file");
	});

	fs.appendFile("sensors_data.txt","M",function(err){
		if (err) console.log("error during writing to file");
	});

	fs.appendFile("sensors_data.txt",os.EOL,function(err){
		if (err) console.log("error during writing to file");
	});

	fs.appendFile("sensors_data.txt",req.body.magnetic,function(err){
		if (err) console.log("error during writing to file");
	});

	fs.appendFile("sensors_data.txt",os.EOL,function(err){
		if (err) console.log("error during writing to file");
	});

	fs.appendFile("sensors_data.txt","D",function(err){
		if (err) console.log("error during writing to file");
	});

	fs.appendFile("sensors_data.txt",os.EOL,function(err){
		if (err) console.log("error during writing to file");
	});

	fs.appendFile("sensors_data.txt",req.body.distance,function(err){
		if (err) console.log("error during writing to file");
	});	
});



