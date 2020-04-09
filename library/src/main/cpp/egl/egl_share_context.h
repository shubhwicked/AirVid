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
 */

//
// Created by Shubham on 2020/4/2.
//

#ifndef MOBISOFT_EGL_SHARE_CONTEXT_H
#define MOBISOFT_EGL_SHARE_CONTEXT_H

#include <EGL/egl.h>

namespace mobisoft {

class EGLShareContext {
 public:
    static EGLContext getSharedContext() {
        if (instance_->shared_display_ == EGL_NO_DISPLAY) {
            instance_->Init();
        }
        return instance_->shared_context_;
    }

 private:
    EGLShareContext();
    void Init();

 private:
    static EGLShareContext* instance_;
    EGLContext shared_context_;
    EGLDisplay shared_display_;
};

}  // namespace mobisoft

#endif  // MOBISOFT_EGL_SHARE_CONTEXT_H
