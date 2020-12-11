package com.example.toptechwebsites;

import android.app.Activity;
import android.support.design.widget.CollapsingToolbarLayout;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.webkit.WebResourceRequest;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.TextView;

import com.example.toptechwebsites.dummy.DummyContent;

/**
 * A fragment representing a single Item detail screen.
 * This fragment is either contained in a {@link ItemListActivity}
 * in two-pane mode (on tablets) or a {@link ItemDetailActivity}
 * on handsets.
 */
public class ItemDetailFragment extends Fragment {
    /**
     * The fragment argument representing the item ID that this fragment
     * represents.
     */
    public static final String ARG_ITEM_ID = "item_id";

    /**
     * The dummy content this fragment is presenting.
     */
    private DummyContent.DummyItem mItem;

    /**
     * Mandatory empty constructor for the fragment manager to instantiate the
     * fragment (e.g. upon screen orientation changes).
     */
    public ItemDetailFragment() {
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        if (getArguments().containsKey(ARG_ITEM_ID)) {
            // Load the dummy content specified by the fragment
            // arguments. In a real-world scenario, use a Loader
            // to load content from a content provider.
            mItem = DummyContent.ITEM_MAP.get(getArguments().getString(ARG_ITEM_ID));

            Activity activity = this.getActivity();
            CollapsingToolbarLayout appBarLayout = (CollapsingToolbarLayout) activity.findViewById(R.id.toolbar_layout);
            if (appBarLayout != null) {
                appBarLayout.setTitle(mItem.content);
            }
        }
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View rootView = inflater.inflate(R.layout.item_detail, container, false);
        //((WebView)rootView.findViewById(R.id.item_detail)).loadUrl(mItem.item_url);



        // Show the dummy content as text in a TextView.
        // Show the dummy content as text in a TextView.
        if (mItem.id.equals("1")) {
            ((WebView) rootView.findViewById(R.id.item_detail))
                    .loadUrl(mItem.item_url);
            WebView webView = (WebView)
                    rootView.findViewById(R.id.item_detail);
            webView.setWebViewClient(new WebViewClient(){
                @Override
                public boolean shouldOverrideUrlLoading(
                        WebView view, WebResourceRequest request) {
                    return super.shouldOverrideUrlLoading(
                            view, request);
                }
            });
            webView.getSettings().setJavaScriptEnabled(true);
            webView.loadUrl(mItem.item_url);
        }

        if (mItem.id.equals("2")) {
            ((WebView) rootView.findViewById(R.id.item_detail))
                    .loadUrl(mItem.item_url);
            WebView webView = (WebView)
                    rootView.findViewById(R.id.item_detail);
            webView.setWebViewClient(new WebViewClient(){
                @Override
                public boolean shouldOverrideUrlLoading(
                        WebView view, WebResourceRequest request) {
                    return super.shouldOverrideUrlLoading(
                            view, request);
                }
            });
            webView.getSettings().setJavaScriptEnabled(true);
            webView.loadUrl(mItem.item_url);
        }

        if (mItem.id.equals("3")) {
            ((WebView) rootView.findViewById(R.id.item_detail))
                    .loadUrl(mItem.item_url);
            WebView webView = (WebView)
                    rootView.findViewById(R.id.item_detail);
            webView.setWebViewClient(new WebViewClient(){
                @Override
                public boolean shouldOverrideUrlLoading(
                        WebView view, WebResourceRequest request) {
                    return super.shouldOverrideUrlLoading(
                            view, request);
                }
            });
            webView.getSettings().setJavaScriptEnabled(true);
            webView.loadUrl(mItem.item_url);
        }

        if (mItem.id.equals("4")) {
            ((WebView) rootView.findViewById(R.id.item_detail))
                    .loadUrl(mItem.item_url);
            WebView webView = (WebView)
                    rootView.findViewById(R.id.item_detail);
            webView.setWebViewClient(new WebViewClient(){
                @Override
                public boolean shouldOverrideUrlLoading(
                        WebView view, WebResourceRequest request) {
                    return super.shouldOverrideUrlLoading(
                            view, request);
                }
            });
            webView.getSettings().setJavaScriptEnabled(true);
            webView.loadUrl(mItem.item_url);
        }

        if (mItem.id.equals("5")) {
            ((WebView) rootView.findViewById(R.id.item_detail))
                    .loadUrl(mItem.item_url);
            WebView webView = (WebView)
                    rootView.findViewById(R.id.item_detail);
            webView.setWebViewClient(new WebViewClient(){
                @Override
                public boolean shouldOverrideUrlLoading(
                        WebView view, WebResourceRequest request) {
                    return super.shouldOverrideUrlLoading(
                            view, request);
                }
            });
            webView.getSettings().setJavaScriptEnabled(true);
            webView.loadUrl(mItem.item_url);
        }

        if (mItem.id.equals("6")) {
            ((WebView) rootView.findViewById(R.id.item_detail))
                    .loadUrl(mItem.item_url);
            WebView webView = (WebView)
                    rootView.findViewById(R.id.item_detail);
            webView.setWebViewClient(new WebViewClient(){
                @Override
                public boolean shouldOverrideUrlLoading(
                        WebView view, WebResourceRequest request) {
                    return super.shouldOverrideUrlLoading(
                            view, request);
                }
            });
            webView.getSettings().setJavaScriptEnabled(true);
            webView.loadUrl(mItem.item_url);
        }


/*
        if (mItem.id.equals("1")){
            ((WebView)rootView.findViewById(R.id.item_detail)).loadUrl(mItem.item_url);
        }
        if (mItem.id.equals("2")){
            ((WebView)rootView.findViewById(R.id.item2_detail)).loadUrl(mItem.item_url);
        }
        if (mItem.id.equals("3")){
            ((WebView)rootView.findViewById(R.id.item3_detail)).loadUrl(mItem.item_url);
        }
*/
        return rootView;
    }


}
