const addon = require('./build/Release/addon');
try {
    const recording = addon.record();
    console.log(recording);

    setTimeout(() => {
        const stopped = addon.stop();
        console.log(stopped);
    }, 10_000);
} catch (e) {
    console.log(e.message);
}