package com.mobisoft.airvid.editor

import android.content.Context
import android.util.AttributeSet

/**
 * Created by Shubham on 2020-07-24
 */
class MusicChooser : Chooser {

  constructor(context: Context) : super(context)

  constructor(context: Context, attrs: AttributeSet?) : super(context, attrs)

  constructor(context: Context, attrs: AttributeSet?, defStyleAttr: Int) : super(context, attrs, defStyleAttr)

  override fun init() {
  }

  override fun isPlayerNeedZoom(): Boolean {
    return false
  }
}