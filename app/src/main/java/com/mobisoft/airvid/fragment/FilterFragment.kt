

package com.mobisoft.airvid.fragment

import android.graphics.Rect
import android.os.Bundle
import android.util.TypedValue
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.mobisoft.airvid.R
import com.mobisoft.airvid.adapter.FilterAdapter
import com.mobisoft.airvid.entity.Filter

class FilterFragment : Fragment() {

  private var mCallback: Callback ?= null

  override fun onCreateView(inflater: LayoutInflater, container: ViewGroup?, savedInstanceState: Bundle?): View? {
    return inflater.inflate(R.layout.fragment_filter, container, false)
  }

  override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
    val recyclerView = view.findViewById<RecyclerView>(R.id.recycler_view)
    recyclerView.layoutManager = LinearLayoutManager(activity, LinearLayoutManager.HORIZONTAL, false)
    recyclerView.adapter = FilterAdapter(view.context) {
      mCallback?.onFilterSelect(it)
    }
    recyclerView.addItemDecoration(object: RecyclerView.ItemDecoration() {
      override fun getItemOffsets(outRect: Rect, view: View, parent: RecyclerView, state: RecyclerView.State) {
        outRect.left = TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, 5f, resources.displayMetrics).toInt()
        outRect.right = TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, 5f, resources.displayMetrics).toInt()
      }
    })
  }

  fun setCallback(callback: Callback) {
    mCallback = callback
  }

  interface Callback {
    fun onFilterSelect(filter: Filter)
  }
}