#define NAPI_DISABLE_CPP_EXCEPTIONS
#include <napi.h>

using Napi::CallbackInfo;
using Napi::Env;
using Napi::Function;
using Napi::Number;
using Napi::Object;
using Napi::String;
using Napi::TypeError;

Number addTwo(const CallbackInfo &info)
{
    Env env = info.Env();

    // check if arguments are numbers
    if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber())
    {
        TypeError::New(env, "Expected two numbers as arguments").ThrowAsJavaScriptException();
        return Number::New(env, 0); // return default value
    }

    double arg0 = info[0].As<Number>().DoubleValue();
    double arg1 = info[1].As<Number>().DoubleValue();
    double sum = arg0 + arg1;
    return Number::New(env, sum);
}

Object Init(Env env, Object exports)
{
    exports.Set(String::New(env, "addTwo"),
                Function::New(env, addTwo));
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
