package com.example.ringtones;

import android.media.MediaPlayer;
import android.os.Bundle;
import android.provider.MediaStore;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.RadioButton;

public class TonePicker extends AppCompatActivity {
    RadioButton tone1, tone2, tone3;
    MediaPlayer ring1, ring2, ring3;
    int playing;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_tone_picker);

        tone1 = (RadioButton)findViewById(R.id.radioButton);
        tone2 = (RadioButton)findViewById(R.id.radioButton2);
        tone3 = (RadioButton)findViewById(R.id.radioButton3);
        tone1.setOnClickListener(bTone1);
        tone2.setOnClickListener(bTone2);
        tone3.setOnClickListener(bTone3);

        ring1 = new MediaPlayer();
        ring1 = MediaPlayer.create(this, R.raw.bomdropringtone);
        ring2 = new MediaPlayer();
        ring2 = MediaPlayer.create(this, R.raw.bengalisongringtone);
        ring3 = new MediaPlayer();
        ring3 = MediaPlayer.create(this, R.raw.jaiwaetfordringtone);

        playing = 0;

        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);


    }

    RadioButton.OnClickListener bTone1 = new RadioButton.OnClickListener(){
        @Override
        public void onClick(View v){
            switch(playing) {
                case 0:
                    ring1.start();
                    playing = 1;
                    tone1.setText("Pause Bom Drop Tone");
                    tone2.setVisibility(View.INVISIBLE);
                    tone3.setVisibility(View.INVISIBLE);
                    break;
                case 1:
                    ring1.pause();
                    playing = 0;
                    tone1.setText("Bom Drop Tone");
                    tone2.setVisibility(View.VISIBLE);
                    tone3.setVisibility(View.VISIBLE);
                    break;
            }
        }
    };

    RadioButton.OnClickListener bTone2 = new RadioButton.OnClickListener(){
        @Override
        public void onClick(View v){
            switch(playing) {
                case 0:
                    ring2.start();
                    playing = 1;
                    tone2.setText("Pause Bengali Song Tone");
                    tone1.setVisibility(View.INVISIBLE);
                    tone3.setVisibility(View.INVISIBLE);
                    break;
                case 1:
                    ring2.pause();
                    playing = 0;
                    tone2.setText("Bengali Song Tone");
                    tone1.setVisibility(View.VISIBLE);
                    tone3.setVisibility(View.VISIBLE);
                    break;
            }
        }
    };

    RadioButton.OnClickListener bTone3 = new RadioButton.OnClickListener(){
        @Override
        public void onClick(View v){
            switch(playing) {
                case 0:
                    ring3.start();
                    playing = 1;
                    tone3.setText("Pause Jaiwaet Tone");
                    tone1.setVisibility(View.INVISIBLE);
                    tone2.setVisibility(View.INVISIBLE);
                    break;
                case 1:
                    ring3.pause();
                    playing = 0;
                    tone3.setText("Jaiwaet Tone");
                    tone1.setVisibility(View.VISIBLE);
                    tone2.setVisibility(View.VISIBLE);
                    break;
            }
        }
    };

}
