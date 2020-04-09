//
// Created by Shubham on 2020-02-01.
//

#ifndef MOBISOFT_FACE_STICKER_H
#define MOBISOFT_FACE_STICKER_H

#include "opengl.h"

namespace mobisoft {

class FaceSticker : public OpenGL {
 public:
    FaceSticker();
    ~FaceSticker();
    int OnDrawFrame(int texture_id);

 protected:
    virtual void RunOnDrawTasks();
 private:
    void CreateStickerTexture();
    void SetupLandMarks();

 private:
    GLuint sticker_texture_id_;
};

}

#endif  // MOBISOFT_FACE_STICKER_H
