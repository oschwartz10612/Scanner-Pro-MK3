const ipc = require('electron').ipcRenderer;

document.getElementById('test').addEventListener('click', () => {
    ipc.send('open-file-dialog-for-file')
})

var stdoutDiv = document.getElementById('stdout')
ipc.on('avrdude', function (event, output) {
    stdoutDiv.innerHTML += output
});