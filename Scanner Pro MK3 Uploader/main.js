const { app, BrowserWindow, dialog } = require('electron')
const ipc = require('electron').ipcMain
const os = require('os');
var spawn = require('child_process').spawn

let win
let file
let comPort

function createWindow () {
  // Create the browser window.
  win = new BrowserWindow({
    width: 1000,
    height: 600,
    resizable: false,
    webPreferences: {
      nodeIntegration: true
    }
  })

  //win.removeMenu()

  // and load the index.html of the app.
  win.loadFile('index.html')

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
          file = files[0]
          win.webContents.send('fileDisplay', file);
        }
     });
 } else {
     dialog.showOpenDialog({
         properties: ['openFile', 'openDirectory']
     }, function (files) {
         if (files) {
          file = files[0]
          win.webContents.send('fileDisplay', file);
         }
     });
 }});

 ipc.on('comPort', function (event, data) {
   comPort = data
 })

var serialport = require("serialport");
ipc.on('run', function (event, data) {

  serialport.list(function (err, ports) {
    ports.forEach(function(port) {
      if (port.comName == comPort) {
        win.webContents.send('avrdude', 'productId: ' + port.serialNumber);
        resetPort(port.serialNumber);
      }
    });
  });
})

function resetPort(ID) {
  win.webContents.send('avrdude', 'Attempting to connect to device 1200bps');

  const avrport = new serialport(comPort, {
    baudRate: 1200
  })

  avrport.on('open', function() {
    win.webContents.send('avrdude', 'Connected!');
    setTimeout(() => {
      win.webContents.send('avrdude', 'Closing port!');
      avrport.close();
    }, 100);

    setTimeout(() => {
      serialport.list(function (err, ports) {
        ports.forEach(function(port) {          
          if (port.serialNumber == ID) {
            win.webContents.send('avrdude', 'New port is: ' + port.comName);

            win.webContents.send('avrdude', 'Running Avrdude...');
            avrdude(port.comName, file);
          }
        });
      });
    }, 1000);
  })

  avrport.on('error', function(err) {
    win.webContents.send('avrdude', err.toString());
  })
}

function avrdude(port, file) { 
  if (process.platform === "win32") {
    avrdude = spawn('./avrdude/avrdude.exe', ['-p', 'atmega32u4', '-C', './avrdude/avrdude.conf', '-c', 'avr109', '-b', '57600', '-D', '-P', port, '-U', 'flash:w:' + file + ':i']);
  } else {
    avrdude = spawn('avrdude', ['-p', 'atmega32u4', '-C', './avrdude/avrdude.conf', '-c', 'avr109', '-b', '57600', '-D', '-P', port, '-U', 'flash:w:' + file + ':i']);
  }
  avrdude.stdout.on('data', function (data) {
    win.webContents.send('avrdude', data.toString());
  });

  avrdude.stderr.on('data', function (data) {
    win.webContents.send('avrdude', data.toString());
  });

  avrdude.on('exit', function (code) {
    win.webContents.send('avrdude', 'Process exited with code: ' + code.toString() + '<br><br>');
  });
}