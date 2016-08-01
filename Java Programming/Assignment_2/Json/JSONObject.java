
import java.util.*;
import java.util.Map.*;

public class JSONObject {
	private Map<String,JSONValue> keyValuePair;
	
	public JSONObject(Map<String,JSONValue> keyValuePair) {
		this.keyValuePair = keyValuePair;
	}

	public Map<String, JSONValue> getPair() {
		return keyValuePair;
	}

	public void setPair(Map<String, JSONValue> keyValuePair) {
		this.keyValuePair = keyValuePair;
	}
	
	public String toString() {
		String result = "{\n";
		Iterator<Map.Entry<String, JSONValue>> iter = keyValuePair.entrySet().iterator();
		while(iter.hasNext()){
			Entry<String, JSONValue> obj = iter.next(); 
			result = result+obj.getKey()+":"+obj.getValue().toString()+"\n";
		}
		return result+"}\n";
	}
}