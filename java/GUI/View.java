package GUI;

import java.awt.Dimension;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.*;

class View extends JFrame  {

	/**
	 * 
	 */
	private static final long serialVersionUID = 4878670195988389337L;

	private JButton refill;
	private JTextField info;
	
	public View(){
		super("View");
		setSize(400,140);
		
		JPanel mainPanel = new JPanel();
		mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.X_AXIS));

		mainPanel.add(Box.createRigidArea(new Dimension(20,0)));

		JPanel buttonPanel = new JPanel();
		buttonPanel.setLayout(new BoxLayout(buttonPanel, BoxLayout.Y_AXIS));	    
		refill = new JButton("Refill coffee");
		buttonPanel.add(refill);    
		mainPanel.add(buttonPanel);
		
		mainPanel.add(Box.createRigidArea(new Dimension(20,0)));
		
		JPanel outputPanel = new JPanel();
		outputPanel.setLayout(new BoxLayout(outputPanel, BoxLayout.Y_AXIS));	    

		JPanel infoLine = new JPanel();
		infoLine.setLayout(new BoxLayout(infoLine, BoxLayout.LINE_AXIS));
		info = new JTextField(60);
		info.setPreferredSize(new Dimension(200,15));
		info.setEditable(false);
		infoLine.add(info);
		outputPanel.add(infoLine);

		mainPanel.add(outputPanel);

		this.getContentPane().add(mainPanel);

		addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent ev){
				System.exit(-1);
			}
		});
	}

	public void registerController(Controller contr){
		refill.addActionListener(contr);
	}

	public void setInfo(String msg){
		SwingUtilities.invokeLater(() -> {
			info.setText(msg);
		});
	}


	
}