//
// Created by Shubham on 2020-02-07.
//

#ifndef MOBISOFT_FACE_MARKUP_RENDER_H
#define MOBISOFT_FACE_MARKUP_RENDER_H

#if __ANDROID__
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#elif __APPLE__
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#endif

#include "face_detection.h"
#include "frame_buffer.h"

namespace mobisoft {

class FaceMarkupRender {
 public:
    FaceMarkupRender();
    ~FaceMarkupRender();
    int OnDrawFrame(int origin_texture_id,
            int prop_texture_id,
            int source_width,
            int source_height,
            int blend_mode,
            float intensity,
            float* texture_coordinate,
            FaceDetectionReport* face_detection);

 private:
    void CreateFrameBuffer(int width, int height);
    void DeleteFrameBuffer();
    GLuint CreateProgram(const char* vertex, const char* fragment);
    void CompileShader(const char* shader_string, GLuint shader);
    int Link(GLuint program);
    void InitCoordinates();

 private:
    GLuint texture_id_;
    GLuint frame_buffer_id_;
    GLuint program_;
    GLuint prop_program_;
    GLfloat* default_vertex_coordinates_;
    GLfloat* default_texture_coordinates_;
    int source_width_;
    int source_height_;
    FrameBuffer* frame_buffer_;
};

}

#endif  // MOBISOFT_FACE_MARKUP_RENDER_H
