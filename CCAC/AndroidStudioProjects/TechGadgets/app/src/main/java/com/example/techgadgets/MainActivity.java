package com.example.techgadgets;

import android.app.ListActivity;
import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class MainActivity extends ListActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        String[] gadgets = {"Graphics Processing Unit", "Raspberry Pi", "Modular Synthesizer", "3D Printer", "Virtual Reality Headset"};
        setListAdapter(new ArrayAdapter<String>(this, R.layout.activity_main, R.id.travel, gadgets));

    }

    protected void onListItemClick(ListView l, View v, int position, long id){
        switch(position){
            case 0:
                startActivity(new Intent(MainActivity.this, GraphicsCard.class));
                break;
            case 1:
                startActivity(new Intent(MainActivity.this, RaspberryPi.class));
                break;
            case 2:
                startActivity(new Intent(MainActivity.this, ModularSynth.class));
                break;
            case 3:
                startActivity(new Intent(MainActivity.this, ThreeDPrinter.class));
                break;
            case 4:
                startActivity(new Intent(MainActivity.this, VRHeadset.class));
                break;
        }
    }
}
