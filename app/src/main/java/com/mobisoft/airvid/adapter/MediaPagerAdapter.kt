package com.mobisoft.airvid.adapter

import androidx.fragment.app.Fragment
import androidx.fragment.app.FragmentManager
import androidx.fragment.app.FragmentPagerAdapter
import com.mobisoft.airvid.fragment.PictureFragment
import com.mobisoft.airvid.fragment.VideoFragment

class MediaPagerAdapter(fm: FragmentManager) : FragmentPagerAdapter(fm, FragmentPagerAdapter.BEHAVIOR_RESUME_ONLY_CURRENT_FRAGMENT) {

  private val mItems = mutableListOf<Fragment>()

  init {
    mItems.add(VideoFragment())
    mItems.add(PictureFragment())
  }

  override fun getItem(position: Int): Fragment {
    return mItems[position]
  }

  override fun getCount(): Int {
    return 2
  }

  override fun getPageTitle(position: Int): CharSequence? {
    return if (position == 0) {
      "Video"
    } else {
      "Photo"
    }
  }
}