#include "WorkletsTurboModule.h"
#include "RNOH/ArkTSTurboModule.h"
#include "WKTJsiWorkletApi.h"

using namespace rnoh;
using namespace facebook;

namespace rnoh {
    jsi::Value install(facebook::jsi::Runtime &rt, react::TurboModule &turboModule, const facebook::jsi::Value *args,
                       size_t count) {
        auto self = static_cast<RNCWorkletsTurboModule *>(&turboModule);
        self->install(rt);
        return facebook::jsi::Value::undefined();
    }

    RNCWorkletsTurboModule::RNCWorkletsTurboModule(const ArkTSTurboModule::Context ctx, const std::string name)
        : ArkTSTurboModule(ctx, name) {
        methodMap_ = {{"install", {0, rnoh::install}}};
    }

    void RNCWorkletsTurboModule::install(facebook::jsi::Runtime &rt) {
        auto jsInvoker = this->jsInvoker_;
        RNWorklet::JsiWorkletContext::getDefaultInstance()->initialize(
            "default", &rt, [=](std::function<void()> &&f) { jsInvoker->invokeAsync(std::move(f)); });

        RNWorklet::JsiWorkletApi::installApi(rt);
    }
} // namespace rnoh
