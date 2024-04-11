#ifndef WORKLETSPACKAGE_H
#define WORKLETSPACKAGE_H

#include "RNOH/Package.h"
#include "WorkletsTurboModule.h"

using namespace rnoh;
using namespace facebook;

class NativeRNCWorkletsTurboModuleFactoryDelegate : public TurboModuleFactoryDelegate {
public:
    SharedTurboModule createTurboModule(Context ctx, const std::string &name) const override {
        if (name == "Worklets") {
            return std::make_shared<RNCWorkletsTurboModule>(ctx, name);
        }
        return nullptr;
    }
};

namespace rnoh {
    class WorkletsPackage : public Package {
    public:
        WorkletsPackage(Package::Context ctx) : Package(ctx) {}
        std::unique_ptr<TurboModuleFactoryDelegate> createTurboModuleFactoryDelegate() {
            return std::make_unique<NativeRNCWorkletsTurboModuleFactoryDelegate>();
        }
    };
} // namespace rnoh
#endif