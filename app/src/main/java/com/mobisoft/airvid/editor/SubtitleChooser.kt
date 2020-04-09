
package com.mobisoft.airvid.editor

import android.annotation.SuppressLint
import android.content.Context
import android.util.AttributeSet
import android.util.TypedValue
import android.view.LayoutInflater
import android.view.View
import android.widget.FrameLayout
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.mobisoft.airvid.R
import com.mobisoft.airvid.adapter.CategoryAdapter
import com.mobisoft.airvid.adapter.SubtitleAdapter
import com.mobisoft.airvid.entity.ResourceForm
import com.mobisoft.airvid.entity.SubtitleInfo
import com.mobisoft.airvid.view.PasteUISimpleImpl
import com.mobisoft.airvid.view.PasteUITextImpl
import com.mobisoft.airvid.view.SpacesItemDecoration

class SubtitleChooser : Chooser {

  private var mSubtitles: MutableList<ResourceForm> ?= null
  private var mOnSubtitleItemClickListener: OnSubtitleItemClickListener ?= null

  constructor(context: Context) : super(context)

  constructor(context: Context, attrs: AttributeSet?) : super(context, attrs)

  constructor(context: Context, attrs: AttributeSet?, defStyleAttr: Int) : super(context, attrs, defStyleAttr)

  override fun init() {
    mSubtitles = mutableListOf()
    val view: View = LayoutInflater.from(context).inflate(R.layout.subtitle_view, this)
//    initListener()
    initResourceLocal()
    val recyclerView: RecyclerView = view.findViewById(R.id.effect_list)
    recyclerView.layoutManager = LinearLayoutManager(context, LinearLayoutManager.HORIZONTAL, false)
    recyclerView.addItemDecoration(SpacesItemDecoration(TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, 2f, resources.displayMetrics).toInt(), 1))
    val subtitleAdapter = SubtitleAdapter(context) {
      mOnSubtitleItemClickListener?.onSubtitleItemClick(it)
    }
//    subtitleAdapter.setOnItemClickListener(mOnItemClickListener)
    recyclerView.adapter = subtitleAdapter
    subtitleAdapter.showFontData()
    val categoryRecyclerView = view.findViewById<RecyclerView>(R.id.category_list)
    categoryRecyclerView.layoutManager = LinearLayoutManager(context, LinearLayoutManager.HORIZONTAL, false)
    val adapter = CategoryAdapter(context) {

    }
    adapter.addShowFontCategory()
    categoryRecyclerView.adapter = adapter
    mSubtitles?.let {
      adapter.setData(it)
    }
  }

  private fun initResourceLocal() {
    val form = ResourceForm()
    form.isMore = true
    mSubtitles?.add(form)
  }

  override fun isPlayerNeedZoom(): Boolean {
    return true

  }

  @SuppressLint("WrongViewCast")
  override fun getThumbContainer(): FrameLayout? {
    return findViewById(R.id.fl_thumblinebar)
  }

  override fun isHostPaste(paste: PasteUISimpleImpl): Boolean {
    return paste is PasteUITextImpl
  }

  fun setOnSubtitleItemClickListener(l: OnSubtitleItemClickListener) {
    mOnSubtitleItemClickListener = l
  }

  interface OnSubtitleItemClickListener {
    fun onSubtitleItemClick(info: SubtitleInfo)
  }
}