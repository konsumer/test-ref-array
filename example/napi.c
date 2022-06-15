// this is the NAPI wrapper

#include <node_api.h>
#include "example.h"

napi_value wrap_exampleInput(napi_env env, napi_callback_info info) {
  return 0;
}

napi_value wrap_exampleOutput(napi_env env, napi_callback_info info) {
  return 0;
}


napi_value Init(napi_env env, napi_value exports) {
  napi_status status;
  napi_value fn;

  status = napi_create_function(env, NULL, 1, wrap_exampleInput, NULL, &fn);
  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Unable to wrap native exampleInput function");
  }

  status = napi_set_named_property(env, exports, "exampleInput", fn);
  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Unable to populate exports with exampleInput");
  }

  status = napi_create_function(env, NULL, 0, wrap_exampleOutput, NULL, &fn);
  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Unable to wrap native exampleOutput function");
  }

  status = napi_set_named_property(env, exports, "exampleOutput", fn);
  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Unable to populate exports with exampleOutput");
  }

  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)