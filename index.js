const addon = require('./build/Release/addon');

try {
    console.log(addon.enumerateWindows());
    console.log(addon.add(1,2));

    // @TODO
    // const windows = addon.getRunningWindow();
    // addon.startRecording(windows[0]);
    // setTimeout(() => {
    //  addon.stopRecording();
    // }, 10_000);

} catch (e) {
    console.log(e.message);
}