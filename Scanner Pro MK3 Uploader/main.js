const { app, BrowserWindow, dialog } = require('electron')
const ipc = require('electron').ipcMain
const os = require('os');
var spawn = require('child_process').spawn

let win

function createWindow () {
  // Create the browser window.
  win = new BrowserWindow({
    width: 800,
    height: 600,
    webPreferences: {
      nodeIntegration: true
    }
  })

  // and load the index.html of the app.
  win.loadFile('index.html')

  // Open the DevTools.
  win.webContents.openDevTools()

  // Emitted when the window is closed.
  win.on('closed', () => {
    win = null
  })
}

app.on('ready', createWindow)

// Quit when all windows are closed.
app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') {
    app.quit()
  }
})

app.on('activate', () => {
  if (win === null) {
    createWindow()
  }
})

ipc.on('open-file-dialog-for-file', function (event) {
  if(os.platform() === 'linux' || os.platform() === 'win32'){
     dialog.showOpenDialog({
         properties: ['openFile']
     }, function (files) {
        if (files) {
          runAvrdude('COM8', files[0], event);
        }
     });
 } else {
     dialog.showOpenDialog({
         properties: ['openFile', 'openDirectory']
     }, function (files) {
         if (files) {
            runAvrdude('COM8', files[0], event);
         }
     });
 }});

function runAvrdude(port, file, event) {
  avrdude = spawn('./avrdude/32u4Upload.exe', [port, file]);

  avrdude.stdout.on('data', function (data) {
    event.sender.send('avrdude', data.toString());
  });

  avrdude.stderr.on('data', function (data) {
    event.sender.send('avrdude', data.toString());
  });

  avrdude.on('exit', function (code) {
    event.sender.send('avrdude', code.toString());
  });
}

var serialport = require("serialport");
serialport.list(function (err, ports) {
    ports.forEach(function(port) {
      console.log(port.comName);
      console.log(port.pnpId);
      console.log(port.manufacturer);
    });
});