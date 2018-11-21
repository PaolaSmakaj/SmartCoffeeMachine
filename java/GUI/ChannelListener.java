package GUI;

import seiot.modulo_lab_2_2.msg.*;
import seiot.modulo_lab_2_2.msg.rxtx.SerialCommChannel;

public class ChannelListener extends Thread {

	CommChannel channel;
	View view;
	
	public ChannelListener (SerialCommChannel channel, View view) throws Exception {
		this.view = view;
		this.channel = channel;
	}
	
	public void run(){
		while (true){
			try {
				String msg = channel.receiveMsg();
				view.setInfo(msg);
			} catch (Exception ex){
				ex.printStackTrace();
			}
		}
	}

}