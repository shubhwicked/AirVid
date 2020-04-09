package com.mobisoft.airvid.editor

/**
 * Created by Shubham on 2020-07-27
 */
interface PlayerListener {
  fun getCurrentDuration(): Long

  fun getDuration(): Long

  fun updateDuration(duration: Long)
}