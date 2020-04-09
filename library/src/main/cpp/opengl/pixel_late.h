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
// Created by Shubham on 2020-05-26.
//

#ifndef MOBISOFT_PIXEL_LATE_H
#define MOBISOFT_PIXEL_LATE_H

#include "opengl.h"
#include "frame_buffer.h"

namespace mobisoft {

class PixelLate : public FrameBuffer {

public:
    PixelLate(int width, int height);
    ~PixelLate();
    GLuint OnDrawFrame(int textureId);

protected:
    virtual void RunOnDrawTasks();
    virtual void OnDrawArrays();

private:
    int width_;
    int height_;

};

}

#endif //MOBISOFT_PIXEL_LATE_H
