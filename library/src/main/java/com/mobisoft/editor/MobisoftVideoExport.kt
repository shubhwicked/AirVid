package com.mobisoft.editor

import com.mobisoft.listener.OnExportListener

interface MobisoftVideoExport {


  fun export(
    path: String,
    width: Int,
    height: Int,
    frameRate: Int,
    videoBitRate: Int,
    sampleRate: Int,
    channelCount: Int,
    audioBitRate: Int,
    l: OnExportListener
  ): Int


  fun cancel()


  fun release()
}