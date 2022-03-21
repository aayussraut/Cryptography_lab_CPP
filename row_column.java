package Transposition;

public class RowTransposition {
	private static String cipherText = "";
	
	public static void rowTransposEncrypt(int[] key, String message) {
		int remainingNoletter = 0;
		char[][] matirxMessage = new char[key.length][key.length];
		int count = 0;
		int totalRow = 0;
		//checked the length of the message
		if(message.length() % key.length!=0) {
			remainingNoletter = key.length - message.length() % key.length;
			for(int i=0;i<remainingNoletter;i++) {
				message += "x";
			}
		}
		totalRow = message.length() / key.length;
		
		//converting to matrix according to the size of the key
		for(int i =0;i<key.length;i++)
		{
			for(int j=0;j<key.length;j++) {
				matirxMessage[i][j] = message.charAt(count);
				System.out.println("Matrix[" + i + "]" + "[" + j + "] = " +  matirxMessage[i][j]);
				count++;
			}
			if(count == message.length())
				break;
		}
		
		//finding the position of key
		int[] keyposition = new int[key.length];
		count = 0;
		for(int i = 1;i<=key.length;i++)
		{
			for(int j = 0;j<key.length;j++) {
				if(i == key[j])
				{
					keyposition[count] = j;
					break;
				}
					
			}
			System.out.println(keyposition[count]);
			count++;
		}
		
		// cipher text generation
		for(int i =0;i<keyposition.length;i++) {
			for(int j=0;j<totalRow;j++) {
				cipherText += matirxMessage[j][keyposition[i]];
			}
		}
		System.out.println("cipherText::" + cipherText.toUpperCase());
		System.out.println("cipherText::" + "TTNAAPTMTSUOAODWCOIXKNLYPETZ");
		
		
		
	}
	public static void main(String[] args) {
		int[] key = {4,3,1,2,5,6,7};
		rowTransposEncrypt(key, "attackpostponeduntiltwoam");
	}

}