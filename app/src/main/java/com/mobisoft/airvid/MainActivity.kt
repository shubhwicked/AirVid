package com.mobisoft.airvid

import android.Manifest
import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.FrameLayout
import androidx.fragment.app.commit
import com.mobisoft.airvid.entity.MediaItem
import com.mobisoft.airvid.fragment.MediaFragment
import com.github.florent37.runtimepermission.RuntimePermission
import com.google.android.material.bottomsheet.BottomSheetBehavior

class MainActivity : AppCompatActivity() {
    private val mMedias = mutableListOf<MediaItem>()
    private lateinit var mInsideBottomSheet: FrameLayout

    companion object {
        init {
            System.loadLibrary("mobisoft")
        }
        private const val MEDIA_TAG = "media_tag"
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        requestPermission()
        mInsideBottomSheet = findViewById(R.id.frame_container)
        findViewById<Button>(R.id.record)
            .setOnClickListener {
                val intent = Intent(this, RecordActivity::class.java)
                startActivity(intent)
            }

        findViewById<Button>(R.id.editor)
            .setOnClickListener {
              showMedia()
            }

        findViewById<Button>(R.id.music)
            .setOnClickListener {
                val intent = Intent(this, MusicActivity::class.java)
                startActivity(intent)
            }
    }

    private fun requestPermission() {
        RuntimePermission.askPermission(this, Manifest.permission.CAMERA,
            Manifest.permission.RECORD_AUDIO,
            Manifest.permission.WRITE_EXTERNAL_STORAGE,
            Manifest.permission.READ_EXTERNAL_STORAGE)
            .onAccepted {

            }
            .onDenied {

            }
    }
    private fun showMedia() {
        var mediaFragment = supportFragmentManager.findFragmentByTag(MEDIA_TAG)
        if (mediaFragment == null) {
            mediaFragment = MediaFragment()
            supportFragmentManager.commit {
                replace(R.id.frame_container, mediaFragment, MEDIA_TAG)
            }
        }
        val behavior = BottomSheetBehavior.from(mInsideBottomSheet)
        if (behavior.state != BottomSheetBehavior.STATE_EXPANDED) {
            behavior.state = BottomSheetBehavior.STATE_EXPANDED
        } else {
            behavior.state = BottomSheetBehavior.STATE_HIDDEN
        }
    }

    fun onMediaResult(medias: MutableList<MediaItem>) {
        val behavior = BottomSheetBehavior.from(mInsideBottomSheet)
        if (behavior.state != BottomSheetBehavior.STATE_EXPANDED) {
            behavior.state = BottomSheetBehavior.STATE_EXPANDED
        } else {
            behavior.state = BottomSheetBehavior.STATE_HIDDEN
        }
        if(mMedias.isNotEmpty()){
            mMedias.removeAll(mMedias)
        }
        medias.forEach {

            mMedias.add(it)
        }
        if (mMedias.isNotEmpty()) {
            val intent = Intent(this, EditorActivity::class.java)
            intent.putExtra("medias", mMedias.toTypedArray())
            startActivity(intent)
        }
    }

    override fun onDestroy() {
        super.onDestroy()
        if (mMedias.isNotEmpty()) {
            mMedias.removeAll(mMedias)
        }
    }

    fun closeBottomSheet() {
        val behavior = BottomSheetBehavior.from(mInsideBottomSheet)
        behavior.state = BottomSheetBehavior.STATE_HIDDEN
    }
    override fun onBackPressed() {
        val behavior = BottomSheetBehavior.from(mInsideBottomSheet)
        if (behavior.state == BottomSheetBehavior.STATE_EXPANDED) {
            closeBottomSheet()
        } else {
            super.onBackPressed()
        }
    }
}
