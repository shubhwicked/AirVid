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
// Created by Shubham on 2020/4/16.
//

#ifndef MOBISOFT_MEDIA_ENCODE_ADAPTER_H
#define MOBISOFT_MEDIA_ENCODE_ADAPTER_H

#include <jni.h>
#include "video_encoder_adapter.h"
#include "handler.h"
#include "video_packet_queue.h"
#include "opengl.h"

namespace mobisoft {

typedef enum {
    FRAME_AVAILABLE
} MediaEncoderType;

class MediaEncodeAdapter : public VideoEncoderAdapter, public Handler {
 public:
    MediaEncodeAdapter(JavaVM* vm, jobject object);
    virtual ~MediaEncodeAdapter();

    virtual void CreateEncoder(EGLCore* core, int texture_id);

    virtual void DestroyEncoder();

    virtual void Encode(float speed = 1.0F);

    void DrainEncodeData();

 private:
    bool encoding_;
    bool sps_write_flag_;
    JavaVM* vm_;
    jobject object_;
    EGLCore* core_;
    MessageQueue* queue_;
    pthread_t encoder_thread_;
    EGLSurface encoder_surface_;
    ANativeWindow* encoder_window_;
    jbyteArray output_buffer_;
    int start_encode_time_;
    OpenGL* render_;

 private:
    static void* MessageQueueThread(void* args);
    virtual void HandleMessage(Message* msg);
    void EncodeLoop();
    void CreateMediaEncoder(JNIEnv* env);
    void DestroyMediaEncoder(JNIEnv* env);
};

}  // namespace mobisoft

#endif  // MOBISOFT_MEDIA_ENCODE_ADAPTER_H
