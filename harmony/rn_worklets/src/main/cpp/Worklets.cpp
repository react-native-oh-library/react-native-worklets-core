/*
 * MIT License
 *
 * Copyright (C) Huawei Technologies Co.,Ltd. 2024. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "Worklets.h"
#include "RNOH/ArkTSTurboModule.h"
#include "WKTJsiWorkletApi.h"

using namespace rnoh;
using namespace facebook;

namespace rnoh {
    jsi::Value install(facebook::jsi::Runtime &rt, react::TurboModule &turboModule, const facebook::jsi::Value *args,
                       size_t count) 
    {
        DLOG(INFO) << "wswsws WorkletsTurboModule.cpp install";
        auto self = static_cast<Worklets *>(&turboModule);
        self->install(rt);
        return true;
    }

    Worklets::Worklets(const ArkTSTurboModule::Context ctx, const std::string name)
        : ArkTSTurboModule(ctx, name) 
    {
        methodMap_ = {{"install", {0, rnoh::install}}};
    }

    void Worklets::install(facebook::jsi::Runtime &rt) 
    {
        auto jsInvoker = this->jsInvoker_;
        RNWorklet::JsiWorkletContext::getDefaultInstance()->initialize(
            "default", &rt, [=](std::function<void()> &&f) { jsInvoker->invokeAsync(std::move(f)); });

        RNWorklet::JsiWorkletApi::installApi(rt);
    }
} // namespace rnoh