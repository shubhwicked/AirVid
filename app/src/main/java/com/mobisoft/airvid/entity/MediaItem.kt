package com.mobisoft.airvid.entity

import java.io.Serializable

class MediaItem(
    val path: String,
    val type: String,
    val width: Int,
    val height: Int
) : Serializable {
  var duration: Int = 0
}