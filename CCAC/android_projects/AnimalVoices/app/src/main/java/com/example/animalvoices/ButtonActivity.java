package com.example.animalvoices;

import android.media.MediaPlayer;
import android.os.Bundle;
import android.app.Activity;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;

public class ButtonActivity extends AppCompatActivity {
    Button button1,button2;
    MediaPlayer mpCow, mpPig;
    int playing;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_button);
        button1 = (Button)findViewById(R.id.button);
        button2 = (Button)findViewById(R.id.button2);
        button1.setOnClickListener(bCow);
        button2.setOnClickListener(bPig);
        mpCow = new MediaPlayer();
        mpCow = MediaPlayer.create(this, R.raw.cows);
        mpPig = new MediaPlayer();
        mpPig = MediaPlayer.create(this, R.raw.pigs);
        playing = 0;


    }
    Button.OnClickListener bCow = new Button.OnClickListener(){
        @Override
        public void onClick(View v){
            switch(playing){
                case 0:
                    mpCow.start();
                    playing = 1;
                    button1.setText("Pause Cow Voices");
                    button2.setVisibility(View.INVISIBLE);
                    break;
                case 1:
                    mpCow.pause();
                    playing = 0;
                    button1.setText("Listen to the Cows");
                    button2.setVisibility(View.VISIBLE);
                    break;
            }

        }
    };
    Button.OnClickListener bPig = new Button.OnClickListener(){
        @Override
        public void onClick(View v){
            switch(playing){
                case 0:
                    mpPig.start();
                    playing = 1;
                    button2.setText("Pause Pig Voices");
                    button1.setVisibility(View.INVISIBLE);
                    break;
                case 1:
                    mpPig.pause();
                    playing = 0;
                    button2.setText("Listen to the Pigs");
                    button1.setVisibility(View.VISIBLE);
                    break;
            }

        }
    };

}
