package com.mobisoft.core

import android.content.Context
import com.mobisoft.editor.MobisoftVideoEditor
import com.mobisoft.editor.MobisoftVideoExport
import com.mobisoft.editor.VideoEditor
import com.mobisoft.editor.VideoExport

object MobisoftCore {

  /**
   * 创建视频编辑实例
   * @param context Android上下文
   * @return 返回创建的视频编辑实例
   */
  fun createEditor(context: Context): MobisoftVideoEditor {
    return VideoEditor(context)
  }

  fun createExport(context: Context): MobisoftVideoExport {
    return VideoExport(context)
  }
}