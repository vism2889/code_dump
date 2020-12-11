package com.example.anthologyweddingphotography;

import android.content.Context;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.GridView;
import android.widget.ImageView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {


    Integer[] wedPics = {R.drawable.wedding_couple1,
            R.drawable.wedding_couple2,
            R.drawable.wedding_couple3,
            R.drawable.wedding_couple4,
            R.drawable.wedding_couple5,
            R.drawable.wedding_couple6,
            R.drawable.wedding_couple7,
            R.drawable.wedding_couple8,
            R.drawable.wedding_couple9,
            R.drawable.wedding_couple10};
    ImageView pic;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        GridView grid = (GridView)findViewById(R.id.gridView);
        final ImageView pic = (ImageView)findViewById(R.id.imgLarge);
        grid.setAdapter(new ImageAdapter(this));
        grid.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Toast.makeText(getBaseContext(), "Anthology Wedding Photography: Image " + (position + 1), Toast.LENGTH_SHORT).show();
                //pic.setVisibility(View.VISIBLE);
                pic.setImageResource(wedPics[position]);
                //wait(3000);
                //pic.setVisibility(View.INVISIBLE);
            }
        });

        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);


    }

    public class ImageAdapter extends BaseAdapter {
        private Context context;
        public ImageAdapter(Context c){
            context = c;
        }

        @Override
        public int getCount(){
            return wedPics.length;
        }
        @Override
        public Object getItem(int position){
            return null;
        }
        @Override
        public long getItemId(int position){
            return 0;
        }
        @Override
        public View getView(int position, View convertView, ViewGroup parent){
            pic = new ImageView(context);
            pic.setImageResource(wedPics[position]);
            pic.setScaleType(ImageView.ScaleType.FIT_XY);
            pic.setLayoutParams(new GridView.LayoutParams(100,100));
            return pic;
        }
    }

}
