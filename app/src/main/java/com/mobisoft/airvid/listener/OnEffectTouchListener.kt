package com.mobisoft.airvid.listener

import com.mobisoft.airvid.entity.Effect

interface OnEffectTouchListener {

  fun onEffectTouchEvent(event: Int, effect: Effect)
}