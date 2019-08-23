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
    width: 600,
    height: 500,
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
          file = files[0]
        }
     });
 } else {
     dialog.showOpenDialog({
         properties: ['openFile', 'openDirectory']
     }, function (files) {
         if (files) {
          file = files[0]
         }
     });
 }});

 ipc.on('comPort', function (event, data) {
   comPort = data
 })

 ipc.on('run', function (event, data) {
  runAvrdude(comPort, file)
 })

function runAvrdude(port, file) {
  avrdude = spawn('./avrdude/32u4Upload.exe', [port, file]);

  avrdude.stdout.on('data', function (data) {
    win.webContents.send('avrdude', data.toString());
  });

  avrdude.stderr.on('data', function (data) {
    win.webContents.send('avrdude', data.toString());
  });

  avrdude.on('exit', function (code) {
    win.webContents.send('avrdude', code.toString());
  });
}

