
import java.util.*;

public class JSONValue {
	String value;
	ArrayList<JSONValue> array;
	JSONObject ob;
	int type;
	
	public String toString() {
		if(type == 1)
			return value;
		else if(type == 3)
			return ob.toString();
		else
			return "null";
	}
}