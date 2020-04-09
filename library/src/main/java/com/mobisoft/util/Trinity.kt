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

package com.mobisoft.util

import android.os.Handler
import android.os.Looper

/**
 * Created by Shubham on 2020-07-31
 */
object Trinity {

  private val mHandler = Handler(Looper.getMainLooper())

  fun <T> callback(body: () -> T) {
    if (Looper.myLooper() == Looper.getMainLooper()) {
      body()
    } else {
      mHandler.post {
        body()
      }
    }
  }
}