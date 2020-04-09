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

#ifndef MOBISOFT_EGL_CORE_H
#define MOBISOFT_EGL_CORE_H

#include <android/native_window.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <KHR/khrplatform.h>

typedef EGLBoolean (EGLAPIENTRYP PFNEGLPRESENTATIONTIMEANDROIDPROC)(EGLDisplay display, EGLSurface surface, khronos_stime_nanoseconds_t time);

namespace mobisoft {

class EGLCore {
 public:
    EGLCore();
    virtual ~EGLCore();
    bool Init();
    bool Init(EGLContext sharedContext);
    bool InitWithSharedContext();
    EGLSurface CreateWindowSurface(ANativeWindow *_window);
    EGLSurface CreateOffscreenSurface(int width, int height);
    bool MakeCurrent(EGLSurface eglSurface);
    void DoneCurrent();
    bool SwapBuffers(EGLSurface eglSurface);
    int QuerySurface(EGLSurface surface, int what);
    int SetPresentationTime(EGLSurface surface, khronos_stime_nanoseconds_t nsecs);
    void ReleaseSurface(EGLSurface eglSurface);
    void Release();
    EGLContext GetContext();
    EGLDisplay GetDisplay();
    EGLConfig GetConfig();

 private:
    EGLDisplay display_;
    EGLConfig config_;
    EGLContext context_;

    PFNEGLPRESENTATIONTIMEANDROIDPROC pfneglPresentationTimeANDROID;
};

}  // namespace mobisoft

#endif  // MOBISOFT_EGL_CORE_H
