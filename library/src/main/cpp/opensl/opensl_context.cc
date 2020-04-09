/*
 * Copyright (C) 2020 Mobisoft. All rights reserved.
 * Copyright (C) 2020 Shubham Kamlapuri <shubhwicked@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

//
// Created by Shubham on 2020/4/21.
//

#include "opensl_context.h"

namespace mobisoft {

OpenSLContext* OpenSLContext::instance_ = new mobisoft::OpenSLContext();

void OpenSLContext::Init() {
    SLresult result = CreateEngine();
    if (SL_RESULT_SUCCESS == result) {
        // Realize the engine object
        result = RealizeObject(engine_object_);
        if (SL_RESULT_SUCCESS == result) {
            // Get the engine interface
            result = GetEngineInterface();
        }
    }
}

OpenSLContext::OpenSLContext() {
    inited_ = false;
}
OpenSLContext::~OpenSLContext() {
}

OpenSLContext* OpenSLContext::GetInstance() {
    if (!instance_->inited_) {
        instance_->Init();
        instance_->inited_ = true;
    }
    return instance_;
}

}  // namespace mobisoft
