// Setup reference: https://github.com/nodejs/node-addon-api/blob/main/doc/setup.md
#include <napi.h>
#include <cstdlib> // for system() function

Napi::String Stop(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::String::New(env, "Recording stopped.");
}

Napi::String Record(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::String::New(env, "Recording started.");
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    // Mapping the functions to the Node.js code
    exports.Set(Napi::String::New(env, "record"), Napi::Function::New(env, Record));
    exports.Set(Napi::String::New(env, "stop"), Napi::Function::New(env, Stop));
    return exports;
}

NODE_API_MODULE(addon, Init)