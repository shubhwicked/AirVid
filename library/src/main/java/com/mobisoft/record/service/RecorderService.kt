
package com.mobisoft.record.service

import com.mobisoft.record.exception.AudioConfigurationException
import com.mobisoft.record.exception.StartRecordingException

interface RecorderService {

  /**
   * Get the buffer size of the background processing data part
   */
  val audioBufferSize: Int

  val sampleRate: Int

  /**
   * Get the current pitch when singing aloud to render volume animation
   */
  val recordVolume: Int

  val isPaused: Boolean

  /**
   * Initialize the hardware part of the recorder
   */
  @Throws(AudioConfigurationException::class)
  fun init(speed: Float)

  /**
   * Initialize our background processing data part
   */
  fun initAudioRecorderProcessor(speed: Float): Boolean

  /**
   * Destroy our background data processing part
   */
  fun destroyAudioRecorderProcessor()

  /**
   * start recording
   */
  @Throws(StartRecordingException::class)
  fun start()

  /**
   * End recording
   */
  fun stop()

  fun enableUnAccom()

  fun pause()

  fun continueRecord()

}
