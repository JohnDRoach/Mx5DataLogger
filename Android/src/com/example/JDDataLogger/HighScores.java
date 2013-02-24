package com.example.JDDataLogger;

import android.app.Activity;
import android.bluetooth.BluetoothSocket;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.nio.CharBuffer;

/**
 * Created with IntelliJ IDEA.
 * User: john
 * Date: 2/23/13
 * Time: 10:58 PM
 * To change this template use File | Settings | File Templates.
 */
public class HighScores extends JDActivity {
    BluetoothSocket socket;
    TextView tempView;
    /**
     * Called when the activity is first created.
     */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.highscores);
        socket = ((MyApplication) this.getApplication()).socket;
        tempView = Get(R.id.HighScoresTempView);
    }

    public void downloadClick(View view) {
        if(socket != null) {
            try {
                socket.getOutputStream().write(new byte[] {0x01, (byte)'H', (byte)'S', (byte)'L' });

                InputStream reader = socket.getInputStream();

                StringBuffer stringBuffer = new StringBuffer();

                byte[] ack = new byte[3];
                reader.read(ack, 0, 3);

                Read6LinesAndAppend(reader, stringBuffer);

                tempView.clearComposingText();
                tempView.setText(stringBuffer.toString());

            } catch (IOException e) {
                BrownToast("Error while writing/reading: " + e.getMessage());
            }
        }
    }

    private void Read6LinesAndAppend(InputStream reader, StringBuffer stringBuffer) throws IOException {
        int lineCount = 0;

        while(lineCount < 6) {
            char readChar = (char)reader.read();
            stringBuffer.append(readChar);

            if(readChar == '\n') {
                lineCount++;
            }
        }
    }

    public void backupClick(View view) {
        BrownToast("Feature not implemented. Yet!");
    }
}
