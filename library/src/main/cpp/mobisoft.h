
#ifndef MOBISOFT_MOBISOFT_H
#define MOBISOFT_MOBISOFT_H

#include <stdint.h>

typedef struct {
    char* file_name;
    int64_t start_time;
    int64_t end_time;
} MediaClip;

typedef struct {
    int action_id;
    char* effect_name;
    char* param_name;
    float value;
} EffectParam;

typedef enum {
    kEffect             = 100,
    kEffectUpdate,
    kEffectParamUpdate,
    kEffectDelete,
    kMusic,
    kMusicUpdate,
    kMusicDelete,
    kFilter,
    kFilterUpdate,
    kFilterDelete,
} EffectMessage;

#endif  // MOBISOFT_MOBISOFT_H
