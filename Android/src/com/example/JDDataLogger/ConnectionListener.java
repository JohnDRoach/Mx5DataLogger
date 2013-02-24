package com.example.JDDataLogger;

import android.bluetooth.BluetoothSocket;

/**
 * Created with IntelliJ IDEA.
 * User: john
 * Date: 2/23/13
 * Time: 9:15 PM
 * To change this template use File | Settings | File Templates.
 */
public interface ConnectionListener {
    void ConnectionSuccess(final BluetoothSocket socket);
    void ConnectionFailure(final String message);
}
