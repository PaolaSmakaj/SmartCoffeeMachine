package GUI;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import seiot.modulo_lab_2_2.msg.rxtx.SerialCommChannel;

public class Controller implements ActionListener {
	
	SerialCommChannel channel;
	View view;
	
	public Controller(String port, View view) throws Exception {
		this.view = view;
		channel = new SerialCommChannel(port,9600);
		new ChannelListener(channel,view).start();		
	
	}
	
	public void actionPerformed(ActionEvent ev){
		  try {
			  if (ev.getActionCommand().equals("Refill coffee")){
					channel.sendMsg("5");
			  }
		  } catch (Exception ex){
			  ex.printStackTrace();
		  }
	 
	}
	
}