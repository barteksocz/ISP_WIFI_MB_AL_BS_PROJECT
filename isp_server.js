var express = require("express");
var os = require("os");
var fs = require("fs");
var bodyParser = require('body-parser');
var sleeper = require('system-sleep');

var _server = express();

function isp_wait(){
	sleeper(10);
}

_server.use(bodyParser.urlencoded({extended:true}));
_server.listen(80,'127.0.0.1');

_server.post("/sensors_data",function(req,res) {
	
	fs.writeFile("sensors_data.txt","T",function(err){
		if (err) console.log("error during writing to file");
	});
	isp_wait();
	fs.appendFile("sensors_data.txt",os.EOL,function(err){
		if (err) console.log("error during writing to file");
	});
	isp_wait();
	fs.appendFile("sensors_data.txt",req.body.temperature,function(err){
		if(err) console.log("error during writing to file");
	});
	isp_wait();
	fs.appendFile("sensors_data.txt",os.EOL,function(err){
		if (err) console.log("error during writing to file");
	});
	isp_wait();
	fs.appendFile("sensors_data.txt","M",function(err){
		if (err) console.log("error during writing to file");
	});
	isp_wait();
	fs.appendFile("sensors_data.txt",os.EOL,function(err){
		if (err) console.log("error during writing to file");
	});
	isp_wait();
	fs.appendFile("sensors_data.txt",req.body.magnetic,function(err){
		if (err) console.log("error during writing to file");
	});
	isp_wait();
	fs.appendFile("sensors_data.txt",os.EOL,function(err){
		if (err) console.log("error during writing to file");
	});
	isp_wait();
	fs.appendFile("sensors_data.txt","D",function(err){
		if (err) console.log("error during writing to file");
	});
	isp_wait();
	fs.appendFile("sensors_data.txt",os.EOL,function(err){
		if (err) console.log("error during writing to file");
	});
	isp_wait();
	fs.appendFile("sensors_data.txt",req.body.distance,function(err){
		if (err) console.log("error during writing to file");
	});
	res.send("ACK");	
});



