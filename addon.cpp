// Setup reference: https://github.com/nodejs/node-addon-api/blob/main/doc/setup.md
#include <napi.h>

// Basic Example Hello World
Napi::String EnumerateWindows(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::String::New(env, "World");
}

// Basic Example addition that accepts params from nodejs
Napi::Value Add(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    int arg0 = info[0].As<Napi::Number>().DoubleValue();
    int arg1 = info[1].As<Napi::Number>().DoubleValue();
    Napi::Number num = Napi::Number::New(env, arg0 + arg1);

    return num;
}

// @TODO
// GetRunningWindow() return array of windows
// StartRecording(windowID) return stream buffer
// StopRecording() return boolean

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    // Mapping the functions to the nodeJS code
    exports.Set(Napi::String::New(env, "enumerateWindows"), Napi::Function::New(env, EnumerateWindows));
    exports.Set(Napi::String::New(env, "add"), Napi::Function::New(env, Add));
    return exports;
}

NODE_API_MODULE(addon, Init)