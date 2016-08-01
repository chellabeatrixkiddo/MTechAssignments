import java.util.*;
import java.io.*;

public class JSONParser {
	private ArrayList<JSONObject> listOfObjects;
	private Tokenizer tokenize;
	
	public JSONParser(String text) {
		listOfObjects = new ArrayList<JSONObject>();
		tokenize = new Tokenizer(text);
		if(tokenize.getNextToken().getType() == 2)
			listOfObjects.add(parseJSON());
	}
	
	public List<JSONObject> getObjectList() {
		return listOfObjects;
	}
	
	public JSONObject parseJSON() {
		Token token;
		JSONObject json = getJSONObject();
		token = tokenize.getNextToken();
		if(token == null || token.getType() != 3) {
			System.out.println("expected }");
			System.exit(1);
		}
		return json;
	}
	
	public JSONObject getJSONObject() {
		Map<String,JSONValue> jMap = new HashMap<String,JSONValue>();
		compute(jMap);
		return new JSONObject(jMap);
	}
	
	private void compute(Map<String, JSONValue> jMap) {
		Token k = tokenize.getNextToken();
		
		if(k == null || k.getType() != 6)
			System.out.println("Expected \""+" at "+tokenize.getPosition());
		
		k = tokenize.getNextToken();
		
		if(k == null || k.getType() != 1)
			System.out.println("Key expected");
		
		String key = k.getLexval();
		
		k = tokenize.getNextToken();
		
		if(k == null || k.getType() != 6)
			System.out.println("Expected \""+" at "+tokenize.getPosition());
		
		k = tokenize.getNextToken();
		
		if(k == null || k.getType() != 7)
			System.out.println("Expected :");
		
		k = tokenize.getNextToken();
		
		if(k == null)
			System.out.println("Unexpected EOF");
		else if(k.getType() == 6){
			
			k = tokenize.getNextToken();
			if(k == null || k.getType() != 1)
				System.out.println("Expected Value");
			
			JSONValue val = new JSONValue();
			val.value = k.getLexval();
			val.type = 1;
			jMap.put(key, val);
			
			k = tokenize.getNextToken();
			if(k == null || k.getType() != 6)
				System.out.println("Expected \""+" at "+tokenize.getPosition());
		} 
		else if(k.getType() == 2){
			JSONObject temp = parseJSON();
			JSONValue val = new JSONValue();
			val.ob = temp;
			val.type = 3;
			jMap.put(key,val);
		}
		if(tokenize.hasNextToken() && tokenize.getLookAhead() == ','){
			tokenize.getNextToken();
			compute(jMap);
		}
	}
	public static void main(String[] args) throws FileNotFoundException {
		try {
			File file = new File("JSONObject.txt");
			Scanner text = new Scanner(file).useDelimiter("\\z").next();
			JSONParser obj = new JSONParser(text);
			List<JSONObject> list = obj.getObjectList();
			for(JSONObject i:list)
				System.out.println(i);
		}
		catch(FileNotFoundException e) {
			throw new FileNotFoundException(e.toString());
		}
	}
}