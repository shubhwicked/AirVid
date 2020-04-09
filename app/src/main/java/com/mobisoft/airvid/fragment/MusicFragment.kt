package com.mobisoft.airvid.fragment

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.mobisoft.airvid.EditorActivity
import com.mobisoft.airvid.R
import com.mobisoft.airvid.RecordActivity
import com.mobisoft.airvid.adapter.MusicAdapter

class MusicFragment : Fragment() {

  companion object {
    fun newInstance(): MusicFragment {
      return MusicFragment()
    }
  }

  override fun onCreateView(inflater: LayoutInflater, container: ViewGroup?, savedInstanceState: Bundle?): View? {
    return inflater.inflate(R.layout.fragment_music, container, false)
  }

  override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
    super.onViewCreated(view, savedInstanceState)
    val recyclerView = view.findViewById<RecyclerView>(R.id.music_recycler)
    recyclerView.adapter = MusicAdapter(requireActivity()) {
      if (activity is RecordActivity) {
        (activity as RecordActivity).setMusic(it)
      } else if (activity is EditorActivity) {
        (activity as EditorActivity).setMusic(it)
      }

    }
    recyclerView.layoutManager = LinearLayoutManager(requireActivity(), RecyclerView.VERTICAL, false)

    view.findViewById<View>(R.id.close)
      .setOnClickListener {
        if (activity is RecordActivity) {
          (activity as RecordActivity).closeBottomSheet()
        } else if (activity is EditorActivity) {
          (activity as EditorActivity).closeBottomSheet()
        }
      }
  }
}