
public class Token {
	private String lexval;
	private int type;
	
	public Token(String lexval, int type) {
		this.lexval = lexval;
		this.type = type;
	}

	public String getLexval() {
		return lexval;
	}
	
	public int getType() {
		return type;
	}
}