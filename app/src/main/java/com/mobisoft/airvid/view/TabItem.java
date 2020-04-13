package com.mobisoft.airvid.view;

import android.content.Context;
import android.content.res.TypedArray;
import android.graphics.drawable.Drawable;
import android.util.AttributeSet;
import android.view.View;
import com.mobisoft.airvid.R;

public class TabItem extends View {
  public final CharSequence text;
  public final Drawable icon;
  public final int customLayout;

  public TabItem(Context context) {
    this(context, null);
  }

  public TabItem(Context context, AttributeSet attrs) {
    super(context, attrs);

    final TypedArray a = context.obtainStyledAttributes(attrs, R.styleable.MobisoftTabItem, 0, 0);
    text = a.getText(R.styleable.MobisoftTabItem_android_text);
    icon = a.getDrawable(R.styleable.MobisoftTabItem_android_icon);
    customLayout = a.getResourceId(R.styleable.MobisoftTabItem_android_layout, 0);
    a.recycle();
  }
}
