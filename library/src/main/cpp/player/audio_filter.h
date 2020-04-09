//
//  audio_filter.h
//  player
//
//  Created by Shubham on 2020/11/20.
//  Copyright © 2020 com.mobisoft.player. All rights reserved.
//

#ifndef audio_filter_h
#define audio_filter_h

#include "play_types.h"

AudioFilterContext* audio_filter_create();
void audio_filter_release(AudioFilterContext* audio_filter_context);
void audio_filter_change_speed(AVPlayContext* context, float speed);
#endif  // audio_filter_h
