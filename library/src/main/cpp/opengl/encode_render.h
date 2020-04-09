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
// Created by Shubham on 2020/4/26.
//

#ifndef MOBISOFT_ENCODE_RENDER_H
#define MOBISOFT_ENCODE_RENDER_H

#include "opengl.h"

namespace mobisoft {

class EncodeRender : public OpenGL {
 public:
    EncodeRender();
    virtual ~EncodeRender();

    void CopyYUV420Image(GLuint texture, uint8_t *buffer, int width, int height);
    void Destroy();

 protected:
    virtual void RunOnDrawTasks();

 private:
    void ConvertYUV420(int texture_id, int width, int height, void *buffer);

 private:
    int width_;
    int height_;
};

}  // namespace mobisoft

#endif  // MOBISOFT_ENCODE_RENDER_H
