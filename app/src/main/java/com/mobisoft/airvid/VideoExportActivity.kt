package com.mobisoft.airvid

import android.os.Bundle
import android.view.View
import android.widget.Toast
import android.widget.VideoView
import androidx.appcompat.app.AppCompatActivity
import androidx.constraintlayout.widget.ConstraintLayout
import com.timqi.sectorprogressview.ColorfulRingProgressView
import com.mobisoft.core.MobisoftCore
import com.mobisoft.listener.OnExportListener

/**
 * Created by Shubham on 2020-07-30
 */
class VideoExportActivity : AppCompatActivity(), OnExportListener {

  private lateinit var mProgressBar: ColorfulRingProgressView
  private lateinit var mVideoView: VideoView

  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    setContentView(R.layout.activity_video_export)
    mProgressBar = findViewById(R.id.progress_view)
    mVideoView = findViewById(R.id.video_view)
    mVideoView.setOnPreparedListener {
      it.isLooping = true
    }

    val videoWidth = 544
    val videoHeight = 960
    val width = resources.displayMetrics.widthPixels
    val params = mVideoView.layoutParams as ConstraintLayout.LayoutParams
    params.width = width
    params.height = ((width * (videoHeight * 1.0f / videoWidth)).toInt())
    mVideoView.layoutParams = params
    val export = MobisoftCore.createExport(this)
    export.export("/sdcard/export.mp4", videoWidth, videoHeight, 25, 3000, 44100, 1, 128, this)
  }

  override fun onExportProgress(progress: Float) {
    println("progress: $progress")
    mProgressBar.percent = progress * 100
  }

  override fun onExportFailed(error: Int) {
    Toast.makeText(this,"Error ="+error,Toast.LENGTH_SHORT).show();
    supportFinishAfterTransition();
  }

  override fun onExportCanceled() {
    supportFinishAfterTransition();
  }

  override fun onExportComplete() {
    mProgressBar.visibility = View.GONE
    mVideoView.setVideoPath("/sdcard/export.mp4")
    mVideoView.start()
  }
}