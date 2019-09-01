const ipc = require('electron').ipcRenderer;
var serialport = require("serialport");

document.addEventListener('DOMContentLoaded', pageLoaded);

var com;
var port;
var connected

const fileButton = document.getElementById('file')
fileButton.addEventListener('click', () => {
    ipc.send('open-file-dialog-for-file')
})

const run = document.getElementById('run')
run.addEventListener('click', () => {
    ipc.send('run')
})

var stdoutDiv = document.getElementById('stdout')
ipc.on('avrdude', function (event, output) {
    if (output == '#' || output == '##') {
        stdoutDiv.innerHTML += output
    }
    else {
        stdoutDiv.innerHTML += output + '<br>'
    }
    
    stdoutDiv.scrollTop = stdoutDiv.scrollHeight;
});

var fileDisplay = document.getElementById('fileDisplay')
ipc.on('fileDisplay', function (event, output) {
    if (output != null) {
        run.disabled = false;
    }
    fileDisplay.value = output
});

const serialData = document.getElementById('serial')
const send = document.getElementById('send')
send.addEventListener('click', () => {
    sendCommand();
})
serialData.addEventListener("keydown", function (e) {
    if (e.keyCode === 13) {
        sendCommand();
    }
});

function sendCommand() {
    var data = serialData.value + "<>"
    console.log(data);


    port.write(data, function(err) {
        if (err) {
            return stdoutDiv.innerHTML += 'Error on write: ' + err.message
        }
    })
}

const connect = document.getElementById('connect')
connect.addEventListener('click', () => {
    port = new serialport(com, {
        baudRate: 9600
    })

    port.on('data', function (data) {
        stdoutDiv.innerHTML += data + "<br>"
        stdoutDiv.scrollTop = stdoutDiv.scrollHeight;
    })

    port.on('error', function(err) {
        stdoutDiv.innerHTML += err + "<br>"
        stdoutDiv.scrollTop = stdoutDiv.scrollHeight;
    })

    port.on('open', function(err) {
        stdoutDiv.innerHTML += "Successfully connected to device <br>"
        serialData.disabled = false;
        send.disabled = false;

        connect.disabled = true;
        close.disabled = false;
        stdoutDiv.scrollTop = stdoutDiv.scrollHeight;
    })

    port.on('close', function(err) {
        stdoutDiv.innerHTML += "Device disconnected! <br>"
        serialData.disabled = true;
        send.disabled = true;

        connect.disabled = false;
        close.disabled = true;
        stdoutDiv.scrollTop = stdoutDiv.scrollHeight;
    })

})

const close = document.getElementById('close')
close.addEventListener('click', () => {
    port.close()
})

var option = document.createElement("option");
const update = document.getElementById('update')
update.addEventListener('click', () => {
    option.length = 0;
    serialport.list(function (err, ports) {
        if (ports.length == 0) {
            option.text = 'No devices';
            comPort.add(option);
            selectCom("No-Devices");
        }
        ports.forEach(function(port) {
            var text = port.comName + " - " + port.manufacturer;
            option.text = text;
            selectCom(text);
            comPort.add(option);
        });
    });
})

const comPort = document.getElementById('comPort')
function pageLoaded() {
    serialData.disabled = true;
    send.disabled = true;
    close.disabled = true;
    run.disabled = true;

    serialport.list(function (err, ports) {
        if (ports.length == 0) {
            option.text = 'No devices';
            comPort.add(option);
            selectCom("No-Devices");
        }
        ports.forEach(function(port) {
            var text = port.comName + " - " + port.manufacturer;
            option.text = text;
            selectCom(text);
            comPort.add(option);
        });
    });
 }

 function selectCom(port) {
     if (port == 'No-Devices') {
         fileButton.disabled = true;
         connect.disabled = true;
     } else {
        fileButton.disabled = false;
        connect.disabled = false;
        var comParse = port.split(" -");
        ipc.send('comPort', comParse[0])
        com = comParse[0];
     }
 }