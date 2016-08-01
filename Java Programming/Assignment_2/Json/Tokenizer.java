
public class Tokenizer {
	private String text;
	private int position;
	
	public Tokenizer(String text) {
		this.text = text;
		position = 0;
	}
	
	public Token getNextToken() {
		StringBuilder stringToken = new StringBuilder("");
		boolean alphaOrDigit = false;
		Token token;
		char character;
		int type;
		
		if(!hasNextToken())
			return null;
		
		while(hasNextToken()&&(Character.isLetter(text.charAt(position)) || Character.isDigit(text.charAt(position)))){
			alphaOrDigit = true;
			stringToken.append(text.charAt(position));
			position++;
		}
		if(alphaOrDigit)
			 token = new Token(stringToken.toString(), 1);
		
		character = text.charAt(position);
		if(character == '{')
			type = 2;
		else if(character == '}')
			type = 3;
		else if(character == '[')
			type = 4;
		else if(character == ']')
			type = 5;
		else if(character == '\"')
			type = 6;
		else if(character == ':')
			type = 7;
		else if(character == ',')
			type = 8;
		else {
			character = "".charAt(0);
			type = -1;
		}
		token = new Token(String.valueOf(character), type);
		position++;
		return token;
	}
	
	public boolean hasNextToken() {
		if(position < text.length())
			return true;
		else
			return false;
	}
	public char getLookAhead() {
		return text.charAt(position);
	}
	
	public int getPosition(){
		return position;
	}
}