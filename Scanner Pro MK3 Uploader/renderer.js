const ipc = require('electron').ipcRenderer;

const comPort = document.getElementById('comPort')
const comButton = document.getElementById('comButton')
const fileButton = document.getElementById('file')
const run = document.getElementById('run')

comButton.addEventListener('click', () => {
    ipc.send('comPort', comPort.value)
})

fileButton.addEventListener('click', () => {
    ipc.send('open-file-dialog-for-file')
})

run.addEventListener('click', () => {
    ipc.send('run')
})

var stdoutDiv = document.getElementById('stdout')
ipc.on('avrdude', function (event, output) {
    stdoutDiv.innerHTML += output
});

