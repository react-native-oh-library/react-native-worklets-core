#pragma once
#include <ReactCommon/TurboModule.h>
#include "RNOH/ArkTSTurboModule.h"

namespace rnoh {
    class JSI_EXPORT RNCWorkletsTurboModule : public ArkTSTurboModule {
    public:
        RNCWorkletsTurboModule(const ArkTSTurboModule::Context ctx, const std::string name);
        void install(facebook::jsi::Runtime &rt);
    };
} // namespace rnoh