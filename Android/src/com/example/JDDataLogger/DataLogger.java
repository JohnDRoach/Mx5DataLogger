package com.example.JDDataLogger;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.os.Bundle;
import android.os.Parcelable;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import java.io.IOException;
import java.util.UUID;

public class DataLogger extends JDActivity implements ConnectionListener {
    private BluetoothSocket socket;
    private BluetoothAdapter adapter;
    private ConnectThread connectThread;

    /**
     * Called when the activity is first created.
     */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        adapter = BluetoothAdapter.getDefaultAdapter();

        if (adapter == null) {
            SetBluetoothButtonTo(false);
        }

        SetAllOtherButtonsTo(false);
    }

    public void bluetoothButtonClicked(View view) {
        Intent intent = new Intent(this, BluetoothSetup.class);
        startActivityForResult(intent, 120);
    }

    public void loggingButtonClicked(View view) {
        BrownToast("Logging Button Clicked");
    }

    public void highScoresButtonClicked(View view) {
        Intent intent = new Intent(this, HighScores.class);
        startActivity(intent);
    }

    public void settingsButtonClicked(View view) {
        BrownToast("Settings Button Clicked");
    }


    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if (requestCode == 120 && resultCode == RESULT_OK) {
            BluetoothDevice device = data.getParcelableExtra("SelectedBluetoothDevice");

            SetBluetoothButtonTo(false);
            BrownToast("Connecting to: " + device.getName());

            connectThread = new ConnectThread(adapter, device, this);
            connectThread.start();
        }
    }

    private void SetAllOtherButtonsTo(boolean value) {
        this.<Button>Get(R.id.LoggingButton).setEnabled(value);
        this.<Button>Get(R.id.HighScoresButton).setEnabled(value);
        this.<Button>Get(R.id.SettingsButton).setEnabled(value);
    }

    private void SetBluetoothButtonTo(boolean value) {
        this.<Button>Get(R.id.BluetoothButton).setEnabled(value);
    }

    @Override
    public void ConnectionSuccess(final BluetoothSocket connectedSocket) {
        socket = connectedSocket;
        ((MyApplication) this.getApplication()).socket = connectedSocket;

        this.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                BrownToast("Connection success!");
                SetAllOtherButtonsTo(true);
            }
        });
    }

    @Override
    public void ConnectionFailure(final String message) {
        this.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                BrownToast("Connection failed: " + message);
                SetBluetoothButtonTo(true);
            }
        });
    }

    @Override
    public void onDestroy()
    {
        super.onDestroy();
        if(socket != null) {
            try {
                BrownToast("Closing connection!");
                socket.close();
            } catch (IOException e) {
            }
        }
    }
}
