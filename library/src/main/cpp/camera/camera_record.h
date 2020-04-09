

#ifndef MOBISOFT_CAMERA_RECORD_H
#define MOBISOFT_CAMERA_RECORD_H

#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <mobisoft.h>
#include "egl_core.h"
#include "handler.h"
#include "frame_buffer.h"
#include "video_encoder_adapter.h"
#include "video_consumer_thread.h"
#include "soft_encoder_adapter.h"
#include "image_process.h"
#include "face_detection.h"
#include "face_point.h"

namespace mobisoft {

enum RenderThreadMessage {
    MSG_RENDER_FRAME = 0,
    MSG_EGL_THREAD_CREATE,
    MSG_EGL_CREATE_PREVIEW_SURFACE,
    MSG_SWITCH_CAMERA_FACING,
    MSG_SET_FRAME,
    MSG_START_RECORDING,
    MSG_STOP_RECORDING,
    MSG_EGL_DESTROY_PREVIEW_SURFACE,
    MSG_EGL_THREAD_EXIT
};

class CameraRecord : public Handler, public FaceDetection {
 public:
    explicit CameraRecord(JNIEnv* env);
    virtual ~CameraRecord();

    void PrepareEGLContext(jobject object, jobject surface,
            int screen_width, int screen_height);

    void NotifyFrameAvailable();

    /**
     * 设置录制速度
     * @param speed 0.25f, 0.5f, 1.0f, 2.0f, 4.0f
     */
    void SetSpeed(float speed);

    void SetRenderType(int type);

    void SetFrame(int frame);

    void SwitchCameraFacing();

    void ResetRenderSize(int screen_width, int screen_height);

    virtual void DestroyEGLContext();

    void CreateWindowSurface(ANativeWindow *window);

    void DestroyWindowSurface();

    void StartEncoding(const char* path,
            int width,
            int height,
            int video_bit_rate,
            int frame_rate,
            bool use_hard_encode,
            int audio_sample_rate,
            int audio_channel,
            int audio_bit_rate);

    void StopEncoding();

    int AddFilter(const char* config_path);

    void UpdateFilter(const char* config_path, int start_time, int end_time, int action_id);

    void DeleteFilter(int action_id);

    int AddAction(const char* config_path);

    void UpdateActionTime(int start_time, int end_time, int action_id);

    void UpdateActionParam(int action_id, const char* effect_name, const char* param_name, float value);

    void DeleteAction(int action_id);

    virtual void FaceDetector(std::vector<FaceDetectionReport*>& face_detection);
 private:
    virtual bool Initialize();

    virtual void Destroy();

    void CreatePreviewSurface();

    void DestroyPreviewSurface();

    void SwitchCamera();

    void StartRecording();

    void StopRecording();

    void RenderFrame();

    void SetFrameType(int frame);

    void Draw();

    void ConfigCamera();

    void StartCameraPreview();

    void UpdateTexImage();

    void onSurfaceCreated();

    int OnDrawFrame(int texture_id, int width, int height);

    void onSurfaceDestroy();

    void GetTextureMatrix();

    void ReleaseCamera();

    static void *ThreadStartCallback(void *myself);

    void ProcessMessage();

    void FPS();

    void OnAddFilter(char* config_path, int action_id);

    void OnUpdateFilter(char* config_path, int action_id,
            int start_time, int end_time);

    void OnDeleteFilter(int action_id);

    void OnAddAction(char* config_path, int action_id);

    void OnUpdateActionTime(int start_time, int end_time, int action_id);

    void OnUpdateActionParam(EffectParam* param);

    void OnDeleteAction(int action_id);

    int GetCameraFacing();

    void GetFaceDetectionReports(std::vector<FaceDetectionReport*>& face_detection_reports);

    virtual void HandleMessage(Message* msg);
 private:
    ANativeWindow *window_;
    JavaVM *vm_;
    jobject obj_;
    int screen_width_;
    int screen_height_;
    int camera_width_;
    int camera_height_;
    bool camera_size_change_;

    GLfloat* vertex_coordinate_;
    GLfloat* texture_coordinate_;
    EGLCore *egl_core_;
    EGLSurface preview_surface_;
    FrameBuffer* frame_buffer_;
    OpenGL* render_screen_;
    MessageQueue* queue_;
    pthread_t thread_id_;
    GLuint oes_texture_id_;
    GLfloat* texture_matrix_;
    VideoEncoderAdapter* encoder_;
    bool encoding_;
    VideoConsumerThread* packet_thread_;
    float speed_;
    int frame_type_;
    int frame_count_;
    int64_t pre_fps_count_time_;
    float fps_;
    bool start_recording;
    int current_action_id_;
    ImageProcess* image_process_;
    int64_t render_time_;
    FacePoint* face_point_;
    int camera_facing_id_;
};

}  // namespace mobisoft

#endif  // MOBISOFT_CAMERA_RECORD_H