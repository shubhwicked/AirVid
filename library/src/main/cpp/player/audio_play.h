//
//  audio_play.h
//  player
//
//  Created by Shubham on 2020/11/20.
//  Copyright © 2020 com.mobisoft.player. All rights reserved.
//

#ifndef audio_play_h
#define audio_play_h

#include "play_types.h"

AudioPlayContext* audio_engine_create();
void audio_player_create(int rate, int channel, AVPlayContext *context);

#endif  // audio_play_h
