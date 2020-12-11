package com.example.guitarsolo;

import android.media.MediaPlayer;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.Button;

public class SoloActivity extends AppCompatActivity {
    Button button1;
    MediaPlayer mpSolo;
    int playing;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_solo);
        button1 = (Button)findViewById(R.id.button);
        button1.setOnClickListener(soloButton);
        mpSolo = new MediaPlayer();
        mpSolo = MediaPlayer.create(this, R.raw.guitarsolosong);
        playing = 0;
        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);


    }

    Button.OnClickListener soloButton = new Button.OnClickListener() {
        @Override
        public void onClick(View v) {
            switch(playing) {
                case 0:
                    mpSolo.start();
                    playing = 1;
                    button1.setText("Pause Guitar Solo");
                    break;
                case 1:
                    mpSolo.pause();
                    playing = 0;
                    button1.setText("Play Guitar Solo");
                    break;
            }
        }
    };

}
