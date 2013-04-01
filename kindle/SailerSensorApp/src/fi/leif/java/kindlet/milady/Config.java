package fi.leif.java.kindlet.milady;

import fi.leif.java.kindlet.milady.sensordisplay.CompassSensorDisplay;
import fi.leif.java.kindlet.milady.sensordisplay.HeadingSensorDisplay;
import fi.leif.java.kindlet.milady.sensordisplay.SensorDisplay;
import fi.leif.java.kindlet.milady.sensordisplay.SpeedSensorDisplay;

public class Config 
{
	public final SensorDisplay[][] SENSOR_DISPLAY_PAGES = new SensorDisplay[][]
	{
			// Page 1
			{
				new CompassSensorDisplay(this),
				new HeadingSensorDisplay(this),
				new SpeedSensorDisplay(this)
			}/*,
			
			// Page 2
			{
				new HeadingSensorDisplay(),
				new HeadingSensorDisplay(),
				new HeadingSensorDisplay()
			}*/
			
	};

	public final int MAX_PAGE_ROWS = 3;
	public final int PAGE_SHOW_MS = 3000;

	public final int TITLE_FONT_SIZE = 50;
	public final int DATA_FONT_SIZE = 210;
	public final String FONTFAMILY = null;
	
	public final int SOCKET_PORT = 9000;
	public final int SOCKET_SLEEP_ON_ERROR = 5000;
	
	public final String MSG_SEPARATOR = " ";
	public final int MSG_ID_LEN = 2;
	
	public Config() {}
}
